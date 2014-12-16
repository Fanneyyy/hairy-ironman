#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWebkitWidgets/QWebView>
#include <Qurl>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connectionsService.setUp();
    personsService.setUp();
    computersService.setUp();
    config();
    displayPersonTable();
    displayComputerTable();
}

MainWindow::~MainWindow() {


    delete ui;
}

void MainWindow::config() {
    ui->lineSearchComputer->setPlaceholderText("Search..");
    ui->lineSearchPerson->setPlaceholderText("Search..");
    ui->tablePersons->setColumnHidden(4,true);
    ui->tableComputers->setColumnHidden(4,true);
    ui->tableComputers->setColumnHidden(3,true);
    ui->tablePersons->horizontalHeader()->resizeSection(0, 185);
    ui->tableComputers->horizontalHeader()->resizeSection(0,185);
    ui->tablePersons->horizontalHeader()->resizeSection(1, 120);
    ui->tableComputers->horizontalHeader()->resizeSection(1,120);
}

void MainWindow::displayPersonTable() {
    ui->tablePersons->clearContents();
    ui->tablePersons->setSortingEnabled(false);
    personsService.removeAll();
    personsService.setUp();

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
    ui->tableComputers->clearContents();
    ui->tableComputers->setSortingEnabled(false);
    computersService.removeAll();
    computersService.setUp();

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

void MainWindow::on_buttonAddPerson_clicked() {
    addperson.exec();
    //personsRepo.emptyRepo();
    //personsService.setUp();
    displayPersonTable();
    //ui->labelPerson->setText("A person has been successfully added to the database");
}

void MainWindow::on_buttonAddComputer_clicked() {
    addcomputer.exec();
    //computersRepo.emptyRepo();
    //computersService.setUp();
    displayComputerTable();
    //ui->labelComputer->setText("A computer has successfully been added to the database");
}

void MainWindow::on_tablePersons_cellActivated(int row) {
    ui->listConnectionsPerson->clear();
    vector<Computer> temp = connectionsService.printAllPerson(ui->tablePersons->item(row,4)->text().toInt(), computersService.getAll());

    ui->viewWikipage->load(QUrl("http://en.wikipedia.org/wiki/"+ui->tablePersons->item(row, 0)->text()));
    if(temp.size() > 0) {
    ui->listConnectionsPerson->addItem("The Scientist "+ui->tablePersons->item(row,0)->text()+" is connected to: ");
    for(unsigned int i = 0; i < temp.size(); i++) {
        ui->listConnectionsPerson->addItem(QString::fromStdString(temp[i].getComputerName()));
        }
    }
    setMinimumWidth(1337);
}

void MainWindow::on_tableComputers_cellActivated(int row) {
    ui->listConnectionsComputer->clear();
    vector<Person> temp = connectionsService.printAllComputer(ui->tableComputers->item(row,4)->text().toInt(), personsService.getAll());

    ui->viewWikipage->load(QUrl("http://en.wikipedia.org/wiki/"+ui->tableComputers->item(row, 0)->text()));
    if(temp.size() > 0) {
    ui->listConnectionsComputer->addItem("The Computer "+ui->tableComputers->item(row,0)->text()+" is connected to: ");
    for(unsigned int i = 0; i < temp.size(); i++) {
        ui->listConnectionsComputer->addItem(QString::fromStdString(temp[i].getName()));
        }
    }
    setMinimumWidth(1337);
}

void MainWindow::on_buttonAddConnectionPerson_clicked() {
    addconnection.exec();
    //ui->labelPerson->setText("A connection has been successfully added to the database");
    //ui->labelComputer->setText("A connection has been successfully added to the database");
}

void MainWindow::on_buttonAddConnectionComputer_clicked() {
    addconnection.exec();
    //ui->labelComputer->setText("A connection has been successfully added to the database");
    //ui->labelPerson->setText("A connection has been successfully added to the database");
}

void MainWindow::on_lineSearchPerson_textChanged() {
    displayPersonTable();
}
void MainWindow::on_lineSearchComputer_textChanged() {
    displayComputerTable();
}

void MainWindow::on_removePerson_clicked() {
    int activeRow = ui->tablePersons->currentRow();
    string ID = ui->tablePersons->item(activeRow,4)->text().toStdString();
    int personID = ui->tablePersons->item(activeRow,4)->text().toInt();
    personsService.remove(personID,ID);
    displayPersonTable();
}

void MainWindow::on_removeComputer_clicked() {
    int activeRow = ui->tableComputers->currentRow();
    string ID = ui->tableComputers->item(activeRow,4)->text().toStdString();
    int computerID = ui->tableComputers->item(activeRow,4)->text().toInt();
    computersService.remove(computerID,ID);
    displayComputerTable();
}
