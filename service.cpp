#include "service.h"


Service::Service() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbname = "TheTestCabinet.sqlite";
    db.setDatabaseName(dbname);
    strcpy(filename, "database.txt");
}

Person Service::get(int id) {
    return personRepo.getPerson(id);
}
// add(): adds a person to the personRepo database.
void Service::add() {
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
void Service::headerPrint() {
    cout << fixed;
    cout << setw(3) << "Name: " << setw(15) << "Gender" << setw(15) << "Year of birth" << setw(15) << "Year of death" << endl;
    cout << "----------------------------------------------------------------" << endl;
}
void Service::printAll() {
    headerPrint();
    for(int i = 0; i < personRepo.getPersonSize(); i++) {
        personRepo.getPerson(i).print();
    }
}
void Service::printAllWithNumber() {
    for(int i = 0; i < personRepo.getPersonSize(); i++) {
        cout << "Person number: " << i+1 << endl;
        personRepo.getPerson(i).print();
    }
}
void Service::printOne(int id) {
    personRepo.getPerson(id).print();
}
void Service::searchAll(int theCase, string search) {
    int* ids = new int[personRepo.getPersonSize()];
    bool personFound = false;
    switch(theCase) {
        case 1: {
            ids = searcher.nameFirst(personRepo.getAllPerson(),search);
            break;
        }
        case 2: {
            ids = searcher.nameLast(personRepo.getAllPerson(),search);
            break;
        }
        case 3: {
            ids = searcher.gender(personRepo.getAllPerson(),search);
            break;
        }
        case 4: {
            ids = searcher.birthYear(personRepo.getAllPerson(),search);
            break;
        }
        case 5: {
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
void Service::removeFromVector(int id) {
    personRepo.removePerson(id);
}
// sortAll: calls the correct sorting case and prints the results.
void Service::sortAll(int theCase) {
    vector<Person> sortedTemp = sorter.sortVector(personRepo.getAllPerson(), theCase);
    for(unsigned int i = 0; i < sortedTemp.size(); i++) {
        sortedTemp[i].print();
    }
}
// clearAndPrintFile(): deletes the original file and makes a new one
// with all the persons from the personRepo database.
void Service::clearAndPrintFile() {
    remove(filename);
    ofstream outFile(filename);
    if(outFile.is_open()) {
        for(int i = 0; i < personRepo.getPersonSize(); i++) {
            outFile << personRepo.getPerson(i);
        }
    }
    outFile.close();
}
int Service::sizeOfDatabase() {
    return personRepo.getPersonSize();
}
// setUp(): reads in information from a database and places it into
// the vector in the repository.
void Service::setUp() {
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
bool Service::UIinputCheck(int input, int maxcases) {
    if(cin.fail())
    {
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
// Saves a person to the database
void Service::savePersonToDatabase(Person p) {
    QSqlQuery query;
    if(db.open()) {
        qDebug() << "Opened!";
        string col = "(Name, Gender, 'Birth year', 'Death year')";
        string name = "('" + p.getFirstName() + " " + p.getLastName() + "'";
        string value = ",'" + p.getGender() + "','" + p.getYearOfBirth() + "','" + p.getYearOfDeath() + "')";
        string command = "INSERT INTO Person " + col + "VALUES " + name + value;
        cout << command << endl;
        QString qcommand = QString::fromUtf8(command.c_str());
        query.exec(qcommand);
        db.close();
    } else {
        qDebug() << "Error = " << db.lastError().text();
    }
}
