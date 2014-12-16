#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <Qstring>
#include "utilities.h"

using namespace std;

class Computer {
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

    bool contains(string search);
    string toString();
private:
    string name;
    string buildYear;
    string type;
    string builtRnot;
    string ID;
    Utilities utilities;
};

#endif // COMPUTER_H
