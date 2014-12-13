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

void AddPersonWindow::on_lineFullname_textChanged(const QString &arg1) {
    //TODO: Person name = &arg1;
}

void AddPersonWindow::on_lineGender_textChanged(const QString &arg1) {
    //TODO: Person gender = &arg1;
}

void AddPersonWindow::on_lineYearOfBirth_textChanged(const QString &arg1) {
    //TODO: Person Year of Birth = &arg1;
}

void AddPersonWindow::on_lineYearOfDeath_textChanged(const QString &arg1) {
    //TODO: Person Year of Death = &arg1;
}

void AddPersonWindow::on_AddPersonButton_clicked() {
    addPerson();
}

void AddPersonWindow::addPerson() {
    Person p = Person();
    string temp;

    on_lineFullname_textChanged(QString::fromStdString(temp));
    p.setName(temp);
    on_lineGender_textChanged(QString::fromStdString(temp));
    p.setGender(temp);
    on_lineYearOfBirth_textChanged(QString::fromStdString(temp));
    p.setYearOfBirth(temp);
    on_lineYearOfDeath_textChanged(QString::fromStdString(temp));
    p.setYearOfDeath(temp);

}
