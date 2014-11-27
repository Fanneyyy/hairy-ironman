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
    Person(fullName newName, string newGender, int newYearOfBirth, int newYearOfDeath);
    friend ostream& operator <<(ostream& outs, const Person& p);
    friend istream& operator >>(istream& ins, Person& p);
    void changeName(Person p, string newLast, string newFirst);
    void changeGender(Person p, string newGender);
    void changeYearOfBirth(Person p, int newYearOfBirth);
    void changeYearOfDeath(Person p, int newYearOfDeath);
    string getLastName(Person p);
    string getFirstName(Person p);
    string getGender(Person p);
    int getYearOfBirth(Person p);
    int getYearOfDeath(Person p);
private:
    fullName name;
    string gender;
    int yearOfBirth;
    int yearOfDeath;
};

#endif // PERSON_H
