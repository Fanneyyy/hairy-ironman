#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H

#include <vector>
#include "Person.h"
#include "Computer.h"
#include <string>
#include <QtSql>
#include <vector>
#include <iomanip>
#include <QtDebug>

using namespace std;

class ComputerRepository
{
public:
    ComputerRepository();
    void add(Computer c);
    Computer getComputer(int id);
    vector<Computer> getAllComputer();
    int getCPUSize();
    void removeComputer(int id);
    void headerComputerPrint();
private:
    vector<Computer> computerList;
};

#endif // COMPUTERREPOSITORY_H
