#ifndef DIALOGSOUHAIT_H
#define DIALOGSOUHAIT_H

#include <QDialog>

namespace Ui {
    class DialogSouhait;
}

class DialogSouhait : public QDialog
{
    Q_OBJECT

public:
    explicit DialogSouhait(QWidget *parent = 0);
    ~DialogSouhait();

private:
    Ui::DialogSouhait *ui;
};

#endif // DIALOGSOUHAIT_H
