#include "person.h"

Person::Person() {
    name.last = "empty";
    name.first = "empty";
    gender = "neutral";
    yearOfBirth = 0;
    yearOfDeath = 0;
}

Person::Person(fullName name, string gender, int yearOfBirth, int yearOfDeath) {
    this -> name = name;
    this -> gender = gender;
    this -> yearOfBirth = yearOfBirth;
    this -> yearOfDeath = yearOfDeath;
}

ostream& operator <<(ostream& outs, const Person& p) {
    outs << "Name: " << p.name.first << " " << p.name.last << endl;
    outs << "Gender: " << p.gender << endl;
    outs << "Year of birth: " << p.yearOfBirth << endl;
    outs << "Year of death: " << p.yearOfDeath << endl << endl;

    return outs;
}

istream& operator >>(istream& ins, Person& p) {

    cout << "Last name: ";
    ins >> p.name.last;
    cout << "First name: ";
    ins >> p.name.first;
    cout << "Gender: ";
    ins >> p.gender;
    cout << "Year of birth: ";
    ins >> p.yearOfBirth;
    cout << "Year of death: ";
    ins >> p.yearOfDeath;

    return ins;
}

void Person::setName(Person p, string newLast, string newFirst) {
    p.name.last = newLast;
    p.name.first = newFirst;
}

void Person::setGender(Person p, string newGender) {
    p.gender = newGender;
}

void Person::setYearOfBirth(Person p, int newYearOfBirth) {
    p.yearOfBirth = newYearOfBirth;
}

void Person::setYearOfDeath(Person p, int newYearOfDeath) {
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
