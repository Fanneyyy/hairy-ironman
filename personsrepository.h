// Repository: Stores in a vector instances of persons, handles add and relays information
// about the repository

#ifndef PERSONSREPOSITORY_H
#define PERSONSREPOSITORY_H

#include <vector>
#include <string>
#include "Person.h"
#include "Computer.h"

using namespace std;

class PersonsRepository {
public:
    PersonsRepository();
    void add(Person a);
    Person getPerson(int id);
    vector<Person> getAllPerson();
    int getPersonSize();
    void emptyRepo();
private:
    vector<Person> personList;
};

#endif // PERSONSREPOSITORY_H
