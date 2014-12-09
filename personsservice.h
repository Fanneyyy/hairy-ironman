// Service: Takes commands from the user interface, seeks information from the repository
// and relays the appropriate information back to the user interface.

#ifndef PERSONSSERVICE_H
#define PERSONSSERVICE_H

#include <string>
#include <vector>
#include <limits>
#include <cstring>
#include <QString>
#include <QtSql>
#include <QtDebug>
#include "PersonsRepository.h"

class PersonsService {
public:
    PersonsService();
    Person get(int id);
    void add();
    void setUp();
    void printAll();
    void printAllWithNumber();
    int getSizeOfRepo();
    string getPersonID();
    void savePersonToDatabase(Person p);
    QSqlDatabase getDatabaseConnection();
    vector<Person> getAll();
private:
    PersonsRepository personRepo;
    QSqlDatabase db;
};

#endif // PERSONSSERVICE_H
