#-------------------------------------------------
#
# Project created by QtCreator 2014-11-27T13:27:07
#
#-------------------------------------------------

QT       += core
QT       += sql
QT       -= gui

TARGET = QtPersons
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    person.cpp \
    consoleui.cpp \
    search.cpp \
    sort.cpp \
    computer.cpp \
    printui.cpp \
    computerrepository.cpp \
    personsrepository.cpp \
    personsservice.cpp

HEADERS += \
    person.h \
    consoleui.h \
    search.h \
    sort.h \
    computer.h \
    printui.h \
    computerrepository.h \
    personsrepository.h \
    personsservice.h

OTHER_FILES += \
    README.txt \
    Persons.sql \
    TheTestCabinet.sqlite
