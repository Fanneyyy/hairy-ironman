#include "connectionsrepository.h"

ConnectionsRepository::ConnectionsRepository() {
}

// add: adds a connection to the database
void ConnectionsRepository::add(Connection c){
    connectionList.push_back(c);
}

// getAll: returns all connections in a vector
vector<Connection> ConnectionsRepository::getAllConnections(){
    return connectionList;
}

// getConnection: returns the connection with that id in the vector
// (possibly but not necessarily the same as in the database)
Connection ConnectionsRepository::getConnection(int id){
    return connectionList[id];
}

//returns the number of connection in the repository
int ConnectionsRepository::getConnectionSize() {
    return connectionList.size();
}
