#ifndef SORT_H
#define SORT_H
#include <iostream>
#include <algorithm>
#include <vector>
#include "person.h"

using namespace std;

class Sort
{
public:
    Sort();
    vector<Person> sortVector(vector<Person> persons, int theCase);
};
    bool sortByFirstName(Person p1, Person p2);

#endif // SORT_H
