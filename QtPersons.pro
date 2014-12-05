#-------------------------------------------------
#
# Project created by QtCreator 2014-11-27T13:27:07
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = QtPersons
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    person.cpp \
    consoleui.cpp \
    search.cpp \
    service.cpp \
    sort.cpp \
    repository.cpp

HEADERS += \
    person.h \
    consoleui.h \
    search.h \
    service.h \
    sort.h \
    repository.h

OTHER_FILES += \
    choose-ui.txt \
    print-ui.txt \
    search.txt \
    sort-ui.txt \
    welcome.txt \
    database.txt \
    add-ui.txt \
    README.txt \
    Persons.sql
