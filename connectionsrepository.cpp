#include "connectionsrepository.h"

ConnectionsRepository::ConnectionsRepository() {
}

void ConnectionsRepository::add(Connection c){
    connectionList.push_back(c);
}

vector<Connection> ConnectionsRepository::getAllConnections(){
    return connectionList;
}

Connection ConnectionsRepository::getConnection(int id){
    return connectionList[id];
}

int ConnectionsRepository::getConnectionSize() {
    return connectionList.size();
}
