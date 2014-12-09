// Person: A class that stores information about a person. Valid names are strings that include
// only alphabetic letters, valid genders are only the strings 'm', 'M', 'f' and 'F' and valid
// years are only digits from 0 to 2014. cout and cin operators have been overloaded.

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <ctime>
#include <iomanip>
#include <algorithm>

using namespace std;

struct fullName {
    string first;
    string last;
};

class Person
{
public:
    Person();

    void setFirstName(string newFirst);
    void setLastName(string newLast);
    void setGender(string newGender);
    void setYearOfBirth(string newYearOfBirth);
    void setYearOfDeath(string newYearOfDeath);
    void setID(string newID);

    string getLastName();
    string getFirstName();
    string getGender();
    string getYearOfBirth();
    string getYearOfDeath();
    string getFullName();
    int getID();

    friend ostream& operator <<(ostream& outs, const Person& p);
    friend istream& operator >>(istream& ins, Person& p);

    bool validYear(string year);
    bool validGender(string gender);
    bool validName(string name);
    bool birthVSDeath(string yearBirth, string yearDeath);

private:
    fullName name;
    string gender;
    string yearOfBirth;
    string yearOfDeath;
    string ID;
};

#endif // PERSON_H
