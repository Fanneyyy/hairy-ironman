
#include "computer.h"

Computer::Computer() {
    name = "";
    buildYear = "";
    type = "";
    builtRnot = "";
}

ostream& operator <<(ostream& outs, const Computer& c) {
    outs << c.name << endl;
    outs << c.buildYear << endl;
    outs << c.type << endl;
    outs << c.builtRnot << endl;

    return outs;
}

istream& operator >>(istream& ins, Computer& c) {
    string input;
    char inputName[256];
    cout << "Enter name: ";
    cin.getline (inputName,256);
    c.name = inputName;
    cout << "Build year (enter '-' if it was never built): ";
    do {
        ins >> input;
    } while(!c.validYear(input));
    c.buildYear = input;
    if(input == "-") {
        c.setBuiltRnot("FALSE");
    } else {
        c.setBuiltRnot("TRUE");
    }
    cout << "Choose a type for the computer:" << endl;
    cout << "1 - Electronic computer" << endl;
    cout << "2 - Transistor computer" << endl;
    cout << "3 - Mechanical computer" << endl;
    do {
        ins >> input;
    }while(!c.validType(input));
    c.type = input;
    return ins;
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

// validYear(): checks if the year has only digits from 0 to current year.
bool Computer::validYear(string year) {
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

    if(year == "-") {
        return true;
    }
    if(year.size() > 4) {
        cout << "Not a valid year, please select another." << endl;
        return false;
    }
    for(unsigned int i = 0; i < year.size(); ++i) {
        if(!isdigit(year[i]) && year[i] != '-') {
            cout << "Not a year, please select another." << endl;
            return false;
        }
    }
    int temp;
    istringstream buffer(year);
    buffer >> temp;
    if(temp > 1900+timePtr->tm_year) {
        cout << "This year is in the future, please select another" << endl;
        return false;
    }
    else if(temp < 0) {
        cout << "This year is BC, don't be ridiculous, select another" << endl;
        return false;
    }
    return true;
}

// validType(): checks if the input is valid, i.e. 1, 2 or 3
bool Computer::validType(string type) {
    if(type != "1" && type != "2" && type != "3") {
        cout << "This is not a valid choice, please try again" << endl;
        return false;
    }
    return true;
}
