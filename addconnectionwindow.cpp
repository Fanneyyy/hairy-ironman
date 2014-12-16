#include "addconnectionwindow.h"
#include "ui_addconnectionwindow.h"

AddConnectionWindow::AddConnectionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddConnectionWindow)
{
    connection = Connection();
    ui->setupUi(this);
    personsService.setUp();
    computersService.setUp();
    displayComputerTable();
    displayPersonTable();
    ui->personTableConnection->setColumnHidden(4,true);
    ui->computerTableConnection->setColumnHidden(4,true);
    ui->computerTableConnection->setColumnHidden(3,true);
}

AddConnectionWindow::~AddConnectionWindow()
{
    delete ui;
}

void AddConnectionWindow::displayPersonTable() {

    ui->personTableConnection->setRowCount(personsService.getSizeOfRepo());
    for(int i = 0; i < personsService.getSizeOfRepo(); i++)
    {
        ui->personTableConnection->setItem(i,0,new QTableWidgetItem(QString::fromStdString(personsService.get(i).getName())));
        ui->personTableConnection->setItem(i,1,new QTableWidgetItem(QString::fromStdString(personsService.get(i).getGender())));
        ui->personTableConnection->setItem(i,2,new QTableWidgetItem(QString::fromStdString(personsService.get(i).getYearOfBirth())));
        ui->personTableConnection->setItem(i,3,new QTableWidgetItem(QString::fromStdString(personsService.get(i).getYearOfDeath())));
        ui->personTableConnection->setItem(i,4,new QTableWidgetItem(QString::number(personsService.get(i).getID())));

    }
}

void AddConnectionWindow::displayComputerTable() {

    ui->computerTableConnection->setRowCount(computersService.getSizeOfRepo());
    for(int i = 0; i < computersService.getSizeOfRepo(); i++) {
        ui->computerTableConnection->setItem(i,0,new QTableWidgetItem(QString::fromStdString(computersService.get(i).getComputerName())));
        ui->computerTableConnection->setItem(i,1,new QTableWidgetItem(QString::fromStdString(computersService.get(i).getType())));
        ui->computerTableConnection->setItem(i,2,new QTableWidgetItem(QString::fromStdString(computersService.get(i).getBuildYear())));
        ui->computerTableConnection->setItem(i,3,new QTableWidgetItem(QString::fromStdString(computersService.get(i).getBuiltRnot())));
        ui->computerTableConnection->setItem(i,4,new QTableWidgetItem(QString::number(computersService.get(i).getID())));
    }
}

void AddConnectionWindow::addConnection() {

}

void AddConnectionWindow::on_computerTableConnection_cellClicked(int row, int column) {
    int computerID = ui->computerTableConnection->item(row,4)->text().toInt();
    connection.setComputerID(computerID);
}

void AddConnectionWindow::on_personTableConnection_cellClicked(int row, int column) {
    int personID = ui->personTableConnection->item(row,4)->text().toInt();
    connection.setPersonID(personID);
}

void AddConnectionWindow::on_buttonPushToClose_clicked() {
    connectionRepo.add(connection);
    connectionsService.saveConnectionToDatabase(connection);
    close();
}
