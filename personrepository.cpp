#include "personrepository.h"

PersonRepository::PersonRepository()
{  
    personList = list<Person>();
}

int PersonRepository::add(Person a){
    personList.push_back(a);
}
