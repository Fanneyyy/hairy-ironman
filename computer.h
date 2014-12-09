#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <ctime>
#include <iomanip>

using namespace std;

class Computer
{
public:
    Computer();

    void setComputerName(string CPUName);
    void setBuildYear(string newBuildYear);
    void setType(string newType);
    void setBuiltRnot(string newBuiltORnot);
    void setID(string newID);

    string getComputerName();
    string getBuildYear();
    string getType();
    string getBuiltRnot();
    int getID();

    friend ostream& operator <<(ostream& outs, const Computer& c);
    friend istream& operator >>(istream& ins, Computer& c);

    bool validYear(string year);
    bool validType(string type);
    bool validName(string name);


private:
    string name;
    string buildYear;
    string type;
    string builtRnot;
    string ID;
};

#endif // COMPUTER_H
