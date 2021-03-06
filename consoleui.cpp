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
    computerService.setUp();
    connectionsService.setUp();
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
        }while(!inputCheck(input, 3));

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
            case 0:
                exit(0);
                break;
            default:
                break;
        }
    }while(input != 0);
    clear_screen();
}

// addUI(): UI to add to the database
void ConsoleUI::addUI() {
    int input = 0;

    clear_screen();
    pr.addScreen();

    do{
        cin >> input;
        }while(!inputCheck(input, 3));

    switch(input) {
        case 1:
            clear_screen();
            pr.addPersonScreen();
            personService.add();
            break;
        case 2:
            clear_screen();
            pr.addComputerScreen();
            computerService.add();
            break;
        case 3:
            clear_screen();
            pr.addConnectionScreen();
            cout << "Nr. ";
            pr.personHeader();
            personService.printAllWithNumber();
            cout << endl;
            cout << "Nr. ";
            pr.computerHeader();
            computerService.printAllWithNumber();
            connectionsService.add(personService.getAll(),computerService.getAll());
            break;
        case 0:
            return;
            break;
        default:
            break;
    }
}

// printUI(): UI to choose what the user wants printed
void ConsoleUI::printUI() {
    int input;

    clear_screen();
    pr.printScreen();

    do{
        cin >> input;
        }while(!inputCheck(input, 4));

    switch(input) {
        case 1:
            printPerson();
            break;
        case 2:
            printEverythingPerson();
            break;
        case 3:
            printComputer();
            break;
        case 4:
            printEverythingComputer();
            break;
        case 0:
            clear_screen();
            return;
        default:
            break;
    }
    continueOrQuit();
    clear_screen();
}

// printPerson(): UI to choose how the list of persons is sorted
void ConsoleUI::printPerson() {
    int input;
    vector<Person> sortedTemp;

    clear_screen();
    pr.printPersonsScreen();

    do{
        cin >> input;
        }while(!inputCheck(input, 6));

    if(input != 0) {
        pr.personHeader();
    }

    switch(input) {
        case 1:
            personService.printAll();;
            break;
        case 2:
            sortedTemp = sorter.sortVectorPersonName(personService.getAll());
            break;
        case 3:
            sortedTemp = sorter.sortVectorGender(personService.getAll());
            break;
        case 4:
            sortedTemp = sorter.sortVectorBirthYear(personService.getAll());
            break;
        case 5:
            sortedTemp = sorter.sortVectorDeathYear(personService.getAll());
            break;
        case 0:
            clear_screen();
            printUI();
            return;
        default:
            break;
    }
    for(unsigned int i = 0; i < sortedTemp.size(); i++) {
        cout << sortedTemp[i];
    }
}

// printComputer(): UI to choose how the list of computers is sorted
void ConsoleUI::printComputer() {
    int input;
    vector<Computer> sortedTemp;

    clear_screen();
    pr.printComputerScreen();

    do{
        cin >> input;
        }while(!inputCheck(input, 4));

    if(input != 0) {
        pr.computerHeader();
    }

    switch(input) {
        case 1:
            computerService.printAll();
            break;
        case 2:
            sortedTemp = sorter.sortVectorComputerName(computerService.getAll());
            break;
        case 3:
            sortedTemp = sorter.sortVectorType(computerService.getAll());
            break;
        case 4:
            sortedTemp = sorter.sortVectorBuildYear(computerService.getAll());
            break;
        case 0:
            clear_screen();
            printUI();
            return;
        default:
            break;
    }
    for(unsigned int i = 0; i < sortedTemp.size(); i++) {
        cout << sortedTemp[i];
    }
}

// printEverythingPerson(): UI to choose how the list of persons is sorted
// and prints the appropriate connected computers
void ConsoleUI::printEverythingPerson() {
    int input;
    vector<Person> sortedTempPersons;

    clear_screen();
    pr.printEverythingPerson();

    do{
        cin >> input;
    }while(!inputCheck(input, 5));

    if(input != 0) {
        pr.personHeader();
    }

    switch(input) {
        case 1:
            sortedTempPersons = personService.getAll();
            break;
        case 2:
            sortedTempPersons = sorter.sortVectorPersonName(personService.getAll());
            break;
        case 3:
            sortedTempPersons = sorter.sortVectorGender(personService.getAll());
            break;
        case 4:
            sortedTempPersons = sorter.sortVectorBirthYear(personService.getAll());
            break;
        case 5:
            sortedTempPersons = sorter.sortVectorDeathYear(personService.getAll());
            break;
        case 0:
            clear_screen();
            printUI();
            return;
        default:
            break;
    }
    connectionsService.printAllPerson(sortedTempPersons, computerService.getAll(), personService.getSizeOfRepo());
}

// printEverythingComputer(): UI to choose how the list of computers is sorted
// and prints the appropriate connected persons
void ConsoleUI::printEverythingComputer() {
    int input;
    vector<Computer> sortedTempComputers;

    clear_screen();
    pr.printEverythingComputer();

    do{
        cin >> input;
    }while(!inputCheck(input, 4));

    if(input != 0) {
        pr.computerHeader();
    }

    switch(input) {
        case 1:
            sortedTempComputers = computerService.getAll();
            break;
        case 2:
            sortedTempComputers = sorter.sortVectorComputerName(computerService.getAll());
            break;
        case 3:
            sortedTempComputers = sorter.sortVectorType(computerService.getAll());
            break;
        case 4:
            sortedTempComputers = sorter.sortVectorBuildYear(computerService.getAll());
            break;
        case 0:
            clear_screen();
            printUI();
            return;
        default:
            break;
    }
    connectionsService.printAllComputer(sortedTempComputers, personService.getAll(), computerService.getSizeOfRepo());
}

// searchUI(): UI for searching the database
void ConsoleUI::searchUI() {
    int input;
    string search;

    clear_screen();
    pr.searchScreen();

    do{
        cin >> input;
    }while(!inputCheck(input, 4));

    switch(input) {
        case 1:
            cout << "Please enter a name: ";
            cin >> search;
            searcher.searchAllNames(personService.getAll(), computerService.getAll(),search);
            break;
        case 2:
            cout << "Please enter Female or Male: ";
            cin >> search;
            searcher.gender(personService.getAll(),search);
            break;
        case 3:
            cout << "Please enter a year to search ";
            cin >> search;
            searcher.searchAllYears(personService.getAll(), computerService.getAll(),search);
            break;
        case 4:
            cout << "Please enter a type (E for Electronic / M for Mechanic / T for Transistor) ";
            cin >> search;
            searcher.type(computerService.getAll(),search);
            break;
        case 0:
            clear_screen();
            choose();
            return;
            break;
        default:
            break;
    }
    continueOrQuit();
    clear_screen();
}

// clear_screen(): clear the screen for nice visual affect
void ConsoleUI::clear_screen() {
    system(CLEAR_COMMAND);
}

// continueOrQuit(): asks the user if he wants to continue or quit
void ConsoleUI::continueOrQuit() {
    char c;

    cout << "Please enter 'c' to continue or 'q' to quit: ";
    cin >> c;
    if(c == 'q' || c == 'Q') {
        exit(0);
    }
}

// inputCheck(input, max): checks if the input is between 0 and max
bool ConsoleUI::inputCheck(int input, int max) {
    if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        input = -1;
    }

    if(input < 0 || input > max) {
        cout << "Wrong input, please try again" << endl;
        return false;
    }
    return true;
}
