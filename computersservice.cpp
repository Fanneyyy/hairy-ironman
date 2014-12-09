#include "computersservice.h"

ComputersService::ComputersService() {
}

// get: returns the computer with the id within the vector
// (not necessarily the same as the database id)
Computer ComputersService::get(int id) {
    return computerRepo.getComputer(id);
}

// add(): adds a computer to the computerRepo database.
void ComputersService::add() {
    Computer computer;
    char c;

    do {
        cin >> computer;
        computerRepo.add(computer);
        saveComputerToDatabase(computer);
        cout << "Want to add another? (y/n?) ";
        cin >> c;
    } while(c != 'N' && c != 'n');
}

vector<Computer> ComputersService::getAll() {
    return computerRepo.getAllComputer();
}

int ComputersService::getSizeOfRepo() {
    return computerRepo.getComputerSize();
}

void ComputersService::printAll() {
    for(int i = 0; i < computerRepo.getComputerSize(); i++) {
        cout << computerRepo.getComputer(i);
    }
}

void ComputersService::printAllWithNumber() {
    for(int i = 0; i < computerRepo.getComputerSize(); i++) {
        cout << left << setw(3) << i+1;
        cout << computerRepo.getComputer(i);
    }
}

int ComputersService::sizeOfDatabase() {
    return computerRepo.getComputerSize();
}

// inputCheck(input, max): checks if the input is between 0 and max
bool ComputersService::UIinputCheck(int input, int maxcases) {
    if(cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        input = -1;
    }

    if(input < 0 || input > maxcases) {
        cout << "Wrong input, please try again" << endl;
        return false;
    }
    return true;
}

// getDatabaseConnection(): checks if a connection has already been made
// and connects to it if it has but otherwise makes a new connection
QSqlDatabase ComputersService::getDatabaseConnection() {
    QString connectionName = "ComputerConnection";
    QSqlDatabase db;

    if(QSqlDatabase::contains(connectionName)) {
        db = QSqlDatabase::database(connectionName);
    }
    else {
        db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
        db.setDatabaseName("TheTestCabinet.sqlite");
        db.open();
    }
    return db;
}

// setUp(): reads in information from a database and places it into
// the vector in the repository.
void ComputersService::setUp() {
    db = getDatabaseConnection();
    Computer c = Computer();
    QSqlQuery query(QSqlDatabase::database("ComputerConnection"));

    query.exec("SELECT * FROM Computer");

    while(query.next()) {
        c.setID(query.value("ID").toString().toStdString());
        c.setComputerName(query.value("Name").toString().toStdString());
        c.setType(query.value("Type").toString().toStdString());
        c.setBuildYear(query.value("Build year").toString().toStdString());
        c.setBuiltRnot(query.value("Built?").toString().toStdString());
        computerRepo.add(c);
    }
    db.close();
}

// Saves a computer to the database
void ComputersService::saveComputerToDatabase(Computer c) {
    db = getDatabaseConnection();

    if(db.open()) {
        QSqlQuery query(QSqlDatabase::database("ComputerConnection"));
        string col = "(Name, Type, 'Build year', 'Built?')";
        string name = "('" + c.getComputerName() + "'";
        string value = ",'" + c.getType() + "','" + c.getBuildYear() + "','" + c.getBuiltRnot() + "')";
        string command = "INSERT INTO Computer " + col + "VALUES " + name + value;
        QString qcommand = QString::fromUtf8(command.c_str());

        if(query.exec(qcommand)) {
            cout << "The computer has been added to the database." << endl;
        } else {
            qDebug() << "Error = " << db.lastError().text();
        }
    } else {
        qDebug() << "Error = " << db.lastError().text();
    }
    db.close();
}
