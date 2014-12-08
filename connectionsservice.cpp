#include "connectionsservice.h"

ConnectionsService::ConnectionsService() {
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
        string col = "(p_ID, c_ID)";
        string value = "('" + personID + "','" + computerID + "')";
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
