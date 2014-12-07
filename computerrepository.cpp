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
int ComputerRepository::getCPUSize() {
    return computerList.size();
}

// removePerson(int id): removes the Computer with the id
// from the vector computerList.
void ComputerRepository::removeComputer(int id) {
    computerList.erase(computerList.begin()+id);
}

void ComputerRepository::headerComputerPrint() {
    cout << fixed;
    cout << setw(3) << "Name: " << setw(15) << "Type:" << setw(15) << "Build year" << setw(15) << "Built?" << endl;
    cout << "----------------------------------------------------------------" << endl;
}
