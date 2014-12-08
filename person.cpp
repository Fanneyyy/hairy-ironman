#include "person.h"

Person::Person() {
    name.last = "";
    name.first = "";
    gender = "";
    yearOfBirth = "";
    yearOfDeath = "";
}

ostream& operator <<(ostream& outs, const Person& p) {
    string name;
    name = p.name.first + " " + p.name.last;
    outs << fixed;
    outs << left << setw(25) << name << setw(15) << p.gender << setw(15) <<   p.yearOfBirth;
    outs << left <<setw(15) << p.yearOfDeath << endl;
    return outs;
}

istream& operator >>(istream& ins, Person& p) {
    string input;
    cout << "Enter name: ";
    do {
        ins >> input;
    } while(!p.validName(input));
    p.name.first = input;
    do {
        ins >> input;
    } while(!p.validName(input));
    p.name.last = input;
    cout << "Gender Female/Male: ";
    do {
        ins >> input;
    } while(!p.validGender(input));
    p.gender = input;
    cout << "Year of birth: ";
    do {
        ins >> input;
    }while(!p.validYear(input));
    p.yearOfBirth = input;
    cout << "Year of death (please enter '-' if person is still alive): ";
    do {
        ins >> input;
    }while(!p.validYear(input) || !p.birthVSDeath(p.yearOfBirth, input));
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
// validName(): checks if the name has only alphabetic letters.
bool Person::validName(string name) {
    for(unsigned int i = 0; i < name.size(); ++i) {
        if(!isalpha(name[i])) {
            cout << "Not a valid name, please use only letters and no spaces" << endl;
            return false;
        }
    }
    return true;
}
// validYear(): checks if the year has only digits from 0 to 2014.
bool Person::validYear(string year) {
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
// validGender(): checks if the gender is 'Male' or 'Female' not case sensitive.
bool Person::validGender(string gender) {
    string temp = gender;
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    if(temp != "female" && temp != "male") {
        cout << "Not a valid gender, please retype Male/Female" << endl;
        return false;
    }
    return true;
}

bool Person::birthVSDeath(string yearBirth, string yearDeath) {
    int birth, death;
    istringstream bbuffer(yearBirth);
    bbuffer >> birth;
    istringstream dbuffer(yearDeath);
    dbuffer >> death;

    if(birth > death) {
        cout << "Sorry, we do not allow death before birth, Please select another year of death. " << endl;
        return false;
    }

    return true;
}

