#-------------------------------------------------
#
# Project created by QtCreator 2014-12-11T13:18:19
#
#-------------------------------------------------

QT       += core gui sql

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
    search.cpp \
    sort.cpp

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
    sort.h

FORMS    += mainwindow.ui
