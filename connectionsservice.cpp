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
        cout << "Number of person to connect: ";

        do {
        cin >> inputPerson;
        } while(!inputCheck(inputPerson, personList.size()));

        //númer persónunar í listanum
        connection.setPersonID(personList[inputPerson-1].getID());

        cout << "Number of computer to connect with that person: ";

        do {
        cin >> inputComputer;
        } while(!inputCheck(inputComputer, computerList.size()));
        //númer tölvunar í listanum
        connection.setComputerID(computerList[inputComputer-1].getID());

        cout << "\nDo you wish to make a connection between " << personList[inputPerson-1].getName() << endl;
        cout << "and the computer " << computerList[inputComputer-1].getComputerName() << " (y/n?) ";
        cin >> input;

        if(input == 'y' || input == 'Y') {
            connectionRepo.add(connection);
            saveConnectionToDatabase(connection);
        }

        cout << "\nWant to add another? (y/n?) ";
        cin >> c;
    } while(c != 'N' && c != 'n');
}

// printAllPerson: prints a list of persons with the appropriate connected computers
vector<Computer> ConnectionsService::printAllPerson(int ID, vector<Computer>computerList) {
    vector<Computer> findings;
    int computerIDtemp;
    for(int j = 0; j < connectionRepo.getConnectionSize(); j++) {
        if(ID == (connectionRepo.getConnection(j).getPersonID())) {
            computerIDtemp = connectionRepo.getConnection(j).getComputerID();
            for(unsigned int i = 0; i < computerList.size(); i++) {
                if(computerIDtemp == computerList[i].getID()) {
                    findings.push_back(computerList[i]);
                }
            }
        }
    }
    return findings;
}

//void ConnectionsService::listConnections(string personName, vector<Computer>computerList, int size) {
//    string name;

//    cout << personName << " is connected to ";
//    for(int i = 0; i < size; i++) {
//        if(personName == per)
//    }
//}

// printAllComputer: prints a list of computers with the appropriate connected persons
/*void ConnectionsService::printAllComputer(vector<Computer>computerList, vector<Person> personList, int size) {
    int personIDtemp;
    string name;

    for(int i = 0; i < size; i++) {
        cout << computerList[i];
        for(int j = 0; j < connectionRepo.getConnectionSize(); j++) {
            if(computerList[i].getID() == (connectionRepo.getConnection(j).getComputerID())) {
                personIDtemp = connectionRepo.getConnection(j).getPersonID();
                for(unsigned int i = 0; i < personList.size(); i++) {
                    if(personIDtemp == personList[i].getID()) {
                        name = personList[i].getName();
                    }
                }
                cout << setw(3) << " " << name << endl;
            }
        }
    }
}
*/
vector<Person> ConnectionsService::printAllComputer(int ID, vector<Person> personList) {
    vector<Person> findings;
    int personIDtemp;
    for(int j = 0; j < connectionRepo.getConnectionSize(); j++) {
        if(ID == (connectionRepo.getConnection(j).getComputerID())) {
            personIDtemp = connectionRepo.getConnection(j).getPersonID();
            for(unsigned int i = 0; i < personList.size(); i++) {
                if(personIDtemp == personList[i].getID()) {
                    findings.push_back(personList[i]);
                }
            }
        }
    }
    return findings;
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

        query.exec("PRAGMA foreign_keys ON");

        personID = static_cast<ostringstream*>( &(ostringstream() << c.getPersonID()) )->str();
        computerID = static_cast<ostringstream*>( &(ostringstream() << c.getComputerID()) )->str();
        string col = "(c_ID, p_ID)";
        string value = "('" + computerID + "','" + personID + "')";
        string command = "INSERT INTO Contributers " + col + "VALUES " + value;
        QString qcommand = QString::fromUtf8(command.c_str());

        if(query.exec(qcommand)) {
            cout << "The connection has been added to the database." << endl;
        } else {
            cout << "Sorry, unable to make that connection" << endl;
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

//vector<Computer> ConnectionsService::findConnections(int ID, vector<Computer> computerList) {
//    vector<Computer> findings;
//    int computerIDtemp;
//    for(int i = 0; i < getSizeOfRepo(); i++) {
//        if(ID == connectionRepo.getConnection(i).getComputerID()) {

//            for(int i = 0; i < computerList; i++) {
//                if()
//                findings.push_back();
//            }
//        }
//    }

//}
