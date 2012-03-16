#ifndef SQL_GUI_H
#define SQL_GUI_H

#include <QMainWindow>

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

private:
    Ui::SQL_GUI *ui;

    void ConnexionBDD();
    void RequeteVille();

};

#endif // SQL_GUI_H
