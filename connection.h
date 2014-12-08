#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>
#include "personsservice.h"
#include "computersservice.h"

using namespace std;

class Connection
{
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