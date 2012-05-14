#-------------------------------------------------
#
# Project created by QtCreator 2012-05-13T07:05:10
#
#-------------------------------------------------

QT       += core gui

TARGET = AgenceImmobiliere
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    dialogaccueil.cpp \
    dialogclient.cpp \
    dialogbien.cpp \
    dialogsouhait.cpp

HEADERS  += mainwindow.h \
    dialogaccueil.h \
    dialogclient.h \
    dialogbien.h \
    dialogsouhait.h

FORMS    += mainwindow.ui \
    barreMenuFiche.ui \
    dialogaccueil.ui \
    dialogclient.ui \
    dialogbien.ui \
    dialogsouhait.ui

RESOURCES += \
    ressources.qrc
