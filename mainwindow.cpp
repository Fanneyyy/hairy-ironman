#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWebkitWidgets/QWebView>
#include <Qurl>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    personsService.setUp();
    computersService.setUp();
    displayPersonTable();
    displayComputerTable();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::displayPersonTable() {

    ui->tablePersons->setRowCount(personsService.getSizeOfRepo());
    for(int i = 0; i < personsService.getSizeOfRepo(); i++)
    {
        ui->tablePersons->setItem(i,0,new QTableWidgetItem(QString::fromStdString(personsService.get(i).getName())));
        ui->tablePersons->setItem(i,1,new QTableWidgetItem(QString::fromStdString(personsService.get(i).getGender())));
        ui->tablePersons->setItem(i,2,new QTableWidgetItem(QString::fromStdString(personsService.get(i).getYearOfBirth())));
        ui->tablePersons->setItem(i,3,new QTableWidgetItem(QString::fromStdString(personsService.get(i).getYearOfDeath())));

    }
}

void MainWindow::displayComputerTable() {

    ui->tableComputers->setRowCount(computersService.getSizeOfRepo());
    for(int i = 0; i < computersService.getSizeOfRepo(); i++) {
        ui->tableComputers->setItem(i,0,new QTableWidgetItem(QString::fromStdString(computersService.get(i).getComputerName())));
        ui->tableComputers->setItem(i,1,new QTableWidgetItem(QString::fromStdString(computersService.get(i).getType())));
        ui->tableComputers->setItem(i,2,new QTableWidgetItem(QString::fromStdString(computersService.get(i).getBuildYear())));
        ui->tableComputers->setItem(i,3,new QTableWidgetItem(QString::fromStdString(computersService.get(i).getBuiltRnot())));
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

void MainWindow::on_tablePersons_cellActivated(int row, int column)
{
    ui->viewWikipage->load(QUrl("http://en.wikipedia.org/wiki/"+ui->tablePersons->item(row, 0)->text()));
}

void MainWindow::on_tableComputers_cellActivated(int row, int column)
{
    ui->viewWikipage->load(QUrl("http://en.wikipedia.org/wiki/"+ui->tableComputers->item(row, 0)->text()));
}
