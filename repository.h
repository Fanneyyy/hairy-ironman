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
    Person get(int id);
    int getSize();
    vector<Person> getAll();
    void removePerson(int id);

    void add(Computer c);
    Computer get(int id);
    vector<Computer> getAll();
    void removeComputer(int id);
};

#endif // repository_H
