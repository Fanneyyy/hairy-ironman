#ifndef ADDCOMPUTERWINDOW_H
#define ADDCOMPUTERWINDOW_H

#include <QDialog>
#include "computersservice.h"
#include "utilities.h"

namespace Ui {
class AddComputerWindow;
}

class AddComputerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputerWindow(QWidget *parent = 0);
    ~AddComputerWindow();

    void addComputer();
private slots:
    void on_buttonAddComputer_clicked();

private:
    Ui::AddComputerWindow *ui;
    ComputersService computersService;
    Utilities utilities;
};

#endif // ADDCOMPUTERWINDOW_H
