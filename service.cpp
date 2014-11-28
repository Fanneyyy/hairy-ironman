#include "service.h"


Service::Service() {
}

Person Service::get(int id) {
    return personRepo.get(id);
}

int Service::add() {
    Person p;
    ofstream outputFile;
    outputFile.open("test.txt");
    char c;
    do {
        cin >> p;

        outputFile << p;   // add person to file
        personRepo.add(p);

        cout << "Want to add another? (y/n?) ";
        cin >> c;
    }while(c != 'N' && c != 'n');
    outputFile.close();
}

int Service::remove() {

}

void Service::setUp() {
    Person p;
    string line;
    int number;
    ifstream myfile ("test.txt");
    if(myfile.is_open()) {
        while(getline(myfile, line)) {
             p.setFirstName(line);
             getline(myfile, line);
             p.setLastName(line);
             getline(myfile, line);
             p.setGender(line);
             getline(myfile, line);
             p.setYearOfBirth(line);
             getline(myfile, line);
             p.setYearOfDeath(line);
        }
        myfile.close();
    } else {
        cout << "Sorry, no information at hand" << endl;
    }
}


