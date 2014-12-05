// repository: Stores persons and computers in vector, relays information and handles additions and deletions.

#ifndef repository_H
#define repository_H

#include <vector>
#include "Person.h"
#include "Computer.h"

using namespace std;

class repository
{
private:
    vector<Person> personList;
    vector<Computer> computerList;
public:
    repository();
    void add(Person a);
    Person getPerson(int id);
    vector<Person> getAllPerson();
    int getPersonSize();
    void removePerson(int id);

    void add(Computer c);
    Computer getComputer(int id);
    vector<Computer> getAllComputer();
    int getCPUSize();
    void removeComputer(int id);
};

#endif // repository_H
