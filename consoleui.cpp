#include "consoleui.h"

using namespace std;

ConsoleUI::ConsoleUI() {

}

void ConsoleUI::initialSetUp() {
    s.setUp();
}

void ConsoleUI::choose(){
    int what;
    string line;


    do{
        ifstream inFile ("choose-ui.txt");
        if(inFile.is_open()) {
            while(getline(inFile, line)) {
                cout << line << endl;
            }
        }
            inFile.close();
        do{
        cin >> what;
            }while(!s.UIinputCheck(what, 4));

        switch(what)
        {
            case 1:
                s.add();
                break;
            case 2:
                printUI();
                break;
            case 3:
                searchUI();
                break;
            case 4:
                removeUI();
                break;
            case 0:
                s.clearAndPrintFile();
                return;
                break;
            default:
                break;
        }

    }while(what != 0);
}

void ConsoleUI::printUI() {
    int input;
    string line;
    ifstream inFile ("print-ui.txt");

    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
    }
        inFile.close();
        do{
        cin >> input;
            }while(!s.UIinputCheck(input, 6));

    if(input == 0) {
        choose();
    } else if(input == 1) {
        s.printAll();
    }
        else {
        s.sortAll(input);
    }
}

void ConsoleUI::searchUI() {
    int input;
    string search;
    string line;
    ifstream inFile ("search.txt");

    if(inFile.is_open()) {
        while(getline(inFile, line)) {
            cout << line << endl;
        }
    }
    do{
    cin >> input;
        }while(!s.UIinputCheck(input, 3));

    switch(input) {
        case 1:
            cout << "Please enter the name: ";
            cin >> search;
            s.searchAll(1, search);
            break;
        case 2:
            cout << "Please enter f for female og m for male: ";
            cin >> search;
            s.searchAll(2, search);
            break;
        case 3:
            cout << "Please enter a year: ";
            cin >> search;
            s.searchAll(3, search);
            break;
        case 0:
            choose();
            break;
        default:
            break;
    }
}

//void ConsoleUI::printUI() {
//    int input;
//    string line;
//    ifstream inFile ("print-ui.txt");

//    if(inFile.is_open()) {
//        while(getline(inFile, line)) {
//            cout << line << endl;
//        }
//    }
//        inFile.close();
//    cin >> input;

//    switch(input) {
//        case 1:
//            s.printAll();
//            break;
//        case 2:
//            break;
//        case 3:
//            break;
//        case 4:
//            break;
//        case 5:
//            break;
//        case 6:
//            break;
//        case 0:
//            choose();
//        default:
//            break;
//    }
//}

void ConsoleUI::removeUI() {
    int input;
    s.printAllWithNumber();
    cout << "Please enter the number of the person you wish to remove" << endl;
    cin >> input;
    cout << "This person has been removed:" << endl;
    s.printOne(input-1);
    s.removeFromFile(input-1);
}
