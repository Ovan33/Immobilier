#ifndef SQL_GUI_H
#define SQL_GUI_H

#include <QtSql>
#include <QTableView>

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>


namespace Ui {
    class SQL_GUI;
}

class SQL_GUI : public QMainWindow
{
    Q_OBJECT

public:
    explicit SQL_GUI(QWidget *parent = 0);
    ~SQL_GUI();

private slots:
    void actionNouveau_Client();



private:
    Ui::SQL_GUI *ui;
    QSqlDatabase db;

    void connexionBDD();
    void requeteVille();
    void remplissageTV();
    void requeteClient();
    void TVClient();
    void requeteNewClient();
    void requeteNewClient2();


};

#endif // SQL_GUI_H
