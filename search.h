#ifndef SEARCH_H
#define SEARCH_H
#include "person.h"
#include <iostream>
#include <list>

class Search
{
public:
    Search();
    bool firstName(list<Person> persons, Person p);
};

#endif // SEARCH_H
