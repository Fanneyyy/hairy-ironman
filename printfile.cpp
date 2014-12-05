#include "printfile.h"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

printFile::printFile()
{
}

void printFile::print(){
   string line;
   cout << "Nuna prentum við ur filenum" << endl;

    ifstream myfile ("test.txt");
    if(myfile.is_open())
    {
    while (getline (myfile, line))
    {
        cout << line << endl;
    }
    myfile.close();
    }
    else
    {
        cout << "Sorry, no information at hand" << endl;
    }
}
