#include "repository.h"

repository::repository() {
    personList = vector<Person>();
}
// getAll(): returns the complete vector personList
vector<Person> repository::getAll() {
    return personList;
}
// add(Person a): adds the Person a to the vector personList.
void repository::add(Person a){
    personList.push_back(a);
}
// get(int id): returns the Person with the appropriate id.
Person repository::get(int id){
    return personList[id];
}
// getSize(): returns the size of the vector personList.
int repository::getSize() {
    return personList.size();
}
// removePerson(int id): removes the Person with the id
// from the vector personList.
void repository::removePerson(int id) {
    personList.erase(personList.begin()+id);

    computerList = vector<Computer>();
}
// getAll(): returns the complete vector personList
vector<Computer> repository::getAll() {
    return computerList;
}
// add(Computer c): adds the Computer c to the vector computerList.
void repository::add(Computer c){
    computerList.push_back(c);
}
// get(int id): returns the Computer with the appropriate id.
Computer repository::get(int id){
    return computerList[id];
}
// getSize(): returns the size of the vector computerList.
int repository::getSize() {
    return computerList.size();
}
// removePerson(int id): removes the Computer with the id
// from the vector computerList.
void repository::removeComputer(int id) {
    computerList.erase(computerList.begin()+id);
}
