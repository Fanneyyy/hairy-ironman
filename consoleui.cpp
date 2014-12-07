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
    personService.setUp();
    pr.welcomeScreen();
    continueOrQuit();
    clear_screen();
}

// choose(): Initial user interface
void ConsoleUI::choose() {
    int input;
    clear_screen();
    do {
        pr.chooseScreen();
        do {
            cin >> input;
        }while(!personService.UIinputCheck(input, 4));

        switch(input) {
            case 1:
                addUI();
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
                exit(0);
                break;
            default:
                break;
        }
    }while(input != 0);
    clear_screen();
}

// addUI(): UI to add a new person
void ConsoleUI::addUI() {
    int input = 0;
    clear_screen();
    pr.addScreen();
    cin >> input;
    switch(input) {
        case 1:
            pr.addPersonScreen();
            personService.add();
            break;
        case 2:
            pr.addComputerScreen();
            computerService.add();
        case 0:
            return;
            break;
        default:
            break;
    }

    personService.add();
}

void ConsoleUI::printUI() {
    int input;
    clear_screen();
    pr.printScreen();
        do{
        cin >> input;
            }while(!personService.UIinputCheck(input, 6));
    switch(input) {
        case 1:
            pr.printPersonsScreen();
            break;
        case 2:
            pr.printComputerScreen();
            break;
        case 3:
            pr.printEverythingScreen();
            break;
        case 0:
            clear_screen();
            return;
            break;
        default:
            break;
    }

    clear_screen();
}

// searchUI(): UI for searching the list of people.
void ConsoleUI::searchUI() {
    int input;
    string search;

    clear_screen();
    pr.searchScreen();
    do{
        cin >> input;
    }while(!personService.UIinputCheck(input, 5));

    switch(input) {
        case 1:
            cout << "Please enter a name: ";
            break;
        case 2:
            cout << "Please enter Female or Male: ";
            break;
        case 3:
            cout << "Please enter a birth year: ";
            break;
        case 4:
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
    personService.searchAll(input, search);
    continueOrQuit();
    clear_screen();
}

// removeUI(): prints out a numbered list of people and removes
// the person chosen.
void ConsoleUI::removeUI() {
    int input;
    int databaseSize = personService.sizeOfDatabase();
    clear_screen();
    pr.remove();
    cin >> input;
    switch(input) {
        case 1:
            //remove scientist
            break;
        case 2:
            //remove computer
            break;
        case 0:
            clear_screen();
            return;
        default:
            break;
    }

    personService.printAllWithNumber();
    cout << "This person has been removed:" << endl;
    personService.printOne(input-1);
    personService.removeFromVector(input-1);
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
