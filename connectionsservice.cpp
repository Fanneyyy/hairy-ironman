#include "connectionsservice.h"

ConnectionsService::ConnectionsService() {
}

// add: adds a connection between a person and a computer to the database
void ConnectionsService::add(vector<Person> personList, vector<Computer>computerList) {
    Connection connection = Connection();
    int inputPerson;
    int inputComputer;
    char input;
    char c;

    do {
        cout << "Number of person to connect: " << endl;

        do {
        cin >> inputPerson;
        } while(!inputCheck(inputPerson, personList.size()));
        connection.setPersonID(personList[inputPerson-1].getID());

        cout << "Number of computer to connect with that person: " << endl;

        do {
        cin >> inputComputer;
        } while(!inputCheck(inputComputer, computerList.size()));
        connection.setComputerID(computerList[inputComputer-1].getID());

        cout << "Do you wish to make a connection between " << personList[inputPerson-1].getFirstName() << endl;
        cout << "and the computer " << computerList[inputComputer-1].getComputerName() << " y/n?" << endl;
        cin >> input;

        if(input == 'y' || input == 'Y') {
            connectionRepo.add(connection);
            saveConnectionToDatabase(connection);
        }

        cout << "Want to add another? (y/n?) ";
        cin >> c;
    } while(c != 'N' && c != 'n');
}

// printAllPerson: prints a list of persons with the appropriate connected computers
void ConnectionsService::printAllPerson(vector<Person> personList, vector<Computer>computerList, int size) {
    int computerIDtemp;
    string name;

    for(int i = 0; i < size; i++) {
        cout << personList[i];
        for(int j = 0; j < connectionRepo.getConnectionSize(); j++) {
            if(personList[i].getID() == (connectionRepo.getConnection(j).getPersonID())) {
                computerIDtemp = connectionRepo.getConnection(j).getComputerID();
                for(unsigned int i = 0; i < computerList.size(); i++) {
                    if(computerIDtemp == computerList[i].getID()) {
                        name = computerList[i].getComputerName();
                    }
                }
                cout << setw(3) << " " << name << endl;
            }
        }
    }
}

// printAllComputer: prints a list of computers with the appropriate connected persons
void ConnectionsService::printAllComputer(vector<Computer>computerList, vector<Person> personList, int size) {
    int personIDtemp;
    string nameFirst;
    string nameLast;

    for(int i = 0; i < size; i++) {
        cout << computerList[i];
        for(int j = 0; j < connectionRepo.getConnectionSize(); j++) {
            if(computerList[i].getID() == (connectionRepo.getConnection(j).getComputerID())) {
                personIDtemp = connectionRepo.getConnection(j).getPersonID();
                for(unsigned int i = 0; i < personList.size(); i++) {
                    if(personIDtemp == personList[i].getID()) {
                        nameFirst = personList[i].getFirstName();
                        nameLast = personList[i].getLastName();
                    }
                }
                cout << setw(3) << " " << nameFirst + " " + nameLast << endl;
            }
        }
    }
}

vector<Connection> ConnectionsService::getAll() {
    return connectionRepo.getAllConnections();
}

int ConnectionsService::getSizeOfRepo() {
    return connectionRepo.getConnectionSize();
}

// getDatabaseConnection(): checks if a connection has already been made
// and connects to it if it has but otherwise makes a new connection
QSqlDatabase ConnectionsService::getDatabaseConnection() {
    QString connectionName = "ConnectionsConnection";
    QSqlDatabase db;

    if(QSqlDatabase::contains(connectionName)) {
        db = QSqlDatabase::database(connectionName);
    }
    else {
        db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
        db.setDatabaseName("TheTestCabinet.sqlite");
        db.open();
    }
    return db;
}

// setUp(): reads in information from a database and places it into
// the vector in the repository.
void ConnectionsService::setUp() {
    db = getDatabaseConnection();
    string personID;
    string computerID;
    Connection c = Connection();

    QSqlQuery query(QSqlDatabase::database("ConnectionsConnection"));

    query.exec("SELECT * FROM Contributers");

    while(query.next()) {
        personID = query.value("p_ID").toString().toStdString();
        computerID = query.value("c_ID").toString().toStdString();
        c.setPersonID(atoi(personID.c_str()));
        c.setComputerID(atoi(computerID.c_str()));
        connectionRepo.add(c);
    }
    db.close();
}

// Saves a person to the database
void ConnectionsService::saveConnectionToDatabase(Connection c) {
    string personID;
    string computerID;

    db = getDatabaseConnection();

    if(db.open()) {
        QSqlQuery query(QSqlDatabase::database("ConnectionsConnection"));

        personID = static_cast<ostringstream*>( &(ostringstream() << c.getPersonID()) )->str();
        computerID = static_cast<ostringstream*>( &(ostringstream() << c.getComputerID()) )->str();
        string col = "(c_ID, p_ID)";
        string value = "('" + computerID + "','" + personID + "')";
        string command = "INSERT INTO Contributers " + col + "VALUES " + value;
        QString qcommand = QString::fromUtf8(command.c_str());

        if(query.exec(qcommand)) {
            cout << "The connection has been added to the database." << endl;
        } else {
            qDebug() << "Error = " << db.lastError().text();
        }
    } else {
        qDebug() << "Error = " << db.lastError().text();
    }
    db.close();
}

// inputCheck(input, max): checks if the input is between 0 and max
bool ConnectionsService::inputCheck(int input, int max) {
    if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        input = -1;
    }

    if(input <= 0 || input > max) {
        cout << "Wrong input, please try again" << endl;
        return false;
    }
    return true;
}
