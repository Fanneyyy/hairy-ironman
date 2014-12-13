#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    personService.setUp();
    computerService.setUp();
    QString str;
    for(int i = 0; i < personService.getSizeOfRepo(); i++) {
        str = QString::fromStdString(personService.get(i).getName());
        ui->listTab1->addItem(str);
    }
    for(int i = 0; i < computerService.getSizeOfRepo(); i++) {
        str = QString::fromStdString(computerService.get(i).getComputerName());
        ui->listTab2->addItem(str);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_listTab1_clicked(const QModelIndex &index)
{
    int currentlySelectedPersonIndex = ui->listTab1->currentIndex().row();

    //ui->labelGender->setText(personService.get(currentlySelectedPersonIndex).getGender());
    std::string selectedPersonString = personService.get(currentlySelectedPersonIndex).getGender();
    qDebug() << QString::fromStdString(selectedPersonString);
}
