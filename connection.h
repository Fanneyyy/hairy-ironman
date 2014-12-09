#ifndef CONNECTION_H
// Connection: A class that stores information about a connection between a person and a computer.

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

    friend ostream& operator <<(ostream& outs, const Connection& c);
    friend istream& operator >>(istream& ins, Connection& c);
    bool inputCheck(int input, int maxcases);
private:
    int personID;
    int computerID;
};

#endif // CONNECTION_H
