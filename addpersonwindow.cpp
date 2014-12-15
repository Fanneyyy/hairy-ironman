#include "addpersonwindow.h"
#include "ui_addpersonwindow.h"

AddPersonWindow::AddPersonWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPersonWindow) {
    ui->setupUi(this);
    ui->lineFullname->setPlaceholderText("Please enter full name");
    ui->lineGender->setPlaceholderText("Please enter gender (male/female)");
    ui->lineYearOfBirth->setPlaceholderText("Please enter the year of birth (Example: 1994)");
    ui->lineYearOfDeath->setPlaceholderText("Please enter the year of death (Example: 1999)");
}

AddPersonWindow::~AddPersonWindow() {
    delete ui;
}

void AddPersonWindow::on_AddPersonButton_clicked() {
    addPerson();
    ui->lineFullname->clear();
    ui->lineGender->clear();
    ui->lineYearOfBirth->clear();
    ui->lineYearOfDeath->clear();

}

void AddPersonWindow::addPerson() {
    Person p = Person();
    string temp;

    temp = ui->lineFullname->text().toStdString();
    p.setName(temp);
    temp = ui->lineGender->text().toStdString();
    p.setGender(temp);
    temp = ui->lineYearOfBirth->text().toStdString();
    p.setYearOfBirth(temp);
    temp = ui->lineYearOfDeath->text().toStdString();
    p.setYearOfDeath(temp);

    personsService.add(p);

}

/*
void AddPersonWindow::on_lineFullname_textChanged(const QString &arg1) {

}


void AddPersonWindow::on_lineGender_textChanged(const QString &arg1)
{

}

void AddPersonWindow::on_lineYearOfBirth_textChanged(const QString &arg1)
{

}

void AddPersonWindow::on_lineYearOfDeath_textChanged(const QString &arg1)
{

}
*/
