// PersonRepository: Stores persons in vector, relays information and handles additions and deletions.

#ifndef PERSONREPOSITORY_H
#define PERSONREPOSITORY_H

#include <vector>
#include "Person.h"

using namespace std;

class PersonRepository
{
private:
    vector<Person> personList;
public:
    PersonRepository();
    void add(Person a);
    Person get(int id);
    int getSize();
    vector<Person> getAll();
    void removePerson(int id);
};

#endif // PERSONREPOSITORY_H
