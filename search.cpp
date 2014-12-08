#include "search.h"

using namespace std;

Search::Search() {
}

// nameFirst: search the vector persons for a person with a
// first name equal to name.
int* Search::personName(vector<Person> persons, string name) {
    string tempName = name;
    string first;
    string last;
    transform(tempName.begin(), tempName.end(), tempName.begin(), ::tolower);
    int* ids = new int[persons.size()]();
    for(unsigned int i = 0; i < persons.size(); i++) {
        first = persons[i].getFirstName();
        last = persons[i].getLastName();
        transform(first.begin(), first.end(), first.begin(), ::tolower);
        transform(last.begin(), last.end(), last.begin(), ::tolower);
        size_t foundFirst = first.find(tempName);
        size_t foundLast = last.find(tempName);
        if(foundFirst != string::npos) {
            ids[i] = 1;
        } else if(foundLast != string::npos) {
            ids[i] = 1;
        }
    }
    return ids;
}

// gender: search the vector persons for a person with a
// gender equal to the string gender.
int* Search::gender(vector<Person> persons, string gender) {
    int* ids = new int[persons.size()]();
    for(unsigned int i = 0; i < persons.size(); i++) {
        if(persons[i].getGender() == gender) {
            ids[i] = 1;
        }
    }
    return ids;
}

// birthYear: search the vector persons for a person with a
// birth year equal to the string year.
int* Search::birthYear(vector<Person> persons, string year) {
    int* ids = new int[persons.size()]();
    for(unsigned int i = 0; i < persons.size(); i++) {
        if(persons[i].getYearOfBirth() == year) {
            ids[i] = 1;
        }
    }
    return ids;
}

// deathYear: search the vector persons for a person with a
// death year equal to the string year.
int* Search::deathYear(vector<Person> persons, string year) {
    int* ids = new int[persons.size()]();
    for(unsigned int i = 0; i < persons.size(); i++) {
        if(persons[i].getYearOfDeath() == year) {
            ids[i] = 1;
        }
    }
    return ids;
}

int* Search::computerName(vector<Computer> computers, string name) {
    string tempName = name;
    string computerName;
    transform(tempName.begin(), tempName.end(), tempName.begin(), ::tolower);
    int* ids = new int[computers.size()]();
    for(unsigned int i = 0; i < computers.size(); i++) {
        computerName = computers[i].getComputerName();
        transform(computerName.begin(), computerName.end(), computerName.begin(), ::tolower);
        size_t foundComputer = computerName.find(tempName);
        if(foundComputer != string::npos) {
            ids[i] = 1;
        }
    }
    return ids;
}

int* Search::type(vector<Computer> computers, string type) {
    int* ids = new int[computers.size()]();
    for(unsigned int i = 0; i < computers.size(); i++) {
        if(computers[i].getType() == type) {
            ids[i] = 1;
        }
    }
    return ids;
}

int* Search::buildYear(vector<Computer> computers, string year) {
    int* ids = new int[computers.size()]();
    for(unsigned int i = 0; i < computers.size(); i++) {
        if(computers[i].getBuildYear() == year) {
            ids[i] = 1;
        }
    }
    return ids;
}

int* Search::builtRnot(vector<Computer> computers, string built) {
    int* ids = new int[computers.size()]();
    for(unsigned int i = 0; i < computers.size(); i++) {
        if(computers[i].getBuiltRnot() == built) {
            ids[i] = 1;
        }
    }
    return ids;
}
