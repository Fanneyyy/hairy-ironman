#ifndef COMPUTER_H
#define COMPUTER_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <ctime>
#include <iomanip>

using namespace std;

//struct cpuName {
//    string cpuName;
//};

class Computer
{
public:
    Computer();

    void setCPUName(string CPUName);
    void setBuildYear(string newBuildYear);
    void setType(string newType);
    void setBuiltORnot(string newBuiltORnot);
    void print();

    string getCPUname();
    string getBuildYear();
    string getType();
    string getBuiltORnot();

    friend ostream& operator <<(ostream& outs, const Computer& c);
    friend istream& operator >>(istream& ins, Computer& c);

    bool validYear(string year);
    bool validType(string type);
    bool validName(string name);
//    bool birthVSDeath(string yearBirth, string yearDeath);
private:
    string name;
    string buildYear;
    string type;
    string builtRnot;
};

#endif // COMPUTER_H
