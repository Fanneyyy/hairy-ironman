#include "connectionsrepository.h"

ConnectionsRepository::ConnectionsRepository() {
}

void ConnectionsRepository::add(Connection c){
    connectionList.push_back(c);
}
