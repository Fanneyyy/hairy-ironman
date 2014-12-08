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

class ConnectionsService
{
public:
    ConnectionsService();
    QSqlDatabase getDatabaseConnection();
    void setUp();
    void saveConnectionToDatabase(Connection c);
private:
    ConnectionsRepository connectionRepo;
    QSqlDatabase db;
};

#endif // CONNECTIONSSERVICE_H
