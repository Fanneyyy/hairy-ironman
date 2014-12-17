#include "personsrepository.h"

PersonsRepository::PersonsRepository() {
    personList = vector<Person>();
}

// getAll(): returns the complete vector personList
vector<Person> PersonsRepository::getAllPerson() {
    return personList;
}

// add(Person a): adds the Person a to the vector personList.
void PersonsRepository::add(Person p){
    personList.push_back(p);
}

void PersonsRepository::remove(int id){
    personList.erase(personList.begin()+id);
}

// adds to the vector and to the database.
void PersonsRepository::addPersonToVectorAndDatabase(Person p) {
    savePersonToDatabase(p);
    p.setID(getPersonID());
    personList.push_back(p);
}

// get(int id): returns the Person with the appropriate id.
Person PersonsRepository::getPerson(int id){
    return personList[id];
}

// getSize(): returns the size of the vector personList.
int PersonsRepository::getPersonSize() {
    return personList.size();
}

// clears out the vector repository
void PersonsRepository::emptyRepo() {
    personList = vector<Person>();
}

// getPersonID(): returns the ID of the person from the database
string PersonsRepository::getPersonID() {
    db = getDatabaseConnection();
    string IDtemp;
    QSqlQuery query(QSqlDatabase::database("PersonConnection"));

    query.exec("SELECT * FROM Person");
    while(query.next()) {
       IDtemp = query.value("ID").toString().toStdString();
    }
    db.close();
    return IDtemp;
}

// getDatabaseConnection(): checks if a connection has already been made
// and connects to it if it has but otherwise makes a new connection
QSqlDatabase PersonsRepository::getDatabaseConnection() {
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
void PersonsRepository::setUp() {
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
        add(p);
    }
    db.close();
}

// Saves a person to the database
void PersonsRepository::savePersonToDatabase(Person p) {
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

// removes a person from the sqlite database
void PersonsRepository::removeFromDatabase(string ID) {
    db = getDatabaseConnection();

    if(db.open()) {
        QSqlQuery query(QSqlDatabase::database("PersonConnection"));

        query.prepare("DELETE FROM Person WHERE ID = :ID");
        query.bindValue(":ID", atoi(ID.c_str()));

        query.exec();

        query.prepare("DELETE FROM Contributers WHERE p_ID = :ID");
        query.bindValue(":ID", atoi(ID.c_str()));

        if(query.exec()) {
            cout << "The person has been removed from the database." << endl;
        } else {
            qDebug() << "Error = " << db.lastError().text();
        }
    } else {
        qDebug() << "Error = " << db.lastError().text();
    }
    db.close();
}
