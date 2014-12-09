// initializes a User interface, calls the setup function
// and runs the first User interface screen.

#include "consoleui.h"

int main() {
    ConsoleUI ui;
    ui.initialSetUp();
    ui.choose();

    return 0;
}
