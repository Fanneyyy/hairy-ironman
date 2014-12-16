#include "utilities.h"

Utilities::Utilities() {
}

// validName(): checks if the name has only alphabetic letters.
bool Utilities::validName(string name) {
    bool validChar = true;
    bool onlySpaces = true;
    for(unsigned int i = 0; i < name.size(); ++i) {
        if(!isspace(name[i])) {
            onlySpaces = false;
        }
        if(!isalpha(name[i]) && !isspace(name[i])) {
            cout << "Not a valid name, please use only letters" << endl;
            validChar = false;
        }
    }
    return (validChar && !onlySpaces);
}

// validYear(): checks if the year has only digits from 0 to 2014.
bool Utilities::validYear(string year) {
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
bool Utilities::validGender(string gender) {
    string temp = gender;
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
    if(temp != "female" && temp != "male") {
        cout << "Not a valid gender, please retype male/female" << endl;
        return false;
    }
    return true;
}

// birthVSDeath: makes sure you can not die before you are born
bool Utilities::birthVSDeath(string yearBirth, string yearDeath) {
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

// trimWhiteSpace: removes whitespaces at beginning and end of a string
// and leaves only one whitespace, where two or more are enter inside string
void Utilities::trimWhiteSpace(string& input) {
    QString stringInput = QString::fromUtf8(input.c_str());
    stringInput = stringInput.simplified();
    input = stringInput.toUtf8().constData();
}

string Utilities::stringToLower(string original) {
    string result = "";
    for(unsigned int i = 0; i < original.length(); ++i) {
        result += tolower(original[i]);
    }
    return result;
}
