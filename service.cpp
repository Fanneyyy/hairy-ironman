#include "service.h"


Service::Service() {
}

Person Service::get(int id) {
    return personRepo.get(id);
}

void Service::add() {
    Person p;
    char c;
    ofstream outFile("test.txt");
    do {
        cin >> p;
        personRepo.add(p);
        if(outFile.is_open()) {
            outFile << p;
            cout << "Want to add another? (y/n?) ";
        }
        cin >> c;
    } while(c != 'N' && c != 'n');
    outFile.close();

//    ofstream outFile("test.txt");
//    if(outFile.is_open()) {
//        do {
//            cin >> p;
//            outFile << p;
//            personRepo.add(p);
//            cout << "Want to add another? (y/n?) ";
//            cin >> c;
//        } while(c != 'N' && c != 'n');
//        outFile.close();
//    }
}

void Service::printAll() {
    for(int i = 0; i < personRepo.getSize(); i++) {
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
        if(ids[i] != 0) {
            personRepo.get(ids[i]).print();
        }
    }
}

void Service::remove() {

}

void Service::setUp() {
    Person p;
    string line;
    ifstream inFile ("test.txt");
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
}


