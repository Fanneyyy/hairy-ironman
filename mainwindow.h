#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "personsservice.h"
#include "computersservice.h"
#include "connectionsservice.h"

#include "addpersonwindow.h"
#include "addcomputerwindow.h"
#include "addconnectionwindow.h"

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

    void on_tablePersons_cellActivated(int row, int column);

    void on_tableComputers_cellActivated(int row, int column);

    void on_buttonAddConnection_clicked();

    void on_lineSearchComputer_textChanged(const QString &arg1);
    void on_lineSearchPerson_textChanged(const QString &arg1);
private:
    Ui::MainWindow *ui;
    AddPersonWindow addperson;
    AddComputerWindow addcomputer;
    AddConnectionWindow addconnection;

    PersonsService personsService;
    ComputersService computersService;
    ConnectionsService connectionsService;
};

#endif // MAINWINDOW_H
