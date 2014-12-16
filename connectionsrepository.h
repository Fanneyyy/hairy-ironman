// Repository: Stores in a vector instances of connections, handles add and relays information
// about the repository

#ifndef CONNECTIONSREPOSITORY_H
#define CONNECTIONSREPOSITORY_H

#include "connection.h"
#include <vector>
#include <QtSql>
#include <QtDebug>
#include <QString>
#include <string>
#include <vector>
#include <limits>
#include <cstring>

using namespace std;

class ConnectionsRepository {
public:
    ConnectionsRepository();
    void add(Connection c);
    Connection getConnection(int id);
    int getConnectionSize();
    vector<Connection> getAllConnections();
    QSqlDatabase getDatabaseConnection();
    void setUp();
    void saveConnectionToDatabase(Connection c);
    void addConnectionToVectorAndDatabase(Connection c);
    void remove(int id);
    void emptyRepo();
private:
    vector<Connection> connectionList;
    QSqlDatabase db;
};

#endif // CONNECTIONSREPOSITORY_H
