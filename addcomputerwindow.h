#ifndef ADDCOMPUTERWINDOW_H
#define ADDCOMPUTERWINDOW_H

#include <QDialog>

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
private slots:
    void on_lineComputerName_textChanged(const QString &arg1);

    void on_lineType_textChanged(const QString &arg1);

    void on_lineYearOfBuild_textChanged(const QString &arg1);

    void on_buttonAddComputer_clicked();

private:
    Ui::AddComputerWindow *ui;
};

#endif // ADDCOMPUTERWINDOW_H
