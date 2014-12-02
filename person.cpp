#include "person.h"

Person::Person() {
    name.last = "";
    name.first = "";
    gender = "";
    yearOfBirth = "";
    yearOfDeath = "";
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
    string input;
    cout << "Last name: ";
    do {
        ins >> input;
    } while(!p.validName(input));
    p.name.last = input;
    cout << "First name: ";
    do {
        ins >> input;
    } while(!p.validName(input));
    p.name.first = input;
    cout << "Gender f/m: ";
    do {
        ins >> input;
    } while(!p.validGender(input));
    p.gender = input;
    cout << "Year of birth: ";
    do {
        ins >> input;
    }while(!p.validYear(input));
    p.yearOfBirth = input;
    cout << "Year of death (enter '-' if person is still alive): ";
    do {
        ins >> input;
    }while(!p.validYear(input));
    p.yearOfDeath = input;

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

bool Person::validName(string name) {
    for(unsigned long i = 0; i < name.size(); ++i) {
        if(!isalpha(name[i])) {
            cout << "Not a valid name, please use only letters and no spaces" << endl;
            return false;
        }
    }
    return true;
}

bool Person::validYear(string year) {
    for(unsigned long i = 0; i < year.size(); ++i) {
        if(!isdigit(year[i]) && year[i] != '-') {
            cout << "Not a valid year, please retype" << endl;
            return false;
        }
    }
    int temp;
    istringstream buffer(year);
    buffer >> temp;
    if(temp < 0 || temp > 2014) {
        cout << "Not a valid year, please retype" << endl;
        return false;
    }
    return true;
}

bool Person::validGender(string gender) {
    if(gender != "m" && gender != "M" && gender != "f" && gender != "F") {
        cout << "Not a valid gender, please retype m/f" << endl;
        return false;
    }
    return true;
}

