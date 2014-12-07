#include "personsservice.h"

PersonsService::PersonsService() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbname = "TheTestCabinet.sqlite";
    db.setDatabaseName(dbname);
}

Person PersonsService::get(int id) {
    return personRepo.getPerson(id);
}

// add(): adds a person to the personRepo database.
void PersonsService::add() {
    Person p;
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
        personRepo.getPerson(i).print();
    }
}

void PersonsService::printAllWithNumber() {
    for(int i = 0; i < personRepo.getPersonSize(); i++) {
        cout << "Person number: " << i+1 << endl;
        personRepo.getPerson(i).print();
    }
}

void PersonsService::printOne(int id) {
    personRepo.getPerson(id).print();
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
            personRepo.getPerson(i).print();
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
        sortedTemp[i].print();
    }
}

// setUp(): reads in information from a database and places it into
// the vector in the repository.
void PersonsService::setUp() {
    if(db.open()) {
        qDebug() << "Opened!";
        QSqlQuery query;
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
    } else {
        qDebug() << "Error = " << db.lastError().text();
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

// Saves a person to the database
void PersonsService::savePersonToDatabase(Person p) {
    if(db.open()) {
        QSqlQuery query;
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
        db.close();
    } else {
        qDebug() << "Error = " << db.lastError().text();
    }
}