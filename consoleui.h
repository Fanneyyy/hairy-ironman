// ConsoleUI: Calls a function to read in a file to fill the vector with stored information.
// It initializes the user interface and calls relevant functions from the Service as demanded
// by the user.

#ifndef CONSOLEUI_H
#define CONSOLEUI_H
//#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
//#include <iostream>
#include "search.h"
#include "PersonsService.h"
#include "computersservice.h"
#include "connectionsservice.h"
#include "printui.h"
#include "sort.h"

class ConsoleUI
{
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
