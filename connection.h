#ifndef CONNECTION_H
#define CONNECTION_H

class Connection
{
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
