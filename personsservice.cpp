#include "personsservice.h"

PersonsService::PersonsService() {
}

Person PersonsService::get(int id) {
    return personRepo.getPerson(id);
}

vector<Person> PersonsService::getAll() {
    return personRepo.getAllPerson();
}

int PersonsService::getSizeOfRepo() {
    return personRepo.getPersonSize();
}

// add(): adds a person to the personRepo database and to sqlite databasinn.
void PersonsService::add() {
    Person p = Person();
    char c;
    do {
        cin >> p;
        personRepo.add(p);
        savePersonToDatabase(p);
        cout << "Want to add another? (y/n?) ";
        cin >> c;
    } while(c != 'N' && c != 'n');
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

void PersonsService::printOne(int id) {
    cout << personRepo.getPerson(id);
}

// removeFromVector(int id): removes the person with the appropriate
// id from the personRepo database.
void PersonsService::removeFromVector(int id) {
    personRepo.removePerson(id);
}

int PersonsService::sizeOfDatabase() {
    return personRepo.getPersonSize();
}

QSqlDatabase PersonsService::getDatabaseConnection() {
    QString connectionName = "PersonConnection";
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
void PersonsService::setUp() {
    db = getDatabaseConnection();
    QSqlQuery query(QSqlDatabase::database("PersonConnection"));
    Person p = Person();

    query.exec("SELECT * FROM Person");

    while(query.next()) {
        p.setFirstName(query.value("Name").toString().toStdString());
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
        string name = "('" + p.getFirstName() + " " + p.getLastName() + "'";
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
