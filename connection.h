// Connection: A class that stores information about a connection between a person and a computer.

#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>

using namespace std;

class Connection {
public:
    Connection();

    int getPersonID();
    int getComputerID();

    void setPersonID(int id);
    void setComputerID(int id);
private:
    int personID;
    int computerID;
};

#endif // CONNECTION_H
