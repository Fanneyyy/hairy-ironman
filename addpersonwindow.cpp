#include "addpersonwindow.h"
#include "ui_addpersonwindow.h"

AddPersonWindow::AddPersonWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPersonWindow) {
    ui->setupUi(this);
    ui->lineFullname->setPlaceholderText("Please enter full name");
    ui->lineYearOfBirth->setPlaceholderText("Please enter the year of birth (Example: 1994)");
    ui->lineYearOfDeath->setPlaceholderText("Please enter the year of death (Example: 1999)");
}

AddPersonWindow::~AddPersonWindow() {
    delete ui;
}

void AddPersonWindow::on_AddPersonButton_clicked() {
    addPerson();
}

void AddPersonWindow::addPerson() {
    Person p = Person();
    string temp;

    temp = ui->lineFullname->text().toStdString();
    p.setName(temp);
    if(ui->male_checkbox->isChecked()) {
        temp = "male";
    }else if(ui->female_checkbox->isChecked()) {
        temp = "female";
    }
    p.setGender(temp);

    temp = ui->lineYearOfBirth->text().toStdString();
    p.setYearOfBirth(temp);
    temp = ui->lineYearOfDeath->text().toStdString();
    p.setYearOfDeath(temp);
}
