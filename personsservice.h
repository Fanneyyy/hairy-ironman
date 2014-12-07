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
#include "sort.h"

class PersonsService
{
public:
    PersonsService();
    Person get(int id);
    void add();
    void setUp();
    void printAll();
    void printOne(int id);
    void searchAll(int theCase, string name);
    void printAllWithNumber();
    void removeFromVector(int id);
    void sortAll(int theCase);
    string getFileName();
    bool UIinputCheck(int input, int maxcases);
    int sizeOfDatabase();
    void headerPrint();
    void savePersonToDatabase(Person p);
    QSqlDatabase getDatabaseConnection();
private:
    Search searcher;
    Sort sorter;
    PersonsRepository personRepo;
    QSqlDatabase db;
};

#endif // PERSONSSERVICE_H
