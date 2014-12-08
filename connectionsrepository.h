#ifndef CONNECTIONSREPOSITORY_H
#define CONNECTIONSREPOSITORY_H

#include "connection.h"
#include <vector>

using namespace std;

class ConnectionsRepository
{
public:
    ConnectionsRepository();
    void add(Connection c);
private:
    vector<Connection> connectionList;
};

#endif // CONNECTIONSREPOSITORY_H
