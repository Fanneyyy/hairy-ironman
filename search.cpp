#include "search.h"

using namespace std;

Search::Search() {
}

int* Search::name(vector<Person> persons, string name) {
    int* ids = new int[persons.size()]();
    for(unsigned int i = 0; i < persons.size(); i++) {
        if(persons[i].getFirstName() == name || persons[i].getLastName() == name) {
            ids[i] = 1;
        }
    }
    return ids;
}

int* Search::gender(vector<Person> persons, string gender) {
    int* ids = new int[persons.size()]();
    for(unsigned int i = 0; i < persons.size(); i++) {
        if(persons[i].getGender() == gender) {
            ids[i] = 1;
        }
    }
    return ids;
}

int* Search::year(vector<Person> persons, string year) {
    int* ids = new int[persons.size()]();
    for(unsigned int i = 0; i < persons.size(); i++) {
        if(persons[i].getYearOfBirth() == year || persons[i].getYearOfDeath() == year) {
            ids[i] = 1;
        }
    }
    return ids;
}
