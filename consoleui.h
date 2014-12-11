// ConsoleUI: Calls a function to read in a database to fill the vectors with stored information.
// It initializes the user interface and calls relevant functions from the Services as demanded
// by the user.

#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <cstdlib>
#include "personsservice.h"
#include "computersservice.h"
#include "connectionsservice.h"
#include "printui.h"
#include "sort.h"
#include "search.h"

class ConsoleUI {
public:
    ConsoleUI();
    void choose();
    void searchUI();
    void printUI();
    void sortUI();
    void initialSetUp();
    void clear_screen();
    void addUI();
    void continueOrQuit();
    void printPerson();
    void printEverything();
    void printComputer();
    bool inputCheck(int input, int max);
    void printEverythingPerson();
    void printEverythingComputer();
private:
    PrintUI pr;
    PersonsService personService;
    ComputersService computerService;
    ConnectionsService connectionsService;
    Search searcher;
    Sort sorter;
};

#endif // CONSOLEUI_H
