#include "readperson.h"
#include <fstream>
#include <string>
#include "person.h"

readPerson::readPerson()
{
}
void readPerson::read() {
    Person p1;
    ofstream outputFile;
    outputFile.open("test.txt");
    char c;
    do
    {
    cout << "Klasa Test a Person." << endl;
    cin >> p1;


    outputFile << p1;   // add person to file


    cout << "Og þetta er það sem prentast:" << endl;
    cout << p1;


    cout << "Ready to add another? (y/n?) ";
    cin >> c;
    }while(c != 'N' && c != 'n');
    outputFile.close();
}
