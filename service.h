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
    void remove();
    void setUp();
    void printAll();
    void printOne(int id);
    void searchAll(string firstName);
private:
    Search s;
    PersonRepository personRepo;
};

#endif // SERVICE_H
