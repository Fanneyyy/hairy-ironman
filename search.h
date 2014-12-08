// Search: Implements a search for a string in a vector filled with persons.

#ifndef SEARCH_H
#define SEARCH_H
#include "person.h"
#include "computer.h"
#include <iostream>
#include <algorithm>
#include <vector>

class Search
{
public:
    Search();
    int* gender(vector<Person> persons, string gender);
    int *personName(vector<Person> persons, string name);
    int *birthYear(vector<Person> persons, string year);
    int *deathYear(vector<Person> persons, string year);
    int *computerName(vector<Computer> computers, string name);
    int *type(vector<Computer> computers, string type);
    int *buildYear(vector<Computer> computers, string year);
    int *builtRnot(vector<Computer> computers, string built);
};

#endif // SEARCH_H
