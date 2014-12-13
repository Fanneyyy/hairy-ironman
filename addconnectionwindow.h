#ifndef ADDCONNECTIONWINDOW_H
#define ADDCONNECTIONWINDOW_H

#include <QDialog>
#include "personsservice.h"
#include "computersservice.h"
#include "connectionsservice.h"

namespace Ui {
class AddConnectionWindow;
}

class AddConnectionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddConnectionWindow(QWidget *parent = 0);
    ~AddConnectionWindow();

    void displayPersonTable();
    void displayComputerTable();
private slots:
    void on_buttonPushToClose_clicked();


private:
    Ui::AddConnectionWindow *ui;
    PersonsService personsService;
    ComputersService computersService;
};

#endif // ADDCONNECTIONWINDOW_H
