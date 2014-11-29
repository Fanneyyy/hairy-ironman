#include "personrepository.h"

PersonRepository::PersonRepository() {
    personList = vector<Person>();
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
