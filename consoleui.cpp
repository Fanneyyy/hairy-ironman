#include "consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI() {

}

void ConsoleUI::choose(){
    s.setUp();
    int what;
    string line;
    ifstream inFile ("choose-ui.txt");


    do{
        if(inFile.is_open()) {
            while(getline(inFile, line)) {
                cout << line << endl;
            }
        }
            inFile.close();
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
                s.clearAndPrintFile();
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
    string line;
    ifstream inFile ("print-ui.txt");

    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
    }
        inFile.close();
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
