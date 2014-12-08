// Search: Implements sort for strings in a vector filled with persons.

#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
#include "person.h"
#include "computer.h"

using namespace std;

class Sort
{
public:
    Sort();
    vector<Person> sortVectorFirstName(vector<Person> persons);
    vector<Person> sortVectorLastName(vector<Person> persons);
    vector<Person> sortVectorGender(vector<Person> persons);
    vector<Person> sortVectorBirthYear(vector<Person> persons);
    vector<Person> sortVectorDeathYear(vector<Person> persons);
    vector<Computer> sortVectorName(vector<Computer> computers);
    vector<Computer> sortVectorType(vector<Computer> computers);
    vector<Computer> sortVectorBuildYear(vector<Computer> computers);
};
    bool sortByFirstName(Person p1, Person p2);
    bool sortByLastName(Person p1, Person p2);
    bool sortByGender(Person p1, Person p2);
    bool sortByYearOfBirth(Person p1, Person p2);
    bool sortByYearOfDeath(Person p1, Person p2);
    bool sortByName(Computer c1, Computer c2);
    bool sortByType(Computer c1, Computer c2);
    bool sortByBuildYear(Computer c1, Computer c2);
    bool sortByBuiltRnot(Computer c1, Computer c2);

#endif // SORT_H
