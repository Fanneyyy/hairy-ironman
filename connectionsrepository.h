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
    Connection getConnection(int id);
    int getConnectionSize();
    vector<Connection> getAllConnections();
private:
    vector<Connection> connectionList;
};

#endif // CONNECTIONSREPOSITORY_H
