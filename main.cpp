#include <QCoreApplication>
#include "consoleui.h"
#include <string>

int main()
{
    ConsoleUI ui;

    ui.initialSetUp();
    ui.choose();

    return 0;
}
