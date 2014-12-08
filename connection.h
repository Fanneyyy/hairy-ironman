#ifndef CONNECTION_H
#define CONNECTION_H

#include <iostream>

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
private:
    int personID;
    int computerID;
};

#endif // CONNECTION_H
