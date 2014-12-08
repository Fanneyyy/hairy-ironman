#ifndef CONNECTIONSSERVICE_H
#define CONNECTIONSSERVICE_H

#include "connectionsrepository.h"
#include <QString>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <cstring>
#include "person.h"
#include "search.h"
#include "PersonsRepository.h"
#include "ComputerRepository.h"
#include "sort.h"
#include "personsservice.h"
#include "computersservice.h"

class ConnectionsService
{
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
