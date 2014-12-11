// Repository: Stores in a vector instances of computers, handles add and relays information
// about the repository

#ifndef COMPUTERREPOSITORY_H
#define COMPUTERREPOSITORY_H

#include <vector>
#include <string>
#include "Person.h"
#include "Computer.h"

using namespace std;

class ComputerRepository {
public:
    ComputerRepository();
    void add(Computer c);
    Computer getComputer(int id);
    vector<Computer> getAllComputer();
    int getComputerSize();
private:
    vector<Computer> computerList;
};

#endif // COMPUTERREPOSITORY_H
