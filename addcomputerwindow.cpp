#include "addcomputerwindow.h"
#include "ui_addcomputerwindow.h"
#include <QMessageBox>

AddComputerWindow::AddComputerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerWindow) {
    ui->setupUi(this);
    ui->lineComputerName->setPlaceholderText("Please enter name of computer");
    ui->lineYearOfBuild->setPlaceholderText("Year of build (leave empty if it wasn't)");
}

AddComputerWindow::~AddComputerWindow() {
    delete ui;
}

// on click, runs input validation and add a computer
void AddComputerWindow::on_buttonAddComputer_clicked() {
    if(ui->lineComputerName->text().isEmpty()) {
        ui->labelError->setText("<font color='red'>Please enter a name</font>");
    }
    else if(!utilities.validYear(ui->lineYearOfBuild->text().toStdString()) && ui->lineYearOfBuild->text().toStdString() != "") {
        ui->labelError->setText("<font color='red'>Please enter a valid year</font>");
    }
    else if(!ui->ElectronicButton->isChecked() && !ui->MechanicalButton->isChecked() && !ui->TransistorButton->isChecked()) {
        ui->labelError->setText("<font color='red'>Please check a box to select a type</font>");
    }
    else {
        addComputer();
        ui->lineComputerName->clear();
        ui->lineYearOfBuild->clear();
        close();
    }
}

// adds a computer into the database
void AddComputerWindow::addComputer() {
    Computer c = Computer();
    string temp;

    temp = ui->lineComputerName->text().toStdString();
    c.setComputerName(temp);
    if(ui->ElectronicButton->isChecked()) {
            temp = "Electronic";
        }
        else if(ui->MechanicalButton->isChecked()) {
            temp = "Mechanical";
        }
        else if(ui->TransistorButton->isChecked()) {
            temp = "Transistor";
        }
        c.setType(temp);
    temp = ui->lineYearOfBuild->text().toStdString();
    c.setBuildYear(temp);

    computersService.add(c);
}
