// Service: Takes commands from the user interface, seeks information from the repository
// and relays the appropriate information back to the user interface.

#ifndef COMPUTERSSERVICE_H
#define COMPUTERSSERVICE_H

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

class ComputersService
{
public:
    ComputersService();
    Computer get(int id);
    void add();
    void setUp();
    void printAll();
    void printOne(int id);
    void printAllWithNumber();
    void removeFromVector(int id);
    void sortAll(int theCase);
    string getFileName();
    bool UIinputCheck(int input, int maxcases);
    int sizeOfDatabase();
    void headerPrint();
    void saveComputerToDatabase(Computer c);
    QSqlDatabase getDatabaseConnection();
    vector<Computer> getAll();
    int getSizeOfRepo();
private:
    Search searcher;
    Sort sorter;
    ComputerRepository computerRepo;
    QSqlDatabase db;
};

#endif // COMPUTERSSERVICE_H
