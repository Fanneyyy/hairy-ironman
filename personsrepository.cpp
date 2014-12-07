#include "personsrepository.h"

PersonsRepository::PersonsRepository() {
    personList = vector<Person>();
}

// getAll(): returns the complete vector personList
vector<Person> PersonsRepository::getAllPerson() {
    return personList;
}

// add(Person a): adds the Person a to the vector personList.
void PersonsRepository::add(Person a){
    personList.push_back(a);
}

// get(int id): returns the Person with the appropriate id.
Person PersonsRepository::getPerson(int id){
    return personList[id];
}

// getSize(): returns the size of the vector personList.
int PersonsRepository::getPersonSize() {
    return personList.size();
}

// removePerson(int id): removes the Person with the id
// from the vector personList.
void PersonsRepository::removePerson(int id) {
    personList.erase(personList.begin()+id);
}

void PersonsRepository::headerPersonsPrint() {
    cout << fixed;
    cout << setw(3) << "Name: " << setw(15) << "Gender" << setw(15) << "Year of birth" << setw(15) << "Year of death" << endl;
    cout << "----------------------------------------------------------------" << endl;
}
