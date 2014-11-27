#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person
{
public:
    Person();
    Person(string newName, string newGender, int newYearOfBirth, int newYearOfDeath);
    friend ostream& operator <<(ostream& outs, const Person& p);
    friend istream& operator >>(istream& ins, Person& p);
    void changeName(Person p, string newName);
    void changeGender(Person p, string newGender);
    void changeYearOfBirth(Person p, int newYearOfBirth);
    void changeYearOfDeath(Person p, int newYearOfDeath);
    string getName(Person p);
    string getGender(Person p);
    int getYearOfBirth(Person p);
    int getYearOfDeath(Person p);
private:
    string name;
    string gender;
    int yearOfBirth;
    int yearOfDeath;
};

#endif // PERSON_H
