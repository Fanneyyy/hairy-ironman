// Service: Takes commands from the user interface, seeks information from the repository
// and relays the appropriate information back to the user interface.

#ifndef CONNECTIONSSERVICE_H
#define CONNECTIONSSERVICE_H

#include <QString>
#include <string>
#include <vector>
#include <limits>
#include <cstring>
#include <QtSql>
#include <QtDebug>
#include "connectionsrepository.h"
#include "personsrepository.h"
#include "computerrepository.h"

class ConnectionsService {
public:
    ConnectionsService();
    int getSizeOfRepo();
    vector<Connection> getAll();
    vector<Computer> printAllPerson(int ID, vector<Computer> computerList);
    void add(Connection c);
    vector<Person> printAllComputer(int ID, vector<Person> personList);
    void setUp();
    void removeAll();
private:
    ConnectionsRepository connectionRepo;
};

#endif // CONNECTIONSSERVICE_H
