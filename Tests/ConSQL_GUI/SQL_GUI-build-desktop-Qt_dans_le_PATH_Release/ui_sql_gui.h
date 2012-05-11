/********************************************************************************
** Form generated from reading UI file 'sql_gui.ui'
**
** Created: Wed May 9 15:57:03 2012
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQL_GUI_H
#define UI_SQL_GUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SQL_GUI
{
public:
    QAction *actionQuitter;
    QWidget *centralWidget;
    QTableView *tableView;
    QTextEdit *FenetreInfo;
    QTextEdit *FenetreRequete;
    QWidget *widget;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SQL_GUI)
    {
        if (SQL_GUI->objectName().isEmpty())
            SQL_GUI->setObjectName(QString::fromUtf8("SQL_GUI"));
        SQL_GUI->resize(585, 526);
        actionQuitter = new QAction(SQL_GUI);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        centralWidget = new QWidget(SQL_GUI);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(110, 0, 461, 221));
        FenetreInfo = new QTextEdit(centralWidget);
        FenetreInfo->setObjectName(QString::fromUtf8("FenetreInfo"));
        FenetreInfo->setGeometry(QRect(20, 410, 561, 71));
        FenetreInfo->setLayoutDirection(Qt::LeftToRight);
        FenetreRequete = new QTextEdit(centralWidget);
        FenetreRequete->setObjectName(QString::fromUtf8("FenetreRequete"));
        FenetreRequete->setGeometry(QRect(10, 10, 91, 121));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(10, 270, 571, 121));
        SQL_GUI->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(SQL_GUI);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        SQL_GUI->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SQL_GUI);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SQL_GUI->setStatusBar(statusBar);

        retranslateUi(SQL_GUI);

        QMetaObject::connectSlotsByName(SQL_GUI);
    } // setupUi

    void retranslateUi(QMainWindow *SQL_GUI)
    {
        SQL_GUI->setWindowTitle(QApplication::translate("SQL_GUI", "SQL_GUI", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("SQL_GUI", "Quitter", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SQL_GUI: public Ui_SQL_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQL_GUI_H
