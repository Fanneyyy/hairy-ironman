#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "personsservice.h"
#include "computersservice.h"
#include "connectionsservice.h"

#include "addpersonwindow.h"
#include "addcomputerwindow.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void displayComputerTable();
    void displayPersonTable();
private slots:


    void on_buttonAddPerson_clicked();

    void on_buttonAddComputer_clicked();

private:
    Ui::MainWindow *ui;
    AddPersonWindow addperson;
    AddComputerWindow addcomputer;
    PersonsService personsService;
    ComputersService computersService;
};

#endif // MAINWINDOW_H
