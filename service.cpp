#include "service.h"


Service::Service()
{
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


