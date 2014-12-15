#include "addcomputerwindow.h"
#include "ui_addcomputerwindow.h"
#include <QMessageBox>

AddComputerWindow::AddComputerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddComputerWindow)
{
    ui->setupUi(this);
    ui->lineComputerName->setPlaceholderText("Please enter name of computer");
    ui->lineType->setPlaceholderText("Please enter type (Mechanical, Electronic or Transistor)");
    ui->lineYearOfBuild->setPlaceholderText("Year of build (leave empty if it wasn't)");
}

AddComputerWindow::~AddComputerWindow()
{
    delete ui;
}


/*
bool AddComputerWindow::linesAreValid() {
    ui->label_error->setText("");

    if(ui->lineComputerName->text().isEmpty()) {
        ui->label_error->setText("<span style='color: red'>Please enter a name</span>");
        return false;
    }
    if(ui->lineType->text().isEmpty()) {
        ui->label_error->setText("<span style='color: red'>Please enter a type</span>");
        return false;
    }
    return true;
}
*/

void AddComputerWindow::on_buttonAddComputer_clicked()
{
    addComputer();
}
void AddComputerWindow::addComputer() {
    Computer c = Computer();
    string temp;

    temp = ui->lineComputerName->text().toStdString();
    c.setComputerName(temp);
    temp = ui->lineType->text().toStdString();
    c.setType(temp);
    temp = ui->lineYearOfBuild->text().toStdString();
    c.setBuildYear(temp);

    computersService.add(c);
}
