#include "personsrepository.h"

PersonsRepository::PersonsRepository() {
    personList = vector<Person>();
}

// getAll(): returns the complete vector personList
vector<Person> PersonsRepository::getAllPerson() {
    return personList;
}

// add(Person a): adds the Person a to the vector personList.
void PersonsRepository::add(Person a){
    personList.push_back(a);
}

// get(int id): returns the Person with the appropriate id.
Person PersonsRepository::getPerson(int id){
    return personList[id];
}

// getSize(): returns the size of the vector personList.
int PersonsRepository::getPersonSize() {
    return personList.size();
}

void PersonsRepository::emptyRepo() {
    personList = vector<Person>();
}
