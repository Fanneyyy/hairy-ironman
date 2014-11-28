#include "consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI() {

}

void ConsoleUI::choose(){
    s.setUp();
    int what;
    do{
        cout << "What would you like to do? " << endl;
        cout << "1. Add person" << endl;
        cout << "2. Print list" << endl;
        cout << "3. Search list" << endl;
        cout << "4. Sort list" << endl;
        cout << "0. Exit" << endl;

        cin >> what;

        switch(what)
        {
            case 1:
                s.add();
                break;
            case 2:
                printUI();
                break;
            case 3:
                searchUI();
                break;
            case 0:
                return;
                break;
            default:
                break;
        }
    }while(what != 0);
}

void ConsoleUI::searchUI() {
    int input;
    cout << "How would you like to search?" << endl;
    cout << "1. Search for first name" << endl;
    cout << "More later" << endl;
    cin >> input;

    switch(input) {
        case 1:
            break;
        case 2:
            break;
        default:
            break;
    }
}

void ConsoleUI::printUI() {
    // Sort s;
    int input;
    cout << "In what order would you like the list?" << endl;
    cout << "1. By input order" << endl;
    cout << "2. By first name" << endl;
    cout << "More later" << endl;
    cin >> input;

    switch(input) {
        case 1:
            break;
        case 2:
            break;
        default:
            break;
    }
}
