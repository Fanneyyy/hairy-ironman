// Search: Implements a search for a string in a vector filled with persons or computers.

#ifndef SEARCH_H
#define SEARCH_H
#include "person.h"
#include "computer.h"
#include <algorithm>
#include <vector>

class Search {
public:
    Search();
    void gender(vector<Person> persons, string gender);
    void type(vector<Computer> computers, string type);
    void searchAllNames(vector<Person> persons, vector<Computer> computers, string name);
    bool printPersonsFromVector(vector<Person> persons, int *idPerson);
    bool printComputerFromVector(vector<Computer> computers, int *idComputer);
    void searchAllYears(vector<Person> persons, vector<Computer> computers, string year);
};

#endif // SEARCH_H
