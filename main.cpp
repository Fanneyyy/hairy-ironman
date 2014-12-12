#include "mainwindow.h"
#include "personsservice.h"
#include "addpersonwindow.h"
#include "addcomputerwindow.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    PersonsService p;

    p.setUp();
    QApplication a(argc, argv);
    MainWindow w;
    AddPersonWindow addp;
    AddComputerWindow addc;
    //addp.show();
    //addc.show();
    w.show();

    return a.exec();
}
