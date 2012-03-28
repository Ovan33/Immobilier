/********************************************************************************
** Form generated from reading UI file 'immo.ui'
**
** Created: Wed Mar 28 11:04:08 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMMO_H
#define UI_IMMO_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Immo
{
public:
    QWidget *centralWidget;
    QTextEdit *textEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Immo)
    {
        if (Immo->objectName().isEmpty())
            Immo->setObjectName(QString::fromUtf8("Immo"));
        Immo->resize(400, 300);
        centralWidget = new QWidget(Immo);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        textEdit = new QTextEdit(centralWidget);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setGeometry(QRect(40, 50, 301, 171));
        Immo->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Immo);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        Immo->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Immo);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        Immo->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(Immo);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        Immo->setStatusBar(statusBar);

        retranslateUi(Immo);

        QMetaObject::connectSlotsByName(Immo);
    } // setupUi

    void retranslateUi(QMainWindow *Immo)
    {
        Immo->setWindowTitle(QApplication::translate("Immo", "Immo", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Immo: public Ui_Immo {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMMO_H
