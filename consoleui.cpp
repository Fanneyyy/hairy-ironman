#include "consoleui.h"
#include <iostream>
#include <fstream>
#include <string>
#include "person.h"

using namespace std;

ConsoleUI::ConsoleUI() {

}

void ConsoleUI::start() {
    Person p1;
    string line;
    ofstream outputFile;
    outputFile.open("test.txt");
    char c;



    do
    {
    cout << "Klasa Test a Person." << endl;
    cin >> p1;

    // add person to file

    outputFile << p1;

    // add person to file

    cout << "Og þetta er það sem prentast:" << endl;
    cout << p1;
    cout << "Ready to add another? (y/n?) ";
    cin >> c;
    }while(c != 'N' && c != 'n');

    cout << "Nuna prentum við ur filenum" << endl;
    ifstream myfile ("test.txt");
    while (getline (myfile, line))
    {
        cout << line << endl;
    }
    outputFile.close();
    myfile.close();
}
