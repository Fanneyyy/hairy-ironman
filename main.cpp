#include "consoleui.h"
#include <string>
#include <QtSql>
#include <vector>
#include <QtDebug>
#include "person.h"

int main()
{
    ConsoleUI ui;
    QSqlDatabase db;
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbname = "TheTestCabinet.sqlite";
    db.setDatabaseName(dbname);

    if(db.open()) {
        qDebug() << "Opened!";
    } else {
        qDebug() << "Error = " << db.lastError().text();
    }

    QSqlQuery query;
    vector<Person> persons;

    query.exec("SELECT * FROM Person");

    while(query.next()) {
        Person p = Person();

        p.setFirstName(query.value("Name").toString().toStdString());
        persons.push_back(p);
    }

    for(unsigned int i = 0; i < persons.size(); i++) {
        std::cout << "The name: " << persons[i].getFirstName() << endl;
    }

    ui.initialSetUp();
    ui.choose();

    return 0;
}
