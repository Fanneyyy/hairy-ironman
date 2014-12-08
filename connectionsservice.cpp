#include "connectionsservice.h"

ConnectionsService::ConnectionsService() {
}

void ConnectionsService::add(int sizeOfPersons, int sizeOfComputers) {
    Connection connection = Connection();
    int input;
    char c;
    do {
        cout << "Number of person to connect: " << endl;
        do {
        cin >> input;
        } while(!inputCheck(input, sizeOfPersons));
        connection.setPersonID(input);
        cout << "Number of computer to connect with that person: " << endl;
        do {
        cin >> input;
        } while(!inputCheck(input, sizeOfComputers));
        connection.setComputerID(input);

        connectionRepo.add(connection);
        saveConnectionToDatabase(connection);
        cout << "Want to add another? (y/n?) ";
        cin >> c;
    } while(c != 'N' && c != 'n');
}

void ConnectionsService::printAllPerson(vector<Person> personList, vector<Computer>computerList, int size) {
    for(int i = 0; i < size; i++) {
        cout << personList[i];
        for(int j = 0; j < connectionRepo.getConnectionSize(); j++) {
            if(i == (connectionRepo.getConnection(j).getPersonID()-1)) {
                cout << setw(3) << " " << computerList[connectionRepo.getConnection(j).getComputerID()-1].getComputerName() << endl;
            }
        }
    }
}

void ConnectionsService::printAllComputer(vector<Computer>computerList, vector<Person> personList, int size) {
    for(int i = 0; i < size; i++) {
        cout << computerList[i];
        for(int j = 0; j < connectionRepo.getConnectionSize(); j++) {
            if(i == (connectionRepo.getConnection(j).getComputerID()-1)) {
                cout << setw(3) << " " << personList[connectionRepo.getConnection(j).getPersonID()-1].getFullName() << endl;
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
    QSqlQuery query(QSqlDatabase::database("ConnectionsConnection"));
    Connection c = Connection();

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
