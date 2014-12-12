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

private slots:
    void on_pushToAddPerson_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    AddPersonWindow addperson;
    AddComputerWindow addcomputer;
};

#endif // MAINWINDOW_H
