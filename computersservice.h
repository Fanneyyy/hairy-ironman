// Service: Takes commands from the user interface, seeks information from the repository
// and relays the appropriate information back to the user interface.

#ifndef COMPUTERSSERVICE_H
#define COMPUTERSSERVICE_H

#include <string>
#include <vector>
#include <limits>
#include <cstring>
#include <QString>
#include "computerrepository.h"

class ComputersService
{
public:
    ComputersService();
    Computer get(int id);
    void add();
    void setUp();
    void printAll();
    void printAllWithNumber();
    bool UIinputCheck(int input, int maxcases);
    int sizeOfDatabase();
    void saveComputerToDatabase(Computer c);
    QSqlDatabase getDatabaseConnection();
    vector<Computer> getAll();
    int getSizeOfRepo();
private:
    ComputerRepository computerRepo;
    QSqlDatabase db;
};

#endif // COMPUTERSSERVICE_H
