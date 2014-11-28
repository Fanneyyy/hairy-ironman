#include "personrepository.h"

PersonRepository::PersonRepository()
{  
    personList = list<Person>();
}

void PersonRepository::add(Person a){
    personList.push_back(a);
}
