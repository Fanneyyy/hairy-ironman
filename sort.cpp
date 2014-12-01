#include "sort.h"

Sort::Sort() {
}

vector<Person> Sort::sortVector(vector<Person> persons, int theCase) {
    vector<Person> sortedTemp = persons;
    switch(theCase) {
        case 1:
            sort(sortedTemp.begin(), sortedTemp.end(), sortByFirstName);
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            break;
    }
    return sortedTemp;
}
bool sortByFirstName(Person p1, Person p2) {
    return p1.getFirstName() > p2.getFirstName();
}
