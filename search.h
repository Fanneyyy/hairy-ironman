#ifndef SEARCH_H
#define SEARCH_H
#include "person.h"
#include <iostream>
#include <vector>

class Search
{
public:
    Search();
    bool firstName(vector<Person> persons, string firstName);
    Person returnFirstName(vector<Person> persons, string firstName);
};

#endif // SEARCH_H
