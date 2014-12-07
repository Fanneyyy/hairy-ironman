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
    int getComputerSize();
    void removeComputer(int id);
    void headerComputerPrint();
    vector<Computer> sortVector(vector<Computer> computers, int theCase);
private:
    vector<Computer> computerList;
};
    bool sortByName(Computer c1, Computer c2);
    bool sortByType(Computer c1, Computer c2);
    bool sortByBuildYear(Computer c1, Computer c2);
    bool sortByBuiltRnot(Computer c1, Computer c2);

#endif // COMPUTERREPOSITORY_H
