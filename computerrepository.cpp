#include "computerrepository.h"

ComputerRepository::ComputerRepository() {
    computerList = vector<Computer>();
}

// getAll(): returns the complete vector computerList
vector<Computer> ComputerRepository::getAllComputer() {
    return computerList;
}

// add(Computer c): adds the Computer c to the vector computerList.
void ComputerRepository::add(Computer c){
    computerList.push_back(c);
}

void ComputerRepository::remove(int id){
    computerList.erase(computerList.begin()+id);
}

// adds to the vector and to the database.
void ComputerRepository::addComputerToVectorAndDatabase(Computer c) {
    saveComputerToDatabase(c);
    c.setID(getComputerID());
    computerList.push_back(c);
}

// get(int id): returns the Computer with the appropriate id.
Computer ComputerRepository::getComputer(int id){
    return computerList[id];
}

// getSize(): returns the size of the vector computerList.
int ComputerRepository::getComputerSize() {
    return computerList.size();
}

// clears out the vector repository
void ComputerRepository::emptyRepo() {
    computerList = vector<Computer>();
}

// getComputerID(): returns the ID of the computer from the database
string ComputerRepository::getComputerID() {
    db = getDatabaseConnection();
    string IDtemp;
    QSqlQuery query(QSqlDatabase::database("ComputerConnection"));

    query.exec("SELECT * FROM Computer");
    while(query.next()) {
       IDtemp = query.value("ID").toString().toStdString();
    }
    db.close();
    return IDtemp;
}

// getDatabaseConnection(): checks if a connection has already been made
// and connects to it if it has but otherwise makes a new connection
QSqlDatabase ComputerRepository::getDatabaseConnection() {
    QString connectionName = "ComputerConnection";
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
void ComputerRepository::setUp() {
    db = getDatabaseConnection();
    Computer c = Computer();
    QSqlQuery query(QSqlDatabase::database("ComputerConnection"));

    query.exec("SELECT * FROM Computer");

    while(query.next()) {
        c.setID(query.value("ID").toString().toStdString());
        c.setComputerName(query.value("Name").toString().toStdString());
        c.setType(query.value("Type").toString().toStdString());
        c.setBuildYear(query.value("Build year").toString().toStdString());
        c.setBuiltRnot(query.value("Built?").toString().toStdString());
        add(c);
    }
    db.close();
}

// Saves a computer to the database
void ComputerRepository::saveComputerToDatabase(Computer c) {
    db = getDatabaseConnection();

    if(db.open()) {
        QSqlQuery query(QSqlDatabase::database("ComputerConnection"));
        string col = "(Name, Type, 'Build year', 'Built?')";
        string name = "('" + c.getComputerName() + "'";
        string value = ",'" + c.getType() + "','" + c.getBuildYear() + "','" + c.getBuiltRnot() + "')";
        string command = "INSERT INTO Computer " + col + "VALUES " + name + value;
        QString qcommand = QString::fromUtf8(command.c_str());

        if(query.exec(qcommand)) {
            qDebug() << "The computer has been added to the database." << endl;
        } else {
            qDebug() << "Error = " << db.lastError().text();
        }
    } else {
        qDebug() << "Error = " << db.lastError().text();
    }
    db.close();
}

void ComputerRepository::removeFromDatabase(string ID) {
    db = getDatabaseConnection();

    if(db.open()) {
        QSqlQuery query(QSqlDatabase::database("ComputerConnection"));

        query.prepare("DELETE FROM Computer WHERE ID = :ID");
        query.bindValue(":ID", atoi(ID.c_str()));

        query.exec();

        query.prepare("DELETE FROM Contributers WHERE p_ID = :ID");
        query.bindValue(":ID", atoi(ID.c_str()));

        if(query.exec()) {
            qDebug() << "The person has been added to the database." << endl;
        } else {
            qDebug() << "Error = " << db.lastError().text();
        }
    } else {
        qDebug() << "Error = " << db.lastError().text();
    }
    db.close();
}
