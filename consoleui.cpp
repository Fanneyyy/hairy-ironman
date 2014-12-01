#include "consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI() {

}

void ConsoleUI::initialSetUp() {
    string line;
    ifstream inFile ("welcome.txt");
    char c;

    s.setUp();
    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
    }
    inFile.close();
    cin >> c;
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
                return;
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
    char c;
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
    cout << "Press a key to continue";
    cin >> c;
    clear_screen();
}

void ConsoleUI::searchUI() {
    int input;
    char c;
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
            cout << "Please enter a birth year: ";
            cin >> search;
            s.searchAll(5, search);
            break;
        case 0:
            clear_screen();
            choose();
            break;
        default:
            break;
    }
    cout << "Press any key to continue: ";
    cin >> c;
    clear_screen();
}

void ConsoleUI::removeUI() {
    int input;
    s.printAllWithNumber();
    cout << "Please enter the number of the person you wish to remove" << endl;
    cin >> input;
    cout << "This person has been removed:" << endl;
    s.printOne(input-1);
    s.removeFromFile(input-1);
    choose();
}


void ConsoleUI::clear_screen()
{
#ifdef WINDOWS
    std::system("cls");
#else
    // Assume POSIX
    std::system ("clear");
#endif
}
