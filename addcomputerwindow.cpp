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

void AddComputerWindow::on_lineComputerName_textChanged(const QString &arg1)
{
    //TODO: Computer name = arg1;
}

void AddComputerWindow::on_lineType_textChanged(const QString &arg1)
{
    //TODO: Computer type = arg1;
}

void AddComputerWindow::on_lineYearOfBuild_textChanged(const QString &arg1)
{
    //TODO: Computer year of build = arg1;
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
    //TODO: Add all stöff into computer;
}
