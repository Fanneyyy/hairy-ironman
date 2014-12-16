// Service: Takes commands from the user interface, seeks information from the repository
// and relays the appropriate information back to the user interface.

#ifndef COMPUTERSSERVICE_H
#define COMPUTERSSERVICE_H

#include <string>
#include <vector>
#include <limits>
#include <cstring>
#include <QString>
#include <QtSql>
#include <QtDebug>
#include "computerrepository.h"

class ComputersService {
public:
    ComputersService();

    Computer get(int id);

    void add(Computer c);
    void setUp();
    void removeAll();
    void remove(int computerID, string ID);

    int sizeOfDatabase();
    int getSizeOfRepo();
    int findPosition(int ID);

    vector<Computer> getAll();

    bool validComputerID(vector<Computer> computers, int ID);
private:
    ComputerRepository computerRepo;

    QSqlDatabase db;
};

#endif // COMPUTERSSERVICE_H
