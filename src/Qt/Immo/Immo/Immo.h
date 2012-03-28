#ifndef IMMO_H
#define IMMO_H

#include <QMainWindow>


namespace Ui {
    class Immo;
}

class Immo : public QMainWindow
{
    Q_OBJECT

public:
    explicit Immo(QWidget *parent = 0);

    ~Immo();

private:
    Ui::Immo *ui;

};

#endif // IMMO_H
