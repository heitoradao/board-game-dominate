#!qmake
# Project created by Heitor Adão Júnior 2012-07-05

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

#TARGET = Dominate
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui

TRANSLATIONS = pt.ts es.ts
