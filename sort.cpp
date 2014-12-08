#include "sort.h"

Sort::Sort() {
}

vector<Person> Sort::sortVectorFirstName(vector<Person> persons) {
    vector<Person> sortedTemp = persons;
    sort(sortedTemp.begin(), sortedTemp.end(), sortByFirstName);
    return sortedTemp;
}

vector<Person> Sort::sortVectorLastName(vector<Person> persons) {
    vector<Person> sortedTemp = persons;
    sort(sortedTemp.begin(), sortedTemp.end(), sortByLastName);
    return sortedTemp;
}

vector<Person> Sort::sortVectorGender(vector<Person> persons) {
    vector<Person> sortedTemp = persons;
    sort(sortedTemp.begin(), sortedTemp.end(), sortByGender);
    return sortedTemp;
}

vector<Person> Sort::sortVectorBirthYear(vector<Person> persons) {
    vector<Person> sortedTemp = persons;
   sort(sortedTemp.begin(), sortedTemp.end(), sortByYearOfBirth);
    return sortedTemp;
}

vector<Person> Sort::sortVectorDeathYear(vector<Person> persons) {
    vector<Person> sortedTemp = persons;
   sort(sortedTemp.begin(), sortedTemp.end(), sortByYearOfDeath);
    return sortedTemp;
}

vector<Computer> Sort::sortVectorName(vector<Computer> computers) {
    vector<Computer> sortedTemp = computers;
    sort(sortedTemp.begin(), sortedTemp.end(), sortByName);
    return sortedTemp;
}

vector<Computer> Sort::sortVectorType(vector<Computer> computers) {
    vector<Computer> sortedTemp = computers;
    sort(sortedTemp.begin(), sortedTemp.end(), sortByType);
    return sortedTemp;
}

vector<Computer> Sort::sortVectorBuildYear(vector<Computer> computers) {
    vector<Computer> sortedTemp = computers;
    sort(sortedTemp.begin(), sortedTemp.end(), sortByBuildYear);
    return sortedTemp;
}

// helper function for sort.
bool sortByLastName(Person p1, Person p2) {
    return p1.getLastName() < p2.getLastName();
}

// helper function for sort.
bool sortByFirstName(Person p1, Person p2) {
    return p1.getFirstName() < p2.getFirstName();
}

// helper function for sort.
bool sortByGender(Person p1, Person p2) {
    return p1.getGender() < p2.getGender();
}

// helper function for sort.
bool sortByYearOfBirth(Person p1, Person p2) {
    string tempP1 = p1.getYearOfBirth();
    string tempP2 = p2.getYearOfBirth();
    int tempP1int, tempP2int;

    istringstream buffer1(tempP1);
    buffer1 >> tempP1int;
    istringstream buffer2(tempP2);
    buffer2 >> tempP2int;
    return tempP1int < tempP2int;
}

// helper function for sort.
bool sortByYearOfDeath(Person p1, Person p2) {
    if(p1.getYearOfDeath() == "-") {
        return false;
    } else if(p2.getYearOfDeath() == "-") {
        return true;
    }
    string tempP1 = p1.getYearOfDeath();
    string tempP2 = p2.getYearOfDeath();
    int tempP1int, tempP2int;

    istringstream buffer1(tempP1);
    buffer1 >> tempP1int;
    istringstream buffer2(tempP2);
    buffer2 >> tempP2int;
    return tempP1int < tempP2int;
}

// helper function for sort.
bool sortByName(Computer c1, Computer c2) {
    return c1.getComputerName() < c2.getComputerName();
}

// helper function for sort.
bool sortByType(Computer c1, Computer c2) {
    return c1.getType() < c2.getType();
}

// helper function for sort.
bool sortByBuildYear(Computer c1, Computer c2) {
    string tempP1 = c1.getBuildYear();
    string tempP2 = c2.getBuildYear();
    int tempP1int, tempP2int;

    istringstream buffer1(tempP1);
    buffer1 >> tempP1int;
    istringstream buffer2(tempP2);
    buffer2 >> tempP2int;
    return tempP1int < tempP2int;
}

// helper function for sort.
bool sortByBuiltRnot(Computer c1, Computer c2) {
    return c1.getBuiltRnot() < c2.getBuiltRnot();
}
