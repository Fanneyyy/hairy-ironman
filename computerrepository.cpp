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

void ComputerRepository::emptyRepo() {
    computerList = vector<Computer>();
}
