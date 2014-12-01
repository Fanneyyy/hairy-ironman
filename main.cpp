#include <QCoreApplication>
#include "consoleui.h"
#include <string>

int main(int argc, char *argv[])
{
    string line;
    ConsoleUI ui;
    ifstream inFile ("welcome.txt");
<<<<<<< HEAD
    string c;
=======
    char c;
>>>>>>> 7ac667996037a085f448c29637655fd450193242

    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
    cin >> c;
    }
    ui.initialSetUp();
    ui.choose();

    return 0;
}
