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

    Computer getComputer(int id);

    void add(Computer c);
    void emptyRepo();
    void saveComputerToDatabase(Computer c);
    void setUp();
    void addComputerToVectorAndDatabase(Computer c);
    void removeFromDatabase(string ID);
    void remove(int id);

    vector<Computer> getAllComputer();

    int getComputerSize();

    QSqlDatabase getDatabaseConnection();

    string getComputerID();
private:
    vector<Computer> computerList;

    QSqlDatabase db;
};

#endif // COMPUTERREPOSITORY_H
