# -------------------------------------------------
# Project created by QtCreator 2012-03-15T15:26:50
# -------------------------------------------------
QT += core \
    gui
QT += sql
TARGET = SQL_GUI
TEMPLATE = app

SOURCES += main.cpp\
        sql_gui.cpp \
    client.cpp

HEADERS  += sql_gui.h \
    client.h

FORMS    += sql_gui.ui \
    client.ui

RESOURCES += images.qrc

