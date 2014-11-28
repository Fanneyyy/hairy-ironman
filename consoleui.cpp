#include "consoleui.h"
#include "readperson.h"
#include "printfile.h"
#include <iostream>
#include <fstream>
#include <string>
#include "search.h"

using namespace std;
list<Person> persons;

ConsoleUI::ConsoleUI() {

}

void ConsoleUI::choose(){
    readPerson rp;
    printFile wf;
    int what;
    do{
        cout << "What would you like to do? " << endl;
        cout << "1. Add person" << endl;
        cout << "2. Print from file" << endl;
        cout << "3. Search list" << endl;
        cout << "4. Sort list" << endl;
        cout << "0. Exit" << endl;

        cin >> what;

        switch(what)
        {
            case 1:
                rp.read();
                break;
            case 2:
                wf.print();
                break;
            case 3:
                searchUI();
                break;
            case 0:
                return;
                break;
            default:
                break;
        }
    }while(what != 0);
}

void ConsoleUI::searchUI() {
    Search s;
    int input;
    cout << "How would you like to search?" << endl;
    cout << "1. Search for first name" << endl;
    cout << "More later" << endl;
    cin >> input;

    switch(input) {
        case 1: {
            string tempName;
            cout << "Enter first name: ";
            cin >> tempName;
            if(s.Search::firstName(persons, tempName)) {
                cout << s.Search::returnFirstName(persons, tempName);
            }
            break;
            }
        case 2:
            break;
        default:
            break;
    }
}
