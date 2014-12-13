#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "personsservice.h"
#include "computersservice.h"

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
    void on_listTab1_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    PersonsService personService;
    ComputersService computerService;
};

#endif // MAINWINDOW_H
