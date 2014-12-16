//#include "search.h"

//using namespace std;

//Search::Search() {
//}

//// searchALlNames: searches both input vectors for the string name, partial or whole
//// and not case sensitive.
//void Search::searchAllNames(vector<Person> persons, vector<Computer> computers, string name) {
//    int* idPerson = new int[persons.size()]();
//    string tempName = name;
//    string fullName;
//    transform(tempName.begin(), tempName.end(), tempName.begin(), ::tolower);

//    for(unsigned int i = 0; i < persons.size(); i++) {
//        fullName = persons[i].getName();
//        transform(fullName.begin(), fullName.end(), fullName.begin(), ::tolower);

//        size_t found = fullName.find(tempName);

//        if(found != string::npos) {
//            idPerson[i] = 1;
//        }
//    }

//    string computerName;
//    int* idComputer = new int[computers.size()]();

//    for(unsigned int i = 0; i < computers.size(); i++) {
//        computerName = computers[i].getComputerName();
//        transform(computerName.begin(), computerName.end(), computerName.begin(), ::tolower);
//        size_t found = computerName.find(tempName);
//        if(found != string::npos) {
//            idComputer[i] = 1;
//        }
//    }

//    bool personFound = printPersonsFromVector(persons, idPerson);
//    bool computerFound = printComputerFromVector(computers, idComputer);

//    if(!personFound && !computerFound) {
//        cout << "Sorry, nothing match your search" << endl;
//    }

//    delete [] idPerson;
//    delete [] idComputer;
//}

//// gender: search the vector persons for a person with a
//// gender equal to the string gender.
//void Search::gender(vector<Person> persons, string gender) {
//    int* idPerson = new int[persons.size()]();
//    string temp = gender;
//    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

//    for(unsigned int i = 0; i < persons.size(); i++) {
//        if(persons[i].getGender() == temp) {
//            idPerson[i] = 1;
//        }
//    }

//    bool genderFound = printPersonsFromVector(persons, idPerson);

//    if(!genderFound) {
//        cout << "Sorry, nothing match your search" << endl;
//    }

//    delete [] idPerson;
//}

//// searchAllYears: searches both vectors for a person or a computer with an instance
//// of a year equal to the string year
//void Search::searchAllYears(vector<Person> persons, vector<Computer> computers, string year) {
//    int* idPerson = new int[persons.size()]();

//    for(unsigned int i = 0; i < persons.size(); i++) {
//        if(persons[i].getYearOfBirth() == year) {
//            idPerson[i] = 1;
//        } else if(persons[i].getYearOfDeath() == year) {
//            idPerson[i] = 1;
//        }
//    }

//    int* idComputer = new int[computers.size()]();

//    for(unsigned int i = 0; i < computers.size(); i++) {
//        if(computers[i].getBuildYear() == year) {
//            idComputer[i] = 1;
//        } else if(computers[i].getBuiltRnot() == year) {
//            idComputer[i] = 1;
//        }
//    }

//    bool personFound = printPersonsFromVector(persons, idPerson);
//    bool computerFound = printComputerFromVector(computers, idComputer);

//    if(!personFound && !computerFound) {
//        cout << "Sorry, nothing match your search" << endl;
//    }

//    delete [] idPerson;
//    delete [] idComputer;
//}

//// type: searches the vector computers for a certain type
//void Search::type(vector<Computer> computers, string type) {
//    int* idComputer = new int[computers.size()]();
//    string temp;
//    string E = "Electronic";
//    string T = "Transistor";
//    string M = "Mechanical";

//    if(type == "E") {
//        temp = E;
//    } else if(type == "T") {
//        temp = T;
//    } else if(type == "M") {
//        temp = M;
//    }

//    for(unsigned int i = 0; i < computers.size(); i++) {
//        if(computers[i].getType() == temp) {
//            idComputer[i] = 1;
//        }
//    }

//    bool computerFound = printComputerFromVector(computers, idComputer);

//    if(!computerFound) {
//        cout << "Sorry, nothing match your search" << endl;
//    }

//    delete [] idComputer;
//}

//// printPersonsFromVector: prints out the persons found by search and
//// returns true if any were found but false otherwise.
//bool Search::printPersonsFromVector(vector<Person> persons, int* idPerson) {
//    bool somethingFound = false;

//    for(unsigned int i = 0; i < persons.size(); i++) {
//        if(idPerson[i] == 1) {
//            cout << persons[i];
//            somethingFound = true;
//        }
//    }
//    return somethingFound;
//}

//// printPersonsFromVector: prints out the computers found by search and
//// returns true if any were found but false otherwise.
//bool Search::printComputerFromVector(vector<Computer> computers, int* idComputer) {
//    bool somethingFound = false;

//    for(unsigned int i = 0; i < computers.size(); i++) {
//        if(idComputer[i] == 1) {
//            cout << computers[i];
//            somethingFound = true;
//        }
//    }
//    return somethingFound;
//}
