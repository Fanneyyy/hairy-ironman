#include "sort.h"

Sort::Sort() {
}
// sortVector: sorts a vector filled with persons depending on theCase.
vector<Person> Sort::sortVector(vector<Person> persons, int theCase) {
    vector<Person> sortedTemp = persons;
    switch(theCase) {
        case 2:
            sort(sortedTemp.begin(), sortedTemp.end(), sortByLastName);
            break;
        case 3:
            sort(sortedTemp.begin(), sortedTemp.end(), sortByFirstName);
            break;
        case 4:
            sort(sortedTemp.begin(), sortedTemp.end(), sortByGender);
            break;
        case 5:
            sort(sortedTemp.begin(), sortedTemp.end(), sortByYearOfBirth);
            break;
        case 6:
            sort(sortedTemp.begin(), sortedTemp.end(), sortByYearOfDeath);
            break;
        default:
            break;
    }
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
    string tempP1 = p1.getYearOfBirth();
    string tempP2 = p2.getYearOfBirth();
    int tempP1int, tempP2int;

    istringstream buffer1(tempP1);
    buffer1 >> tempP1int;
    istringstream buffer2(tempP2);
    buffer2 >> tempP2int;
    return tempP1int < tempP2int;
}
