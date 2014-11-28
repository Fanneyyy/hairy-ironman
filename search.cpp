#include "search.h"

using namespace std;

Search::Search() {
}

bool Search::firstName(list<Person> persons, string firstName) {
    for(list<Person>::iterator iter = persons.begin(); iter != persons.end(); ++iter) {
        if(iter->getFirstName() == firstName) {
            return true;
        }
    }
    return false;
}

Person Search::returnFirstName(list<Person> persons, string firstName) {
    for(list<Person>::iterator iter = persons.begin(); iter != persons.end(); ++iter) {
        if(iter->getFirstName() == firstName) {
            return *iter;
        }
    }
}
