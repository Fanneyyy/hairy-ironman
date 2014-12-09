#include "computer.h"

Computer::Computer() {
    ID = "";
    name = "";
    buildYear = "";
    type = "";
    builtRnot = "";
}

ostream& operator <<(ostream& outs, const Computer& c) {
    string built;
    if(c.builtRnot == "TRUE") {
        built = "Yes";
    } else {
        built = "No";
    }
    outs << fixed;
    outs << left << setw(25) << c.name << setw(15) << c.type;
    outs << left << setw(15) << c.buildYear << setw(15) << built << endl;
    return outs;
}

istream& operator >>(istream& ins, Computer& c) {
    string input;
    string E = "Electronic";
    string T = "Transistor";
    string M = "Mechanical";
    char inputName[256];

    cout << "Enter name: ";
    cin.ignore();
    cin.getline (inputName,256);
    input = inputName;
    c.trimWhiteSpace(input);
    c.name = input;

    cout << "Build year (enter '-' if it was never built): ";
    do {
        ins >> input;
    } while(!c.validYear(input));
    if(input == "-") {
        c.buildYear = "";
    } else {
        c.buildYear = input;
    }
    if(input == "-") {
        c.setBuiltRnot("FALSE");
    } else {
        c.setBuiltRnot("TRUE");
    }
    cout << "Choose a type for the computer:" << endl;
    cout << "1 - " << E << "\n" << "2 - " << T << "\n" << "3 - " << M << endl;
    do {
        ins >> input;
    }while(!c.validType(input));
    if(input == "1") {
        c.type = E;
    } else if(input == "2") {
        c.type = T;
    } else if(input == "3") {
        c.type = M;
    }
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

int Computer::getID() {
    int temp;

    istringstream buffer(ID);
    buffer >> temp;
    return temp;
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

// trimWhiteSpace: removes whitespaces at beginning and end of a string
// and leaves only one whitespace, where two or more are enter inside string
void Computer::trimWhiteSpace(string& input) {
    QString stringInput = QString::fromUtf8(input.c_str());
    stringInput = stringInput.simplified();
    input = stringInput.toUtf8().constData();
}
