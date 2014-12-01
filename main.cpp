#include <QCoreApplication>
#include "consoleui.h"
#include <string>

int main(int argc, char *argv[])
{
    string line;
    ConsoleUI ui;
    ifstream inFile ("welcome.txt");
    char c;

    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
    cin >> c;
    }

    ui.choose();

    return 0;
}
