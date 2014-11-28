#ifndef PERSONREPOSITORY_H
#define PERSONREPOSITORY_H

#include <vector>
#include "Person.h"

using namespace std;

class PersonRepository
{
private:
    vector<Person> personList;
public:
    PersonRepository();
    int add(Person a);
    Person get(int id);
};

#endif // PERSONREPOSITORY_H
