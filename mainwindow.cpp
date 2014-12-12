#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    personsService.setUp();
    computersService.setUp();
    displayTable();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::displayTable() {

    ui->tablePersons->setRowCount(personsService.getSizeOfRepo());
    for(int i = 0; i < personsService.getSizeOfRepo(); i++)
    {
        ui->tablePersons->setItem(i,0,new QTableWidgetItem(QString::fromStdString(personsService.get(i).getName())));
        ui->tablePersons->setItem(i,1,new QTableWidgetItem(QString::fromStdString(personsService.get(i).getGender())));
        ui->tablePersons->setItem(i,2,new QTableWidgetItem(QString::fromStdString(personsService.get(i).getYearOfBirth())));
        ui->tablePersons->setItem(i,3,new QTableWidgetItem(QString::fromStdString(personsService.get(i).getYearOfDeath())));

    }
}


void MainWindow::on_buttonAddPerson_clicked()
{
    addperson.show();
}

void MainWindow::on_buttonAddComputer_clicked()
{
    addcomputer.show();
}
