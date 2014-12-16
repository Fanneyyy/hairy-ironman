#-------------------------------------------------
#
# Project created by QtCreator 2014-12-11T13:18:19
#
#-------------------------------------------------

QT       += core gui sql webkitwidgets webkit

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
    addpersonwindow.cpp \
    addcomputerwindow.cpp \
    addconnectionwindow.cpp \
    utilities.cpp

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
    addpersonwindow.h \
    addcomputerwindow.h \
    addconnectionwindow.h \
    utilities.h

FORMS    += mainwindow.ui \
    addpersonwindow.ui \
    addcomputerwindow.ui \
    addconnectionwindow.ui
