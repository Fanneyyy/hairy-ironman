#include "search.h"

using namespace std;

Search::Search() {
}

int Search::firstName(vector<Person> persons, string firstName) {
    for(unsigned int i = 0; i < persons.size(); i++) {
        if(persons[i].getFirstName() == firstName) {
            return i;
        }
    }
    return 0;
}

Person Search::returnFirstName(vector<Person> persons, string firstName) {

    for(unsigned int i = 0; i < persons.size(); i++) {
        if(persons[i].getFirstName() == firstName) {
            return persons[i];
        }
    }
}
