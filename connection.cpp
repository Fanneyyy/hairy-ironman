#include "connection.h"

Connection::Connection() {
    personID = 0;
    computerID = 0;
}

int Connection::getPersonID () {
    return personID;
}

int Connection::getComputerID() {
    return computerID;
}

void Connection::setPersonID(int id) {
    personID = id;
}

void Connection::setComputerID(int id) {
    computerID = id;
}
