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
    int sizeOfDatabase();
    vector<Computer> getAll();
    int getSizeOfRepo();
    void setUp();
    void removeAll();
    int findPosition(int ID);
    bool validComputerID(vector<Computer> computers, int ID);
    void remove(int computerID, string ID);
private:
    ComputerRepository computerRepo;
    QSqlDatabase db;
};

#endif // COMPUTERSSERVICE_H
