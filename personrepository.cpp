#include "personrepository.h"

PersonRepository::PersonRepository()
{  
    personList = vector<Person>();
}

int PersonRepository::add(Person a){
    personList.push_back(a);
}

Person PersonRepository::get(int id){
    personList[id];
}
