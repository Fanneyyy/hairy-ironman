#include "computersservice.h"

ComputersService::ComputersService() {
}

// get: returns the computer with the id within the vector
// (not necessarily the same as the database id)
Computer ComputersService::get(int id) {
    return computerRepo.getComputer(id);
}

// add(): adds a computer to the computerRepo database.
void ComputersService::add(Computer c) {
    computerRepo.add(c);
    computerRepo.addComputerToVectorAndDatabase(c);
}

// runs setup for the initialization of a vector filled from the database.
void ComputersService::setUp() {
    computerRepo.setUp();
}

vector<Computer> ComputersService::getAll() {
    return computerRepo.getAllComputer();
}

int ComputersService::getSizeOfRepo() {
    return computerRepo.getComputerSize();
}

void ComputersService::removeAll() {
    computerRepo.emptyRepo();
}
