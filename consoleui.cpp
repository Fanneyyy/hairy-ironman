#include "consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI() {
}

void ConsoleUI::initialSetUp() {
    string line;
    ifstream inFile ("welcome.txt");

    s.setUp();
    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
    }
    inFile.close();
    cont();
    clear_screen();
}

void ConsoleUI::choose(){
    int what;
    string line;
    clear_screen();

    do{
        ifstream inFile ("choose-ui.txt");
        if(inFile.is_open()) {
            while(getline(inFile, line)) {
                cout << line << endl;
            }
        }
            inFile.close();
        do{
        cin >> what;
            }while(!s.UIinputCheck(what, 4));

        switch(what)
        {
            case 1:
                addUI();
                s.add();
                clear_screen();
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
                exit(0);
                break;
            default:
                break;
        }

    }while(what != 0);
    clear_screen();
}

void ConsoleUI::addUI() {
    string line;
    ifstream inFile ("add-ui.txt");

    clear_screen();
    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
    }
        inFile.close();
}

void ConsoleUI::printUI() {
    int input;
    string line;
    ifstream inFile ("print-ui.txt");

    clear_screen();
    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
    }
        inFile.close();
        do{
        cin >> input;
            }while(!s.UIinputCheck(input, 6));

    if(input == 0) {
        choose();
    } else if(input == 1) {
        s.printAll();
    }
        else {
        s.sortAll(input);
    }
    cont();
    clear_screen();
}

void ConsoleUI::searchUI() {
    int input;
    string search;
    string line;
    ifstream inFile ("search.txt");
    clear_screen();

    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
    }
    do{
        cin >> input;
    }while(!s.UIinputCheck(input, 5));

    switch(input) {
        case 1:
            cout << "Please enter the first name: ";
            cin >> search;
            s.searchAll(1, search);
            break;
        case 2:
            cout << "Please enter the last name: ";
            cin >> search;
            s.searchAll(2, search);
            break;
        case 3:
            cout << "Please enter f for female or m for male: ";
            cin >> search;
            s.searchAll(3, search);
            break;
        case 4:
            cout << "Please enter a birth year: ";
            cin >> search;
            s.searchAll(4, search);
            break;
        case 5:
            cout << "Please enter a death year: ";
            cin >> search;
            s.searchAll(5, search);
            break;
        case 0:
            clear_screen();
            choose();
            return;
            break;
        default:
            break;
    }
    cont();
    clear_screen();
}

void ConsoleUI::removeUI() {
    int input;
    int databaseSize = s.sizeOfDatabase();
    s.printAllWithNumber();
    cout << "Please enter the number of the person you wish to remove" << endl;
    do{
        cin >> input;
    }while(!s.UIinputCheck(input-1, databaseSize-1));
    cout << "This person has been removed:" << endl;
    s.printOne(input-1);
    s.removeFromFile(input-1);
    cont();
    choose();
}


void ConsoleUI::clear_screen()
{
    //system("CLS");
    system("clear");

}

void ConsoleUI::cont() {
    char c;
    cout << "Please enter 'c' to continue or 'q' to quit: ";
    cin >> c;

    if(c == 'q' || c == 'Q')
    {
        exit(0);
    }
}
