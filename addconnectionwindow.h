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
    void addConnection();
private slots:
    void on_buttonPushToClose_clicked();

    void on_computerTableConnection_cellClicked(int row);

    void on_personTableConnection_cellClicked(int row);

private:
    Ui::AddConnectionWindow *ui;
    ConnectionsService connectionsService;
    PersonsService personsService;
    ComputersService computersService;
    Connection connection;
    ConnectionsRepository connectionRepo;
};

#endif // ADDCONNECTIONWINDOW_H
