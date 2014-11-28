#include "consoleui.h"
#include "readperson.h"
#include "printfile.h"
#include <iostream>
#include <fstream>
#include <string>
#include "person.h"

using namespace std;

ConsoleUI::ConsoleUI() {

}

void ConsoleUI::choose(){
    readPerson rp;
    printFile wf;

    int what;
    cout << "What would you like to do? " << endl;
    cout << "1. Add person" << endl;
    cout << "2. Print from file" << endl;

    cin >> what;

    switch(what)
    {
    case 1:
        rp.read();
        break;
    case 2:
        wf.print();
        break;
    default:
        break;
    }
}
