#ifndef DIALOGACCUEIL_H
#define DIALOGACCUEIL_H

#include <QDialog>

namespace Ui {
    class DialogAccueil;
}

class DialogAccueil : public QDialog
{
    Q_OBJECT

public:
    explicit DialogAccueil(QWidget *parent = 0);
    ~DialogAccueil();

private:
    Ui::DialogAccueil *ui;
};

#endif // DIALOGACCUEIL_H
