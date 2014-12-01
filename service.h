#ifndef SERVICE_H
#define SERVICE_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "person.h"
#include "search.h"
#include "personrepository.h"

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
private:
    Search s;
    PersonRepository personRepo;
};

#endif // SERVICE_H
