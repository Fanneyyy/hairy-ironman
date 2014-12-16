// Service: Takes commands from the user interface, seeks information from the repository
// and relays the appropriate information back to the user interface.

#ifndef PERSONSSERVICE_H
#define PERSONSSERVICE_H

#include <string>
#include <vector>
#include <limits>
#include <cstring>
#include "PersonsRepository.h"

class PersonsService {
public:
    PersonsService();
    Person get(int id);
    void add(Person p);
    int getSizeOfRepo();
    vector<Person> getAll();
    void setUp();
    void removeAll();
    void remove(int personID, string ID);
    int findPosition(int ID);
    bool validPersonID(vector<Person> persons, int ID);
private:
    PersonsRepository personRepo;
};

#endif // PERSONSSERVICE_H
