#ifndef SEARCH_H
#define SEARCH_H
#include "person.h"
#include <iostream>
#include <vector>

class Search
{
public:
    Search();
    int* name(vector<Person> persons, string name);
    int* gender(vector<Person> persons, string gender);
    int *year(vector<Person> persons, string year);
};

#endif // SEARCH_H
