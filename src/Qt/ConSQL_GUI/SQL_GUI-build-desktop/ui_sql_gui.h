/********************************************************************************
** Form generated from reading UI file 'sql_gui.ui'
**
** Created: Sat Mar 24 10:09:48 2012
**      by: Qt User Interface Compiler version 4.7.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SQL_GUI_H
#define UI_SQL_GUI_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QTableView>
#include <QtGui/QTextEdit>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SQL_GUI
{
public:
    QWidget *centralWidget;
    QTextEdit *FenetreRequete;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QTableView *tableView;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTextEdit *FenetreInfo;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SQL_GUI)
    {
        if (SQL_GUI->objectName().isEmpty())
            SQL_GUI->setObjectName(QString::fromUtf8("SQL_GUI"));
        SQL_GUI->resize(511, 541);
        centralWidget = new QWidget(SQL_GUI);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        FenetreRequete = new QTextEdit(centralWidget);
        FenetreRequete->setObjectName(QString::fromUtf8("FenetreRequete"));
        FenetreRequete->setGeometry(QRect(10, -40, 256, 144));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(270, 0, 231, 341));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tableView = new QTableView(verticalLayoutWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));

        verticalLayout->addWidget(tableView);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(0, 390, 511, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        FenetreInfo = new QTextEdit(horizontalLayoutWidget);
        FenetreInfo->setObjectName(QString::fromUtf8("FenetreInfo"));

        horizontalLayout->addWidget(FenetreInfo);

        SQL_GUI->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SQL_GUI);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 511, 25));
        SQL_GUI->setMenuBar(menuBar);
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
    } // retranslateUi

};

namespace Ui {
    class SQL_GUI: public Ui_SQL_GUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SQL_GUI_H
