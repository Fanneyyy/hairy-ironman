#include "personsservice.h"

PersonsService::PersonsService() {
}

// get: returns the person with the id within the vector
// (not necessarily the same as the database id)
Person PersonsService::get(int id) {
    return personRepo.getPerson(id);
}

vector<Person> PersonsService::getAll() {
    return personRepo.getAllPerson();
}

int PersonsService::getSizeOfRepo() {
    return personRepo.getPersonSize();
}

// add(): adds a person to the personRepo database and to the sqlite database.
void PersonsService::add(Person p) {

        personRepo.add(p);
        savePersonToDatabase(p);
}

void PersonsService::printAll() {
    for(int i = 0; i < personRepo.getPersonSize(); i++) {
        cout << personRepo.getPerson(i);
    }
}

void PersonsService::printAllWithNumber() {
    for(int i = 0; i < personRepo.getPersonSize(); i++) {
        cout << left << setw(3) << i+1;
        cout << personRepo.getPerson(i);
    }
}

// getPersonID(): returns the ID of the person from the database
string PersonsService::getPersonID() {
    db = getDatabaseConnection();
    Person p = Person();
    string ID;
    QSqlQuery query(QSqlDatabase::database("PersonConnection"));

    query.exec("SELECT last_insert_rowid() FROM Person");
    while(query.next()) {

       ID = query.value("ID").toString().toStdString();
    }
    db.close();
    return ID;
}

// getDatabaseConnection(): checks if a connection has already been made
// and connects to it if it has but otherwise makes a new connection
QSqlDatabase PersonsService::getDatabaseConnection() {
    QString connectionName = "PersonConnection";
    QSqlDatabase db;

    if(QSqlDatabase::contains(connectionName)) {
        db = QSqlDatabase::database(connectionName);
    } else {
        db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
        db.setDatabaseName("TheTestCabinet.sqlite");
        db.open();
    }
    return db;
}

// setUp(): reads in information from a database and places it into
// the vector in the repository.
void PersonsService::setUp() {
    db = getDatabaseConnection();
    Person p = Person();

    QSqlQuery query(QSqlDatabase::database("PersonConnection"));

    query.exec("SELECT * FROM Person");

    while(query.next()) {
        p.setID(query.value("ID").toString().toStdString());
        p.setName(query.value("Name").toString().toStdString());
        p.setGender(query.value("Gender").toString().toStdString());
        p.setYearOfBirth(query.value("Birth year").toString().toStdString());
        p.setYearOfDeath(query.value("Death year").toString().toStdString());
        personRepo.add(p);
    }
    db.close();
}

// Saves a person to the database
void PersonsService::savePersonToDatabase(Person p) {
    db = getDatabaseConnection();

    if(db.open()) {
        QSqlQuery query(QSqlDatabase::database("PersonConnection"));

        string col = "(Name, Gender, 'Birth year', 'Death year')";
        string name = "('" + p.getName() + "'";
        string value = ",'" + p.getGender() + "','" + p.getYearOfBirth() + "','" + p.getYearOfDeath() + "')";
        string command = "INSERT INTO Person " + col + "VALUES " + name + value;
        QString qcommand = QString::fromUtf8(command.c_str());

        if(query.exec(qcommand)) {
            cout << "The person has been added to the database." << endl;
        } else {
            qDebug() << "Error = " << db.lastError().text();
        }
    } else {
        qDebug() << "Error = " << db.lastError().text();
    }
    db.close();
}
