#ifndef DIALOGBIEN_H
#define DIALOGBIEN_H

#include <QDialog>

namespace Ui {
    class DialogBien;
}

class DialogBien : public QDialog
{
    Q_OBJECT

public:
    explicit DialogBien(QWidget *parent = 0);
    ~DialogBien();

private:
    Ui::DialogBien *ui;
};

#endif // DIALOGBIEN_H
