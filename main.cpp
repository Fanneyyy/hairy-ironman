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
    //addp.show();
    //addc.show();
    w.setGeometry(30,200,300,700);
    w.show();


    return a.exec();
}
