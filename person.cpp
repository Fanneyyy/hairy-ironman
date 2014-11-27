#include "person.h"

Person::Person() {
    name = "empty";
    gender = "neutral";
    yearOfBirth = 0;
    yearOfDeath = 0;
}

Person::Person(string newName, string newGender, int newYearOfBirth, int newYearOfDeath) {
    name = newName;
    gender = newGender;
    yearOfBirth = newYearOfBirth;
    yearOfDeath = newYearOfDeath;
}

ostream& operator <<(ostream& outs, const Person& p) {
    outs << "Name: " << p.name << endl;
    outs << "Gender: " << p.gender << endl;
    outs << "Year of birth: " << p.yearOfBirth;
    outs << "Year of death: " << p.yearOfDeath;
    return outs;
}

istream& operator >>(istream& ins, Person& p) {
    string newName, newGender;
    int newYearOfBirth, newYearOfDeath;
    ins >> newName >> newGender >> newYearOfBirth >> newYearOfDeath;
    p.name = newName;
    p.gender = newGender;
    p.yearOfBirth = newYearOfBirth;
    p.yearOfDeath = newYearOfDeath;
    return ins;
}

void Person::changeName(Person p, string newName) {
    p.name = newName;
}

void Person::changeGender(Person p, string newGender) {
    p.gender = newGender;
}

void Person::changeYearOfBirth(Person p, int newYearOfBirth) {
    p.yearOfBirth = newYearOfBirth;
}

void Person::changeYearOfDeath(Person p, int newYearOfDeath) {
    p.yearOfDeath = newYearOfDeath;
}

string Person::getName(Person p) {
    return p.name;
}

string Person::getGender(Person p) {
    return p.gender;
}

int Person::getYearOfBirth(Person p) {
    return p.yearOfBirth;
}

int Person::getYearOfDeath(Person p) {
    return p.yearOfDeath;
}
