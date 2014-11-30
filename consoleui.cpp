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
        cout << "4. Remove a person" << endl;
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
            case 4:
                removeUI();
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
    string search;
    cout << "How would you like to search?" << endl;
    cout << "1. Search for a first or a last name" << endl;
    cout << "2. Search for gender" << endl;
    cout << "3. Search for a year of birth or of death" << endl;
    cin >> input;

    switch(input) {
        case 1:
            cout << "Please enter the name: ";
            cin >> search;
            s.searchAll(1, search);
            break;
        case 2:
            cout << "Please enter f for female og m for male: ";
            cin >> search;
            s.searchAll(2, search);
            break;
        case 3:
            cout << "Please enter a year: ";
            cin >> search;
            s.searchAll(3, search);
            break;
        default:
            break;
    }
}

void ConsoleUI::printUI() {
    int input;
    cout << "In what order would you like the list?" << endl;
    cout << "1. By input order" << endl;
    cout << "2. By first name" << endl;
    cout << "More later" << endl;
    cin >> input;

    switch(input) {
        case 1:
            s.printAll();
            break;
        case 2:
            break;
        default:
            break;
    }
}

void ConsoleUI::removeUI() {
    int input;
    s.printAllWithNumber();
    cout << "Please enter the number of the person you wish to remove" << endl;
    cin >> input;
    cout << "This person has been removed:" << endl;
    s.printOne(input-1);
    s.removeFromFile(input-1);
}
