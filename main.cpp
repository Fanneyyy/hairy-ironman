#include <QCoreApplication>
#include "consoleui.h"

int main(int argc, char *argv[])
{
    string line;
    ConsoleUI ui;
    ifstream inFile ("welcome.txt");
    int c;

    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
        cin >> c;
    }

    ui.choose();

    return 0;
}
