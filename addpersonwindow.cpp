#include "addpersonwindow.h"
#include "ui_addpersonwindow.h"

AddPersonWindow::AddPersonWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddPersonWindow) {
    ui->setupUi(this);
    ui->lineFullname->setPlaceholderText("Please enter full name");
    ui->lineYearOfBirth->setPlaceholderText("Please enter the year of birth");
    ui->lineYearOfDeath->setPlaceholderText("Please enter the year of death ('-' if person still alive)");
}

AddPersonWindow::~AddPersonWindow() {
    delete ui;
}

void AddPersonWindow::on_AddPersonButton_clicked() {
    if(!utilities.validYear(ui->lineYearOfBirth->text().toStdString())) {
        ui->labelError->setText("<font color='red'>The birth year you selected is not valid</font>");
    }
    else if(!utilities.validYear(ui->lineYearOfDeath->text().toStdString())) {
        ui->labelError->setText("<font color='red'>The death year you selected is not valid</font>");
    }
    else if(ui->lineFullname->text().isEmpty()) {
        ui->labelError->setText("<font color='red'>Please enter a name</font>");
    }
    else if(!ui->male_checkbox->isChecked() && !ui->female_checkbox->isChecked()) {
        ui->labelError->setText("<font color='red'>Please check a box to select a gender</font>");
    }
    else if(ui->lineYearOfBirth->text().toInt() > ui->lineYearOfDeath->text().toInt()) {
        ui->labelError->setText("<font color='red'>Sorry, you can't die before being born</font>");
    }
    else {
        addPerson();
        ui->lineFullname->clear();
        ui->lineYearOfBirth->clear();
        ui->lineYearOfDeath->clear();
        close();
    }
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
