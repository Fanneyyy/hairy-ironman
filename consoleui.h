#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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
private:
    Service s;
    vector<Person> persons;
};

#endif // CONSOLEUI_H
