
#include "computer.h"

Computer::Computer() {
    name = "";
    buildYear = "";
    type = "";
    builtRnot = "";
}

void Computer::print(){

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
    cout << "Enter name: ";
    do {
        ins >> input;
    } while(!c.validName(input));
    c.name = input;
   // cout << "First name: ";
    cout << "Build year: ";
    do {
        ins >> input;
    } while(!c.validYear(input));
    c.buildYear = input;
    cout << "Type: ";
    do {
        ins >> input;
    }while(!c.validType(input));
    c.type = input;
    cout << "Year of death (enter '-' if Computer is still alive): ";
    return ins;
}

void Computer::setCPUName(string CPUName) {
    name = CPUName;
}

void Computer::setBuildYear(string newBuildYear) {
    buildYear = newBuildYear;
}

void Computer::setType(string newType) {
    type = newType;
}

void Computer::setBuiltORnot(string newBuiltORnot) {
    builtRnot = newBuiltORnot;
}

string Computer::getCPUname() {
    return name;
}

string Computer::getBuildYear() {
    return buildYear;
}

string Computer::getType() {
    return type;
}

string Computer::getBuiltORnot() {
    return builtRnot;
}


// validName(): checks if the name has only alphabetic letters.
bool Computer::validName(string name) {
    for(unsigned int i = 0; i < name.size(); ++i) {
        if(!isalpha(name[i])) {
            cout << "Not a valid name, please use only letters and no spaces" << endl;
            return false;
        }
    }
    return true;
}
// validYear(): checks if the year has only digits from 0 to current year.
bool Computer::validYear(string year) {
    time_t t = time(NULL);
    tm* timePtr = localtime(&t);

    if(year.size() > 4)
    {
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
// validGender(): checks if the gender is 'm', 'M', 'f' or 'F'.
bool Computer::validType(string type) {
    if(type != "m" && type != "M" && type != "f" && type != "F") {
        cout << "Not a valid gender, please retype m/f" << endl;
        return false;
    }
    return true;
}
