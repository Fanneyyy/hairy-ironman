// Search: Implements a search for a string in a vector filled with persons.

#ifndef SEARCH_H
#define SEARCH_H
#include "person.h"
#include <iostream>
#include <vector>

class Search
{
public:
    Search();
    int* gender(vector<Person> persons, string gender);
    int *nameFirst(vector<Person> persons, string name);
    int *nameLast(vector<Person> persons, string name);
    int *birthYear(vector<Person> persons, string year);
    int *deathYear(vector<Person> persons, string year);
};

#endif // SEARCH_H
