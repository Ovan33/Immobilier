#ifndef MONWIDGET_H
#define MONWIDGET_H

#include <QDialog>

namespace Ui {
    class MonWidget;
}

class MonWidget : public QDialog {
    Q_OBJECT
public:
    MonWidget(QWidget *parent = 0);
    ~MonWidget();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MonWidget *ui;
};

#endif // MONWIDGET_H
