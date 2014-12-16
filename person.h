// Person: A class that stores information about a person. Valid names are strings that include
// only alphabetic letters, valid genders are only the strings male or female (not case sensitive)
// and valid years are only digits from 0 to the current year. cout and cin operators have been overloaded.

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <algorithm>
#include <Qstring>
#include "utilities.h"

using namespace std;

class Person {
public:
    Person();

    void setName(string newName);
    void setGender(string newGender);
    void setYearOfBirth(string newYearOfBirth);
    void setYearOfDeath(string newYearOfDeath);
    void setID(string id);

    string getName();
    string getGender();
    string getYearOfBirth();
    string getYearOfDeath();
    string toString();

    int getID();

    bool contains(string search);
private:
    string name;
    string gender;
    string yearOfBirth;
    string yearOfDeath;
    string ID;
    Utilities utilities;
};

#endif // PERSON_H
