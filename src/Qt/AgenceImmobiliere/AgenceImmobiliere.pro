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
    Client.cpp \
    Ville.cpp \
    widgetclient.cpp \
    dialoglistebiens.cpp \
    widgetbien.cpp \
    dialogrecherchebiens.cpp \
    Bien.cpp \
    Souhait.cpp \
    widgetsouhait.cpp \
    dialoglistesouhait.cpp \
    dialoglisterecherchesouhaits.cpp \
#    Agent.cpp \
#    widgetagent.cpp

HEADERS  +=     dialogaccueil.h \
    dialogclient.h \
    dialogbien.h \
    dialogsouhait.h \
    BDD.h \
    Parametre.h \
    Client.h \
    Ville.h \
    widgetclient.h \
    dialoglistebiens.h \
    widgetbien.h \
    dialogrecherchebiens.h \
    Bien.h \
    Souhait.h \
    widgetsouhait.h \
    dialoglistesouhait.h \
    dialoglisterecherchesouhaits.h \
#    Agent.h \
#    widgetagent.h

FORMS    += mainwindow.ui \
    barreMenuFiche.ui \
    accueilResultat.ui \
    dialogaccueil.ui \
    dialogclient.ui \
    dialogbien.ui \
    dialogsouhait.ui \    
    souhait.ui \
    widgetclient.ui \
    dialoglistebiens.ui \
    dialogrecherchebiens.ui \
    widgetbien.ui \
    widgetsouhait.ui \
    dialoglistesouhait.ui \
    dialoglisterecherchesouhaits.ui \
#    widgetagent.ui

RESOURCES += ressources.qrc
