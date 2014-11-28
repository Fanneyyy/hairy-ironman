#ifndef PERSONREPOSITORY_H
#define PERSONREPOSITORY_H

#include <list>
#include "Person.h"

using namespace std;

class PersonRepository
{
private:
    vector<Person> personVector;
public:
    PersonRepository();
};

#endif // PERSONREPOSITORY_H
