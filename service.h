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
    int add();
    int remove();
    void setUp();
private:
    Search s;
    PersonRepository personRepo;
};

#endif // SERVICE_H
