#include "personrepository.h"

PersonRepository::PersonRepository() {
    personList = vector<Person>();
}
// getAll(): returns the complete vector personList
vector<Person> PersonRepository::getAll() {
    return personList;
}
// add(Person a): adds the Person a to the vector personList.
void PersonRepository::add(Person a){
    personList.push_back(a);
}
// get(int id): returns the Person with the appropriate id.
Person PersonRepository::get(int id){
    return personList[id];
}
// getSize(): returns the size of the vector personList.
int PersonRepository::getSize() {
    return personList.size();
}
// removePerson(int id): removes the Person with the id
// from the vector personList.
void PersonRepository::removePerson(int id) {
    personList.erase(personList.begin()+id);
}
