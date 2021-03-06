// The main window for the User interface

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

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void displayComputerTable();
    void displayPersonTable();
    void config();
private slots:
    void on_buttonAddPerson_clicked();
    void on_buttonAddComputer_clicked();
    void on_tablePersons_cellActivated(int row);
    void on_tableComputers_cellActivated(int row);
    void on_buttonAddConnectionPerson_clicked();
    void on_buttonAddConnectionComputer_clicked();
    void on_lineSearchComputer_textChanged();
    void on_lineSearchPerson_textChanged();
    void on_removePerson_clicked();
    void on_removeComputer_clicked();

private:
    Ui::MainWindow *ui;
    AddPersonWindow addperson;
    AddComputerWindow addcomputer;

    PersonsService personsService;
    ComputersService computersService;
    ConnectionsService connectionsService;

    PersonsRepository personsRepo;
    ComputerRepository computersRepo;
};

#endif // MAINWINDOW_H
