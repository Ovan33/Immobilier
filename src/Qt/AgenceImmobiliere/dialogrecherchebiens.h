#ifndef DIALOGRECHERCHEBIENS_H
#define DIALOGRECHERCHEBIENS_H

#include <QDialog>

namespace Ui {
    class DialogRechercheBiens;
}

class DialogRechercheBiens : public QDialog
{
    Q_OBJECT

public:
    explicit DialogRechercheBiens(QWidget *parent = 0);
    ~DialogRechercheBiens();

private:
    Ui::DialogRechercheBiens *ui;
};

#endif // DIALOGRECHERCHEBIENS_H
