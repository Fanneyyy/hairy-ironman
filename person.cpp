#include "person.h"

Person::Person() {
    ID = "";
    name = "";
    gender = "";
    yearOfBirth = "";
    yearOfDeath = "";
}

void Person::setName(string newName) {
    name = newName;
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

void Person::setID(string id) {
    ID = id;
}

string Person::getName() {
    return name;
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

// getID(): returns the ID from the database not the vector
int Person::getID() {
    int temp;
    // returns ID as int not string
    istringstream buffer(ID);
    buffer >> temp;
    return temp;
}

string Person::toString() {
    return name + " " + yearOfBirth + " " + yearOfDeath;
}

// contains: search for a string in a persons name, yearOfBirth eða yearOfDeath.
bool Person::contains(string search) {
    if(search == "") {
        return true;
    }
    string searchStringToLower = utilities.stringToLower(search);

    if(utilities.stringToLower(this->toString()).find(searchStringToLower) != string::npos) {
        return true;
    }
    else {
        return false;
    }
}
