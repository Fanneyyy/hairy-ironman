#include "readperson.h"
#include <fstream>
#include <iostream>
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

    cin >> p1;

    outputFile << p1;   // add person to file

    cout << "Ready to add another? (y/n?) ";
    cin >> c;
    }while(c != 'N' && c != 'n');
    outputFile.close();
}
