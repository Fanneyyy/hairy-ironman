#ifndef PERSONREPOSITORY_H
#define PERSONREPOSITORY_H

#include <list>
#include "Person.h"

using namespace std;

class PersonRepository
{
private:
    list<Person> personList;
public:
    PersonRepository();
    void add(Person a);
};

#endif // PERSONREPOSITORY_H
