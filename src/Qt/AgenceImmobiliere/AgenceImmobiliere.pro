#-------------------------------------------------
#
# Project created by QtCreator 2012-05-13T07:05:10
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += xml

TARGET = AgenceImmobiliere
TEMPLATE = app


SOURCES += main.cpp\
    dialogaccueil.cpp \
    dialogclient.cpp \
    dialogbien.cpp \
    dialogsouhait.cpp \
    BDD.cpp \
    Parametre.cpp \
    widgetclient.cpp
    # mainwindow.cpp \

HEADERS  +=     dialogaccueil.h \
    dialogclient.h \
    dialogbien.h \
    dialogsouhait.h \
    BDD.h \
    Parametre.h \
    widgetclient.h
    # mainwindow.h \

FORMS    += mainwindow.ui \
    barreMenuFiche.ui \
    accueilResultat.ui \
    dialogaccueil.ui \
    dialogclient.ui \
    dialogbien.ui \
    dialogsouhait.ui \    
    souhait.ui \
    listeSouhaits.ui \
    listeBiens.ui \
    bien.ui \
    widgetclient.ui

RESOURCES += \
    ressources.qrc
