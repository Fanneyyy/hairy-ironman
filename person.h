#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

struct fullName {
    string first;
    string last;
};

class Person
{
public:
    Person();
    Person(fullName name, string gender, int yearOfBirth, int yearOfDeath);

    void setName(Person p, string newLast, string newFirst);
    void setGender(Person p, string newGender);
    void setYearOfBirth(Person p, int newYearOfBirth);
    void setYearOfDeath(Person p, int newYearOfDeath);
    string getLastName();
    string getFirstName();
    string getGender();
    int getYearOfBirth();
    int getYearOfDeath();

    friend ostream& operator <<(ostream& outs, const Person& p);
    friend istream& operator >>(istream& ins, Person& p);
private:
    fullName name;
    string gender;
    int yearOfBirth;
    int yearOfDeath;
};

#endif // PERSON_H
