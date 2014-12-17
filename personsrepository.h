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
    Person getPerson(int id);
    vector<Person> getAllPerson();
    void add(Person p);
    void emptyRepo();
    void setUp();
    void addPersonToVectorAndDatabase(Person p);
    void remove(int id);
    void removeFromDatabase(string ID);
    void savePersonToDatabase(Person p);
    int getPersonSize();
    string getPersonID();
    QSqlDatabase getDatabaseConnection();
private:
    vector<Person> personList;
    QSqlDatabase db;
};

#endif // PERSONSREPOSITORY_H
