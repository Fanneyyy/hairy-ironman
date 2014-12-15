#include "addconnectionwindow.h"
#include "ui_addconnectionwindow.h"

AddConnectionWindow::AddConnectionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddConnectionWindow)
{
    ui->setupUi(this);
    personsService.setUp();
    computersService.setUp();
    displayComputerTable();
    displayPersonTable();
}

AddConnectionWindow::~AddConnectionWindow()
{
    delete ui;
}

void AddConnectionWindow::on_buttonPushToClose_clicked()
{
    close();
}

void AddConnectionWindow::displayPersonTable() {

    ui->personTableConnection->setRowCount(personsService.getSizeOfRepo());
    for(int i = 0; i < personsService.getSizeOfRepo(); i++)
    {
        ui->personTableConnection->setItem(i,0,new QTableWidgetItem(QString::fromStdString(personsService.get(i).getName())));
        ui->personTableConnection->setItem(i,1,new QTableWidgetItem(QString::fromStdString(personsService.get(i).getGender())));
        ui->personTableConnection->setItem(i,2,new QTableWidgetItem(QString::fromStdString(personsService.get(i).getYearOfBirth())));
        ui->personTableConnection->setItem(i,3,new QTableWidgetItem(QString::fromStdString(personsService.get(i).getYearOfDeath())));

    }
}

void AddConnectionWindow::displayComputerTable() {

    ui->computerTableConnection->setRowCount(computersService.getSizeOfRepo());
    for(int i = 0; i < computersService.getSizeOfRepo(); i++) {
        ui->computerTableConnection->setItem(i,0,new QTableWidgetItem(QString::fromStdString(computersService.get(i).getComputerName())));
        ui->computerTableConnection->setItem(i,1,new QTableWidgetItem(QString::fromStdString(computersService.get(i).getType())));
        ui->computerTableConnection->setItem(i,2,new QTableWidgetItem(QString::fromStdString(computersService.get(i).getBuildYear())));
        ui->computerTableConnection->setItem(i,3,new QTableWidgetItem(QString::fromStdString(computersService.get(i).getBuiltRnot())));
    }
}

void AddConnectionWindow::addConnection() {


}
