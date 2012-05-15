#-------------------------------------------------
#
# Project created by QtCreator 2012-05-13T07:05:10
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT      += xml

TARGET = AgenceImmobiliere
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialogaccueil.cpp \
    dialogclient.cpp \
    dialogbien.cpp \
    dialogsouhait.cpp \
    BDD.cpp \
    Parametre.cpp

HEADERS  += mainwindow.h \
    dialogaccueil.h \
    dialogclient.h \
    dialogbien.h \
    dialogsouhait.h \
    BDD.h \
    Parametre.h

FORMS    += mainwindow.ui \
    barreMenuFiche.ui \
    dialogaccueil.ui \
    dialogclient.ui \
    dialogbien.ui \
    dialogsouhait.ui

RESOURCES += \
    ressources.qrc
