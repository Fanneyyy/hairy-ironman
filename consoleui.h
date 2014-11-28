#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "printfile.h"
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
    void read();
    void print();
    void searchUI();
    void printUI();
private:
    Service s;
    vector<Person> persons;
};

#endif // CONSOLEUI_H
