#include "computer.h"

Computer::Computer() {
    ID = "";
    name = "";
    buildYear = "";
    type = "";
    builtRnot = "";
}

void Computer::setComputerName(string CPUName) {
    name = CPUName;
}

void Computer::setBuildYear(string newBuildYear) {
    buildYear = newBuildYear;
}

void Computer::setType(string newType) {
    type = newType;
}

void Computer::setBuiltRnot(string newBuiltORnot) {
    builtRnot = newBuiltORnot;
}

void Computer::setID(string newID) {
    ID = newID;
}

string Computer::getComputerName() {
    return name;
}

string Computer::getBuildYear() {
    return buildYear;
}

string Computer::getType() {
    return type;
}

string Computer::getBuiltRnot() {
    return builtRnot;
}

// getID(): returns the ID from the database not the vector
int Computer::getID() {
    int temp;

    istringstream buffer(ID);
    buffer >> temp;
    return temp;
}

string Computer::toString() {
    return name + " " + buildYear;
}

// contains: search for a string in a compuers name eða build year.
bool Computer::contains(string search) {
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
