#include "personsservice.h"

PersonsService::PersonsService() {
}

// get: returns the person with the id within the vector
// (not necessarily the same as the database id)
Person PersonsService::get(int id) {
    return personRepo.getPerson(id);
}

vector<Person> PersonsService::getAll() {
    return personRepo.getAllPerson();
}

int PersonsService::getSizeOfRepo() {
    return personRepo.getPersonSize();
}

// add(): adds a person to the personRepo database and to the sqlite database.
void PersonsService::add(Person p) {
    personRepo.addPersonToVectorAndDatabase(p);
}

void PersonsService::setUp() {
    personRepo.setUp();
}
