// Service: Takes commands from the user interface, seeks information from the repository
// and relays the appropriate information back to the user interface.

#ifndef CONNECTIONSSERVICE_H
#define CONNECTIONSSERVICE_H

#include <QString>
#include <string>
#include <vector>
#include <limits>
#include <cstring>
#include "connectionsrepository.h"
#include "personsrepository.h"
#include "computerrepository.h"

class ConnectionsService {
public:
    ConnectionsService();
    QSqlDatabase getDatabaseConnection();
    void setUp();
    void saveConnectionToDatabase(Connection c);
    int getSizeOfRepo();
    vector<Connection> getAll();
    void printAllPerson(vector<Person> personList, vector<Computer> computerList, int size);
    void printAllComputer(vector<Computer> computerList, vector<Person> personList, int size);
    void add(int sizeOfPersons, int sizeOfComputers);
    bool inputCheck(int input, int max);
private:
    ConnectionsRepository connectionRepo;
    QSqlDatabase db;
};

#endif // CONNECTIONSSERVICE_H
