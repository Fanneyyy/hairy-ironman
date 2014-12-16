#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>
#include <string>
#include <sstream>
#include <Qstring>

using namespace std;

class Utilities
{
public:
    Utilities();
    string stringToLower(string original);
    bool validYear(string year);
    bool validGender(string gender);
    bool validName(string name);
    bool birthVSDeath(string yearBirth, string yearDeath);
    void trimWhiteSpace(string &input);
};

#endif // UTILITIES_H