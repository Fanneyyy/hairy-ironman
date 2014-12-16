#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWebkitWidgets/QWebView>
#include <Qurl>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    personsService.setUp();
    computersService.setUp();
    connectionsService.setUp();
    displayPersonTable();
    displayComputerTable();
    ui->lineSearchComputer->setPlaceholderText("Search..");
    ui->lineSearchPerson->setPlaceholderText("Search..");

}

MainWindow::~MainWindow() {

    delete ui;
}

void MainWindow::displayPersonTable() {
    ui->tablePersons->clear();
    ui->tablePersons->setSortingEnabled(false);

    vector<Person> temp;
    string searchString;
    for(int i = 0; i < personsService.getSizeOfRepo(); i++) {
        searchString = ui->lineSearchPerson->text().toStdString();
        if(personsService.get(i).contains(searchString)) {
            temp.push_back(personsService.get(i));
        }
    }

    ui->tablePersons->setRowCount(personsService.getSizeOfRepo());
    for(unsigned int i = 0; i < temp.size(); i++) {
        ui->tablePersons->setItem(i,0,new QTableWidgetItem(QString::fromStdString(temp[i].getName())));
        ui->tablePersons->setItem(i,1,new QTableWidgetItem(QString::fromStdString(temp[i].getGender())));
        ui->tablePersons->setItem(i,2,new QTableWidgetItem(QString::fromStdString(temp[i].getYearOfBirth())));
        ui->tablePersons->setItem(i,3,new QTableWidgetItem(QString::fromStdString(temp[i].getYearOfDeath())));
        ui->tablePersons->setItem(i,4,new QTableWidgetItem(QString::number(temp[i].getID())));
    }
    ui->tablePersons->setSortingEnabled(true);
}

void MainWindow::displayComputerTable() {
    ui->tableComputers->clear();
    ui->tableComputers->setSortingEnabled(false);

    vector<Computer> temp;
    string searchString;
    for(int i = 0; i < computersService.getSizeOfRepo(); i++) {
        searchString = ui->lineSearchComputer->text().toStdString();
        if(computersService.get(i).contains(searchString)) {
            temp.push_back(computersService.get(i));
        }
    }

    ui->tableComputers->setRowCount(computersService.getSizeOfRepo());
    for(unsigned int i = 0; i < temp.size(); i++) {
        ui->tableComputers->setItem(i,0,new QTableWidgetItem(QString::fromStdString(temp[i].getComputerName())));
        ui->tableComputers->setItem(i,1,new QTableWidgetItem(QString::fromStdString(temp[i].getType())));
        ui->tableComputers->setItem(i,2,new QTableWidgetItem(QString::fromStdString(temp[i].getBuildYear())));
        ui->tableComputers->setItem(i,3,new QTableWidgetItem(QString::fromStdString(temp[i].getBuiltRnot())));
        ui->tableComputers->setItem(i,4,new QTableWidgetItem(QString::number(temp[i].getID())));
    }
    ui->tableComputers->setSortingEnabled(true);
}
/*
void MainWindow::displayComputerTable() {

    ui->tableComputers->setRowCount(computersService.getSizeOfRepo());
    for(int i = 0; i < computersService.getSizeOfRepo(); i++) {
        ui->tableComputers->setItem(i,0,new QTableWidgetItem(QString::fromStdString(computersService.get(i).getComputerName())));
        ui->tableComputers->setItem(i,1,new QTableWidgetItem(QString::fromStdString(computersService.get(i).getType())));
        ui->tableComputers->setItem(i,2,new QTableWidgetItem(QString::fromStdString(computersService.get(i).getBuildYear())));
        ui->tableComputers->setItem(i,3,new QTableWidgetItem(QString::fromStdString(computersService.get(i).getBuiltRnot())));
        ui->tableComputers->setItem(i,4,new QTableWidgetItem(QString::number(computersService.get(i).getID())));
    }
}
*/
void MainWindow::on_buttonAddPerson_clicked() {
    addperson.exec();
}

void MainWindow::on_buttonAddComputer_clicked() {
    addcomputer.exec();
}

void MainWindow::on_tablePersons_cellActivated(int row) {
    ui->listConnections->clear();
    vector<Computer> temp = connectionsService.printAllPerson(ui->tablePersons->item(row,4)->text().toInt(), computersService.getAll());

    ui->viewWikipage->load(QUrl("http://en.wikipedia.org/wiki/"+ui->tablePersons->item(row, 0)->text()));
    if(temp.size() > 0) {
    ui->listConnections->addItem("The Scientist "+ui->tablePersons->item(row,0)->text()+" is connected to: ");
    for(unsigned int i = 0; i < temp.size(); i++) {
        ui->listConnections->addItem(QString::fromStdString(temp[i].getComputerName()));
        }
    }
}

void MainWindow::on_tableComputers_cellActivated(int row) {
    ui->listConnections->clear();
    vector<Person> temp = connectionsService.printAllComputer(ui->tableComputers->item(row,4)->text().toInt(), personsService.getAll());

    ui->viewWikipage->load(QUrl("http://en.wikipedia.org/wiki/"+ui->tableComputers->item(row, 0)->text()));
    if(temp.size() > 0) {
    ui->listConnections->addItem("The Computer "+ui->tableComputers->item(row,0)->text()+" is connected to: ");
    for(unsigned int i = 0; i < temp.size(); i++) {
        ui->listConnections->addItem(QString::fromStdString(temp[i].getName()));
        }
    }
}

void MainWindow::on_buttonAddConnectionPerson_clicked() {
    addconnection.exec();
}

void MainWindow::on_buttonAddConnectionComputer_clicked() {
    addconnection.exec();
}

void MainWindow::on_lineSearchPerson_textChanged() {
    displayPersonTable();
}
void MainWindow::on_lineSearchComputer_textChanged() {
    displayComputerTable();
}
