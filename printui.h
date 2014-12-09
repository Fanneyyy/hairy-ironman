#ifndef PRINTUI_H
#define PRINTUI_H
#include <iostream>
#include <iomanip>

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
    void computerHeader();
    void personHeader();
    void addConnectionScreen();
    void printEverythingPerson();
    void printEverythingComputer();
};

#endif // PRINTUI_H
