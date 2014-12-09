#ifndef PERSONSREPOSITORY_H
#define PERSONSREPOSITORY_H

#include <vector>
#include "Person.h"
#include "Computer.h"
#include <string>
#include <QtSql>
#include <vector>
#include <QtDebug>
#include <iomanip>

using namespace std;

class PersonsRepository
{
public:
    PersonsRepository();
    void add(Person a);
    Person getPerson(int id);
    vector<Person> getAllPerson();
    int getPersonSize();
private:
    vector<Person> personList;
};

#endif // PERSONSREPOSITORY_H
