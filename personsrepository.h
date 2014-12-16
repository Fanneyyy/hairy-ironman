// Repository: Stores in a vector instances of persons, handles add and relays information
// about the repository

#ifndef PERSONSREPOSITORY_H
#define PERSONSREPOSITORY_H

#include <vector>
#include <string>
#include <QString>
#include <QtSql>
#include <QtDebug>
#include "Person.h"

using namespace std;

class PersonsRepository {
public:
    PersonsRepository();
    void add(Person p);
    Person getPerson(int id);
    vector<Person> getAllPerson();
    int getPersonSize();
    void emptyRepo();
    void setUp();
    string getPersonID();
    void savePersonToDatabase(Person p);
    QSqlDatabase getDatabaseConnection();
    void addPersonToVectorAndDatabase(Person p);
private:
    vector<Person> personList;
    QSqlDatabase db;
};

#endif // PERSONSREPOSITORY_H
