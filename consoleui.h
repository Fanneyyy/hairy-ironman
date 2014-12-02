// ConsoleUI: Calls a function to read in a file to fill the vector with stored information.
// It initializes the user interface and calls relevant functions from the Service as demanded
// by the user.

#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "search.h"
#include "service.h"

class ConsoleUI
{
public:
    ConsoleUI();
    void choose();
    void searchUI();
    void printUI();
    void removeUI();
    void sortUI();
    void initialSetUp();
    void clear_screen();
    void addUI();
    void cont();
private:
    Service s;
};

#endif // CONSOLEUI_H
