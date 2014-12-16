#include "connectionsservice.h"

ConnectionsService::ConnectionsService() {
}

// add: adds a connection between a person and a computer to the database
void ConnectionsService::add(Connection c) {
    connectionRepo.addConnectionToVectorAndDatabase(c);
}

void ConnectionsService::removeAll() {
    connectionRepo.emptyRepo();
}

void ConnectionsService::setUp() {
    connectionRepo.setUp();
}

// printAllPerson: prints a list of persons with the appropriate connected computers
vector<Computer> ConnectionsService::printAllPerson(int ID, vector<Computer>computerList) {
    vector<Computer> findings;
    int computerIDtemp;
    for(int j = 0; j < connectionRepo.getConnectionSize(); j++) {
        if(ID == (connectionRepo.getConnection(j).getPersonID())) {
            computerIDtemp = connectionRepo.getConnection(j).getComputerID();
            for(unsigned int i = 0; i < computerList.size(); i++) {
                if(computerIDtemp == computerList[i].getID()) {
                    findings.push_back(computerList[i]);
                }
            }
        }
    }
    return findings;
}

vector<Person> ConnectionsService::printAllComputer(int ID, vector<Person> personList) {
    vector<Person> findings;
    int personIDtemp;
    for(int j = 0; j < connectionRepo.getConnectionSize(); j++) {
        if(ID == (connectionRepo.getConnection(j).getComputerID())) {
            personIDtemp = connectionRepo.getConnection(j).getPersonID();
            for(unsigned int i = 0; i < personList.size(); i++) {
                if(personIDtemp == personList[i].getID()) {
                    findings.push_back(personList[i]);
                }
            }
        }
    }
    return findings;
}

vector<Connection> ConnectionsService::getAll() {
    return connectionRepo.getAllConnections();
}

int ConnectionsService::getSizeOfRepo() {
    return connectionRepo.getConnectionSize();
}
