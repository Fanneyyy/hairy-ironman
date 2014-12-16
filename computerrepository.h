// Repository: Stores in a vector instances of computers, handles add and relays information
// about the repository

#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H

#include <vector>
#include <string>
#include <QString>
#include <QtSql>
#include <QtDebug>
#include "Person.h"
#include "Computer.h"

using namespace std;

class ComputerRepository {
public:
    ComputerRepository();
    void add(Computer c);
    Computer getComputer(int id);
    vector<Computer> getAllComputer();
    int getComputerSize();
    void emptyRepo();
    void saveComputerToDatabase(Computer c);
    QSqlDatabase getDatabaseConnection();
    void setUp();
    void addComputerToVectorAndDatabase(Computer c);
    string getComputerID();
private:
    vector<Computer> computerList;
    QSqlDatabase db;
};

#endif // COMPUTERREPOSITORY_H
