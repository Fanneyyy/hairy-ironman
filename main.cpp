#include <QCoreApplication>
#include <iostream>
#include "person.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "Klasatest a Person." << endl;
    Person p1;
    cin >> p1;
    cout << "Og þetta er það sem prentast:" << endl;
    cout << p1;
    return 0;
}
