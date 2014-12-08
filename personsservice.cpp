#include "personsservice.h"

PersonsService::PersonsService() {
}

Person PersonsService::get(int id) {
    return personRepo.getPerson(id);
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
    personRepo.headerPersonsPrint();
    for(int i = 0; i < personRepo.getPersonSize(); i++) {
        cout << personRepo.getPerson(i);
    }
}

void PersonsService::printAllWithNumber() {
    for(int i = 0; i < personRepo.getPersonSize(); i++) {
        cout << "Person number: " << i+1 << endl;
        cout << personRepo.getPerson(i);
    }
}

void PersonsService::printOne(int id) {
    cout << personRepo.getPerson(id);
}

void PersonsService::searchAll(int theCase, string search) {
    int* ids = new int[personRepo.getPersonSize()];
    bool personFound = false;
    switch(theCase) {
        case 1: {
            ids = searcher.personName(personRepo.getAllPerson(),search);
            break;
        }
        case 2: {
            ids = searcher.gender(personRepo.getAllPerson(),search);
            break;
        }
        case 3: {
            ids = searcher.birthYear(personRepo.getAllPerson(),search);
            break;
        }
        case 4: {
            ids = searcher.deathYear(personRepo.getAllPerson(),search);
            break;
        }
        default:
            break;
    }
    for(int i = 0; i < personRepo.getPersonSize(); i++) {
        if(ids[i] == 1) {
            cout << personRepo.getPerson(i);
            personFound = true;
        }
    }
    if(!personFound) {
        cout << "Sorry, nothing match your search" << endl;
    }
    delete [] ids;
}

// removeFromVector(int id): removes the person with the appropriate
// id from the personRepo database.
void PersonsService::removeFromVector(int id) {
    personRepo.removePerson(id);
}

// sortAll: calls the correct sorting case and prints the results.
void PersonsService::sortAll(int theCase) {
    vector<Person> sortedTemp = sorter.sortVector(personRepo.getAllPerson(), theCase);
    for(unsigned int i = 0; i < sortedTemp.size(); i++) {
        cout << sortedTemp[i];
    }
}

// UIinputCheck: validates the input for UI choices.
bool PersonsService::UIinputCheck(int input, int maxcases) {
    if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        input = -1;
    }

    if(input < 0 || input > maxcases) {
        cout << "Wrong input, please try again" << endl;
        return false;
    }
    return true;
}

int PersonsService::sizeOfDatabase() {
    return personRepo.getPersonSize();
}

QSqlDatabase PersonsService::getDatabaseConnection() {
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
        QSqlQuery query(QSqlDatabase::database("ComputerConnection"));
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
