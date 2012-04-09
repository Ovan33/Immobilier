#ifndef MONCOMPOSANT_H
#define MONCOMPOSANT_H

#include <QWidget>

namespace Ui {
    class MonComposant;
}

class MonComposant : public QWidget
{
    Q_OBJECT

public:
    explicit MonComposant(QWidget *parent = 0);
    ~MonComposant();

private:
    Ui::MonComposant *ui;
};

#endif // MONCOMPOSANT_H
