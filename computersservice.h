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
#include "printui.h"

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
    string getFileName();
    bool UIinputCheck(int input, int maxcases);
    int sizeOfDatabase();
    void headerPrint();
    void saveComputerToDatabase(Computer c);
    QSqlDatabase getDatabaseConnection();
    vector<Computer> getAll();
    int getSizeOfRepo();
private:
    ComputerRepository computerRepo;
    QSqlDatabase db;
    PrintUI print;
};

#endif // COMPUTERSSERVICE_H
