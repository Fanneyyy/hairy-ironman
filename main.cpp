#include "mainwindow.h"
#include "personsservice.h"
#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    PersonsService p;

    p.setUp();
    qDebug() << p.getSizeOfRepo();
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
