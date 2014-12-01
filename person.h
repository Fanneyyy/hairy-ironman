#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct fullName {
    string first;
    string last;
};

class Person
{
public:
    Person();
    Person(fullName name, string gender, string yearOfBirth, string yearOfDeath);

    void setFirstName(string newFirst);
    void setLastName(string newLast);
    void setGender(string newGender);
    void setYearOfBirth(string newYearOfBirth);
    void setYearOfDeath(string newYearOfDeath);
    void print();

    string getLastName();
    string getFirstName();
    string getGender();
    string getYearOfBirth();
    string getYearOfDeath();

    friend ostream& operator <<(ostream& outs, const Person& p);
    friend istream& operator >>(istream& ins, Person& p);

    bool validYear(string year);
private:
    fullName name;
    string gender;
    string yearOfBirth;
    string yearOfDeath;
};

#endif // PERSON_H
