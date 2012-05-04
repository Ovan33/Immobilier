#-------------------------------------------------
#
# Project created by QtCreator 2012-03-27T11:09:06
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += xml

CONFIG       += console

TARGET = Immo
TEMPLATE = app


SOURCES += main.cpp\
    BDD.cpp \
    Parametre.cpp \
    Immo.cpp \
    Ville.cpp

HEADERS  += \
    BDD.h \
    Immo.h \
    Parametre.h \
    Ville.h

FORMS    += immo.ui
