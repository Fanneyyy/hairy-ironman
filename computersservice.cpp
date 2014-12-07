#include "computersservice.h"

ComputersService::ComputersService() {
    db = QSqlDatabase::addDatabase("QSQLITE");
    QString dbname = "TheTestCabinet.sqlite";
    db.setDatabaseName(dbname);
}

Computer ComputersService::get(int id) {
    return computerRepo.getComputer(id);
}

// add(): adds a person to the computerRepo database.
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

void ComputersService::printAll() {
    computerRepo.headerComputerPrint();
    for(int i = 0; i < computerRepo.getComputerSize(); i++) {
        cout << computerRepo.getComputer(i);
    }
}

void ComputersService::printAllWithNumber() {
    for(int i = 0; i < computerRepo.getComputerSize(); i++) {
        cout << "Computer number: " << i+1 << endl;
        cout << computerRepo.getComputer(i);
    }
}

void ComputersService::printOne(int id) {
    cout << computerRepo.getComputer(id);
}

void ComputersService::searchAll(int theCase, string search) {
    int* ids = new int[computerRepo.getComputerSize()];
    bool computerFound = false;
    switch(theCase) {
        case 1: {
            ids = searcher.computerName(computerRepo.getAllComputer(),search);
            break;
        }
        case 2: {
            ids = searcher.type(computerRepo.getAllComputer(),search);
            break;
        }
        case 3: {
            ids = searcher.buildYear(computerRepo.getAllComputer(),search);
            break;
        }
        case 4: {
            ids = searcher.builtRnot(computerRepo.getAllComputer(),search);
            break;
        }
        default:
            break;
    }
    for(int i = 0; i < computerRepo.getComputerSize(); i++) {
        if(ids[i] == 1) {
            cout << computerRepo.getComputer(i);
            computerFound = true;
        }
    }
    if(!computerFound) {
        cout << "Sorry, nothing match your search" << endl;
    }
    delete [] ids;
}

// removeFromVector(int id): removes the person with the appropriate
// id from the computerRepo database.
void ComputersService::removeFromVector(int id) {
    computerRepo.removeComputer(id);
}

// sortAll: calls the correct sorting case and prints the results.
void ComputersService::sortAll(int theCase) {
    vector<Computer> sortedTemp = computerRepo.sortVector(computerRepo.getAllComputer(), theCase);
    for(unsigned int i = 0; i < sortedTemp.size(); i++) {
        cout << sortedTemp[i];
    }
}

int ComputersService::sizeOfDatabase() {
    return computerRepo.getComputerSize();
}

// setUp(): reads in information from a database and places it into
// the vector in the repository.
void ComputersService::setUp() {
    if(db.open()) {
        qDebug() << "Opened!";
        QSqlQuery query;
        Computer c = Computer();

        query.exec("SELECT * FROM Computer");

        while(query.next()) {
            c.setComputerName(query.value("Name").toString().toStdString());
            c.setType(query.value("Type").toString().toStdString());
            c.setBuildYear(query.value("Build year").toString().toStdString());
            if(query.value("Built?").toString().toStdString() == "TRUE") {
                c.setBuiltRnot("yes");
            } else {
                c.setBuiltRnot("no");
            }
            computerRepo.add(c);
        }
      db.close();
    } else {
        qDebug() << "Error = " << db.lastError().text();
    }
}

// UIinputCheck: validates the input for UI choices.
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

// Saves a person to the database
void ComputersService::saveComputerToDatabase(Computer c) {
    if(db.open()) {
        QSqlQuery query;
        string col = "(Name, Type, 'Build year', 'Built?')";
        string name = "('" + c.getComputerName() + "'";
        string value = ",'" + c.getType() + "','" + c.getBuildYear() + "','" + c.getBuiltRnot() + "')";
        string command = "INSERT INTO Person " + col + "VALUES " + name + value;
        QString qcommand = QString::fromUtf8(command.c_str());
        if(query.exec(qcommand)) {
            cout << "The computer has been added to the database." << endl;
        } else {
            qDebug() << "Error = " << db.lastError().text();
        }
        db.close();
    } else {
        qDebug() << "Error = " << db.lastError().text();
    }
}
