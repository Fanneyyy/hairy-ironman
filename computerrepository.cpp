#include "computerrepository.h"

ComputerRepository::ComputerRepository() {
    computerList = vector<Computer>();
}

// getAll(): returns the complete vector computerList
vector<Computer> ComputerRepository::getAllComputer() {
    return computerList;
}

// add(Computer c): adds the Computer c to the vector computerList.
void ComputerRepository::add(Computer c){
    computerList.push_back(c);
}

// get(int id): returns the Computer with the appropriate id.
Computer ComputerRepository::getComputer(int id){
    return computerList[id];
}

// getSize(): returns the size of the vector computerList.
int ComputerRepository::getComputerSize() {
    return computerList.size();
}

// removePerson(int id): removes the Computer with the id
// from the vector computerList.
void ComputerRepository::removeComputer(int id) {
    computerList.erase(computerList.begin()+id);
}

void ComputerRepository::headerComputerPrint() {

}

// sortVector: sorts a vector filled with persons depending on theCase.
vector<Computer> ComputerRepository::sortVector(vector<Computer> computers, int theCase) {
    vector<Computer> sortedTemp = computers;
    switch(theCase) {
        case 2:
            sort(sortedTemp.begin(), sortedTemp.end(), sortByName);
            break;
        case 3:
            sort(sortedTemp.begin(), sortedTemp.end(), sortByType);
            break;
        case 4:
            sort(sortedTemp.begin(), sortedTemp.end(), sortByBuildYear);
            break;
        case 5:
            sort(sortedTemp.begin(), sortedTemp.end(), sortByBuiltRnot);
            break;
        default:
            break;
    }
    return sortedTemp;
}

// helper function for sort.
bool sortByName(Computer c1, Computer c2) {
    return c1.getComputerName() < c2.getComputerName();
}

// helper function for sort.
bool sortByType(Computer c1, Computer c2) {
    return c1.getType() < c2.getType();
}

// helper function for sort.
bool sortByBuildYear(Computer c1, Computer c2) {
    string tempP1 = c1.getBuildYear();
    string tempP2 = c2.getBuildYear();
    int tempP1int, tempP2int;

    istringstream buffer1(tempP1);
    buffer1 >> tempP1int;
    istringstream buffer2(tempP2);
    buffer2 >> tempP2int;
    return tempP1int < tempP2int;
}

// helper function for sort.
bool sortByBuiltRnot(Computer c1, Computer c2) {
    return c1.getBuiltRnot() < c2.getBuiltRnot();
}
