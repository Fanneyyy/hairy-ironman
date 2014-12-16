#include "connectionsrepository.h"

ConnectionsRepository::ConnectionsRepository() {
}

// add: adds a connection to the database
void ConnectionsRepository::add(Connection c){
    connectionList.push_back(c);
}

void ConnectionsRepository::remove(int id){
    connectionList.erase(connectionList.begin()+id);
}

void ConnectionsRepository::emptyRepo() {
    connectionList = vector<Connection>();
}

// adds to the vector and to the database.
void ConnectionsRepository::addConnectionToVectorAndDatabase(Connection c) {
    saveConnectionToDatabase(c);
    connectionList.push_back(c);
}

// getAll: returns all connections in a vector
vector<Connection> ConnectionsRepository::getAllConnections(){
    return connectionList;
}

// getConnection: returns the connection with that id in the vector
// (possibly but not necessarily the same as in the database)
Connection ConnectionsRepository::getConnection(int id){
    return connectionList[id];
}

//returns the number of connection in the repository
int ConnectionsRepository::getConnectionSize() {
    return connectionList.size();
}


// getDatabaseConnection(): checks if a connection has already been made
// and connects to it if it has but otherwise makes a new connection
QSqlDatabase ConnectionsRepository::getDatabaseConnection() {
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
void ConnectionsRepository::setUp() {
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
        add(c);
    }
    db.close();
}

// Saves a person to the database
void ConnectionsRepository::saveConnectionToDatabase(Connection c) {
    QString personID;
    QString computerID;

    db = getDatabaseConnection();

    if(db.open()) {
        QSqlQuery query(QSqlDatabase::database("ConnectionsConnection"));

        query.exec("PRAGMA foreign_keys ON");

        personID = QString::number(c.getPersonID());
        computerID = QString::number(c.getComputerID());
        QString col = "(c_ID, p_ID)";
        QString value = "('" + computerID + "','" + personID + "')";
        QString qcommand = "INSERT INTO Contributers " + col + "VALUES " + value;

        if(query.exec(qcommand)) {
            qDebug() << "The connection has been added to the database." << endl;
        } else {
            qDebug() << "Sorry, unable to make that connection" << endl;
        }
    } else {
        qDebug() << "Error = " << db.lastError().text();
    }
    db.close();
}
