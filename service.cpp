#include "service.h"


Service::Service() {
}

Person Service::get(int id) {
    return personRepo.get(id);
}

void Service::add() {
    Person p;
    char c;
    do {
        cin >> p;
        personRepo.add(p);
        cout << "Want to add another? (y/n?) ";
        cin >> c;
    } while(c != 'N' && c != 'n');
}

void Service::printAll() {
    for(int i = 0; i < personRepo.getSize(); i++) {
        personRepo.get(i).print();
    }
}

void Service::printAllWithNumber() {
    for(int i = 0; i < personRepo.getSize(); i++) {
        cout << "Person number: " << i+1 << endl;
        personRepo.get(i).print();
    }
}

void Service::printOne(int id) {
    personRepo.get(id).print();
}

void Service::searchAll(int theCase, string search) {
    int* ids = new int[personRepo.getSize()];
    switch(theCase) {
        case 1: {
            ids = s.name(personRepo.getAll(),search);
            break;
        }
        case 2: {
            ids = s.gender(personRepo.getAll(),search);
            break;
        }
        case 3: {
            ids = s.year(personRepo.getAll(),search);
            break;
        }
        default:
            break;
    }
    for(int i = 0; i < personRepo.getSize(); i++) {
        if(ids[i] == 1) {
            personRepo.get(i).print();
        }
    }
    delete [] ids;
}

void Service::removeFromFile(int id) {
    personRepo.removePerson(id);
    remove("test.txt");
    ofstream outFile("test.txt");

    if(outFile.is_open()) {
        for(int i = 0; i < personRepo.getSize(); i++) {
            outFile << personRepo.get(i);
        }
    }

    outFile.close();
}

void Service::clearAndPrintFile() {
    remove("test.txt");
    ofstream outFile("test.txt");
    if(outFile.is_open()) {
        for(int i = 0; i < personRepo.getSize(); i++) {
            outFile << personRepo.get(i);
        }
    }
    outFile.close();
}

void Service::setUp() {
    Person p;
    string line;
    ifstream inFile ("test.txt");

    //addar Persónunni úr filenum í vectorinn
    if(inFile.is_open()) {
        while(getline(inFile, line)) {
             p.setFirstName(line);
             getline(inFile, line);
             p.setLastName(line);
             getline(inFile, line);
             p.setGender(line);
             getline(inFile, line);
             p.setYearOfBirth(line);
             getline(inFile, line);
             p.setYearOfDeath(line);
             personRepo.add(p);
        }
        inFile.close();
    } else {
        cout << "Sorry, no information at hand" << endl;
    }
    //addar Persónunni svo aftur í file'inn (commentað út því þetta olli einhverjum errorum)
//    ofstream outFile("test.txt");

//    if(outFile.is_open()) {
//        outFile << p;
//    }
//    outFile.close();
}

bool Service::UIinputCheck(int input, int maxcases) {


    if(input < 0 || input > maxcases) {
        cout << "Wrong input, please try again" << endl;
        return false;
    }
    return true;

}


