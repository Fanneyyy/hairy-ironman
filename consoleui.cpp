#include "consoleui.h"
#include <iostream>
#include "person.h"

using namespace std;

ConsoleUI::ConsoleUI() {

}

void ConsoleUI::start() {
    Person p1;
    char c;

    do
    {
    cout << "Klasa Test a Person." << endl;
    cin >> p1;

    // add person to file

    cout << "Og þetta er það sem prentast:" << endl;
    cout << p1;
    cout << "Ready to add another? (y/n?) ";
    cin >> c;
    }while(c != 'N' && c != 'n');
}
