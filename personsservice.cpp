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

// runs setup for the initialization of a vector filled from the database.
void PersonsService::setUp() {
    personRepo.setUp();
}

void PersonsService::remove(int personID, string ID) {
    personRepo.remove(findPosition(personID));
    personRepo.removeFromDatabase(ID);
}

void PersonsService::removeAll() {
    personRepo.emptyRepo();
}

bool PersonsService::validPersonID(vector<Person> persons, int ID) {
    for(unsigned int i = 0; i < persons.size(); i++) {
        if(persons[i].getID() == ID) {
            return true;
        }
    }
    return false;
}

int PersonsService::findPosition(int ID) {
    int temp;
    for(int i = 0; i < personRepo.getPersonSize(); i++) {
        if(personRepo.getPerson(i).getID() == ID) {
            temp = i;
        }
    }
    return temp;
}
