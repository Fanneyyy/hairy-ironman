#include "person.h"

Person::Person() {
    name.last = "empty";
    name.first = "empty";
    gender = "neutral";
    yearOfBirth = "0";
    yearOfDeath = "0";
}

Person::Person(fullName name, string gender, string yearOfBirth, string yearOfDeath) {
    this -> name = name;
    this -> gender = gender;
    this -> yearOfBirth = yearOfBirth;
    this -> yearOfDeath = yearOfDeath;
}
void Person::print(){
    cout << "Name: " << name.first << " " << name.last << endl;
    cout << "Gender: " << gender << endl;
    cout << "Year of birth: " << yearOfBirth << endl;
    cout << "Year of death: " << yearOfDeath << endl << endl;
}

ostream& operator <<(ostream& outs, const Person& p) {
    outs << p.name.first << endl;
    outs << p.name.last << endl;
    outs << p.gender << endl;
    outs << p.yearOfBirth << endl;
    outs << p.yearOfDeath << endl;

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

void Person::setFirstName(string newFirst) {
    name.first = newFirst;
}
void Person::setLastName(string newLast) {
    name.last = newLast;
}

void Person::setGender(string newGender) {
    gender = newGender;
}

void Person::setYearOfBirth(string newYearOfBirth) {
    yearOfBirth = newYearOfBirth;
}

void Person::setYearOfDeath(string newYearOfDeath) {
    yearOfDeath = newYearOfDeath;
}

string Person::getLastName() {
    return name.last;
}

string Person::getFirstName() {
    return name.first;
}

string Person::getGender() {
    return gender;
}

string Person::getYearOfBirth() {
    return yearOfBirth;
}

string Person::getYearOfDeath() {
    return yearOfDeath;
}
