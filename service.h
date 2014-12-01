#ifndef SERVICE_H
#define SERVICE_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include "search.h"
#include "personrepository.h"
#include "sort.h"

class Service
{
public:
    Service();
    Person get(int id);
    void add();
    void setUp();
    void printAll();
    void printOne(int id);
    void searchAll(int theCase, string name);
    void printAllWithNumber();
    void removeFromFile(int id);
    void clearAndPrintFile();
    void sortAll(int theCase);
    bool UIinputCheck(int input, int maxcases);
private:
    Search searcher;
    Sort sorter;
    PersonRepository personRepo;
};

#endif // SERVICE_H
