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
void Person::printAll(const Person& p){
    cout << p.name.first << endl;
    cout << p.name.last << endl;
    cout << p.gender << endl;
    cout << p.yearOfBirth << endl;
    cout << p.yearOfDeath << endl;

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

string Person::getLastName() {
    return name.last;
}

string Person::getFirstName() {
    return name.first;
}

string Person::getGender() {
    return gender;
}

int Person::getYearOfBirth() {
    return yearOfBirth;
}

int Person::getYearOfDeath() {
    return yearOfDeath;
}
