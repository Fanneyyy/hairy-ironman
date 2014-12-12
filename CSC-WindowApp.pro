#-------------------------------------------------
#
# Project created by QtCreator 2014-12-11T13:18:19
#
#-------------------------------------------------

QT       += core gui sql webkitwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CSC-WindowApp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    computer.cpp \
    computerrepository.cpp \
    computersservice.cpp \
    connection.cpp \
    connectionsrepository.cpp \
    connectionsservice.cpp \
    person.cpp \
    personsrepository.cpp \
    personsservice.cpp \
    readperson.cpp \
    search.cpp \
    sort.cpp \
    addpersonwindow.cpp \
    addcomputerwindow.cpp

HEADERS  += mainwindow.h \
    computer.h \
    computerrepository.h \
    computersservice.h \
    connection.h \
    connectionsrepository.h \
    connectionsservice.h \
    person.h \
    personsrepository.h \
    personsservice.h \
    readperson.h \
    search.h \
    sort.h \
    addpersonwindow.h \
    addcomputerwindow.h

FORMS    += mainwindow.ui \
    addpersonwindow.ui \
    addcomputerwindow.ui
