#include "sort.h"

Sort::Sort() {
}

vector<Person> Sort::sortVector(vector<Person> persons, int theCase) {
    vector<Person> sortedTemp = persons;
    switch(theCase) {
        case 1:
            sort(sortedTemp.begin(), sortedTemp.end(), sortByLastName);
            break;
        case 2:
            sort(sortedTemp.begin(), sortedTemp.end(), sortByFirstName);
            break;
        case 3:
            sort(sortedTemp.begin(), sortedTemp.end(), sortByGender);
            break;
        case 4:
            sort(sortedTemp.begin(), sortedTemp.end(), sortByYearOfBirth);
            break;
        case 5:
            sort(sortedTemp.begin(), sortedTemp.end(), sortByYearOfDeath);
            break;
        default:
            break;
    }
    return sortedTemp;
}
bool sortByFirstName(Person p1, Person p2) {
    return p1.getLastName() < p2.getLastName();
}
bool sortByLastName(Person p1, Person p2) {
    return p1.getFirstName() < p2.getFirstName();
}
bool sortByGender(Person p1, Person p2) {
    return p1.getGender() < p2.getGender();
}
bool sortByYearOfBirth(Person p1, Person p2) {
    return p1.getYearOfBirth() < p2.getYearOfBirth();
}
bool sortByYearOfDeath(Person p1, Person p2) {
    return p1.getYearOfDeath() < p2.getYearOfDeath();
}
