#include "consoleui.h"
#include <iostream>
#include "person.h"

using namespace std;

ConsoleUI::ConsoleUI() {

}

void ConsoleUI::start() {
    cout << "Klasa Test a Person." << endl;
    Person p1;
    cin >> p1;
    cout << "Og þetta er það sem prentast:" << endl;
    cout << p1;
}
