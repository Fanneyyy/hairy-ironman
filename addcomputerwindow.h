#ifndef ADDCOMPUTERWINDOW_H
#define ADDCOMPUTERWINDOW_H

#include <QDialog>
#include "computersservice.h"

namespace Ui {
class AddComputerWindow;
}

class AddComputerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddComputerWindow(QWidget *parent = 0);
    ~AddComputerWindow();

    bool linesAreValid();
    void addComputer();
private slots:

    void on_buttonAddComputer_clicked();

private:
    Ui::AddComputerWindow *ui;
    ComputersService computersService;
};

#endif // ADDCOMPUTERWINDOW_H
