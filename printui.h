#ifndef PRINTUI_H
#define PRINTUI_H
#include <iostream>

using namespace std;

class PrintUI
{
public:
    PrintUI();
    void welcomeScreen();
    void chooseScreen();
    void addScreen();
    void printScreen();
    void searchScreen();
    void printPersonsScreen();
    void printComputerScreen();
    void printEverythingScreen();
    void addComputerScreen();
    void addPersonScreen();
    void remove();
};

#endif // PRINTUI_H
