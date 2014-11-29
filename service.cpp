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


