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
    Ville.cpp \
    Client.cpp \
    Bien.cpp \
    Immo.cpp \
    Proprietaire.cpp \
    # Acheteur.cpp \
    Souhait.cpp \
    dialogclient.cpp

HEADERS  += \
    BDD.h \
    Parametre.h \
    Ville.h \
    Client.h \
    Bien.h \
    Immo.h \
    Proprietaire.h \
    # Acheteur.h \
    Souhait.h \
    dialogclient.h

FORMS    += immo.ui \
    # UI_WIDGET_barreMenuFiche.ui \
    # UI_Client.ui
    dialogclient.ui

RESOURCES += \
    ressources.qrc
