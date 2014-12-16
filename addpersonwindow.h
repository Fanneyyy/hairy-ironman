#ifndef ADDPERSONWINDOW_H
#define ADDPERSONWINDOW_H

#include <QDialog>
#include "personsservice.h"

namespace Ui {
class AddPersonWindow;
}

class AddPersonWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddPersonWindow(QWidget *parent = 0);
    ~AddPersonWindow();

    void addPerson();
private slots:

    void on_AddPersonButton_clicked();

private:
    Ui::AddPersonWindow *ui;
    PersonsService personsService;
    Person p;
};

#endif // ADDPERSONWINDOW_H
