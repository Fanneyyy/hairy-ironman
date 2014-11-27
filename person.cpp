#include "person.h"

Person::Person() {
    name.last = "empty";
    name.first = "empty";
    gender = "neutral";
    yearOfBirth = 0;
    yearOfDeath = 0;
}

Person::Person(fullName newName, string newGender, int newYearOfBirth, int newYearOfDeath) {
    name = newName;
    gender = newGender;
    yearOfBirth = newYearOfBirth;
    yearOfDeath = newYearOfDeath;
}

ostream& operator <<(ostream& outs, const Person& p) {
    outs << "Name: " << p.name.first << " " << p.name.last << endl;
    outs << "Gender: " << p.gender << endl;
    outs << "Year of birth: " << p.yearOfBirth << endl;
    outs << "Year of death: " << p.yearOfDeath << endl;
    return outs;
}

istream& operator >>(istream& ins, Person& p) {
    string newLast, newFirst, newGender;
    int newYearOfBirth, newYearOfDeath;
    cout << "Type in the persons last name, first name, gender, year of birth ";
    cout << "and year of death, seperated by a space." << endl;
    ins >> newLast >> newFirst >> newGender >> newYearOfBirth >> newYearOfDeath;
    p.name.last = newLast;
    p.name.first = newFirst;
    p.gender = newGender;
    p.yearOfBirth = newYearOfBirth;
    p.yearOfDeath = newYearOfDeath;
    return ins;
}

void Person::changeName(Person p, string newLast, string newFirst) {
    p.name.last = newLast;
    p.name.first = newFirst;
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

string Person::getLastName(Person p) {
    return p.name.last;
}

string Person::getFirstName(Person p) {
    return p.name.first;
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
