#include "search.h"

using namespace std;

Search::Search() {
    list<Person> persons;
}

bool Search::firstName(list<Person> persons, Person p) {
    for(list<Person>::iterator iter = persons.begin(); iter != persons.end(); ++iter) {
        if(iter->getFirstName() == p.getFirstName()) {
            return true;
        }
    }
    return false;
}
