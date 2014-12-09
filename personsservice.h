// Service: Takes commands from the user interface, seeks information from the repository
// and relays the appropriate information back to the user interface.

#ifndef PERSONSSERVICE_H
#define PERSONSSERVICE_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstring>
#include <QString>
#include "person.h"
#include "search.h"
#include "PersonsRepository.h"
#include "ComputerRepository.h"

class PersonsService
{
public:
    PersonsService();
    Person get(int id);
    void add();
    void setUp();
    void printAll();
    void printAllWithNumber();
    int sizeOfDatabase();
    void savePersonToDatabase(Person p);
    QSqlDatabase getDatabaseConnection();
    vector<Person> getAll();
    int getSizeOfRepo();
    string getPersonID();
private:
    PersonsRepository personRepo;
    QSqlDatabase db;
};

#endif // PERSONSSERVICE_H
