#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cstdlib>
#include "search.h"
#include "service.h"
#include <QUrl>

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
    vector<Person> persons;
};

#endif // CONSOLEUI_H
