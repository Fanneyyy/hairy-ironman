#include "personrepository.h"

PersonRepository::PersonRepository() {
    personList = vector<Person>();
}

vector<Person> PersonRepository::getAll() {
    return personList;
}

void PersonRepository::add(Person a){
    personList.push_back(a);
}

Person PersonRepository::get(int id){
    return personList[id];
}

int PersonRepository::getSize() {
    return personList.size();
}

void PersonRepository::removePerson(int id) {
    personList.erase(personList.begin()+id);
}
