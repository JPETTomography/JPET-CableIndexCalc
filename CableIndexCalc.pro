QMAKE_CXXFLAGS+= -std=c++11
QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = CableIndexCalc
TEMPLATE = app
SOURCES += main.cpp mainwindow.cpp
HEADERS  += mainwindow.h
FORMS    += mainwindow.ui
