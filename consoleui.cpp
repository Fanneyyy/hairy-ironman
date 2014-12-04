#include "consoleui.h"

using namespace std;


#ifdef _WIN32
#define CLEAR_COMMAND "CLS"
#else
#define CLEAR_COMMAND "clear"
#endif

ConsoleUI::ConsoleUI() {
}
// initialSetUp(): prints the welcome screen and calls
// a function to load the exsiting database into a vector.
void ConsoleUI::initialSetUp() {
//    string line;
//    ifstream inFile ("welcome.txt");

//    s.setUp();
//    if(inFile.is_open()) {
//        while(getline(inFile, line)) {
//            cout << line << endl;
//        }
//    }
//    inFile.close();
    p.welcomeScreen();
    continueOrQuit();
    clear_screen();
}
// choose(): Initial user interface
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
// addUI(): UI to add a new person
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
// printUI(): allows the user to choose in what order
// to print out the list of people.
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
    continueOrQuit();
    clear_screen();
}
// searchUI(): UI for searching the list of people.
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
            break;
        case 2:
            cout << "Please enter the last name: ";
            break;
        case 3:
            cout << "Please enter f for female or m for male: ";
            break;
        case 4:
            cout << "Please enter a birth year: ";
            break;
        case 5:
            cout << "Please enter a death year: ";
            break;
        case 0:
            clear_screen();
            choose();
            return;
            break;
        default:
            break;
    }
    cin >> search;
    s.searchAll(input, search);
    continueOrQuit();
    clear_screen();
}
// removeUI(): prints out a numbered list of people and removes
// the person chosen.
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
    s.removeFromVector(input-1);
    continueOrQuit();
    choose();
}
// clear_screen(): clear the screen for nice visual affect
void ConsoleUI::clear_screen()
{
    system(CLEAR_COMMAND);
}
// continueOrQuit(): asks the user if he wants to continue or quit
void ConsoleUI::continueOrQuit() {
    char c;
    cout << "Please enter 'c' to continue or 'q' to quit: ";
    cin >> c;

    if(c == 'q' || c == 'Q')
    {
        exit(0);
    }
}
