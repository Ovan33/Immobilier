#ifndef TRUCVIEW_H
#define TRUCVIEW_H

#include <QDialog>

#include "truc.h"

namespace Ui {
    class TrucView;
}

class TrucView : public QDialog {
    Q_OBJECT
public:
    TrucView(Truc *t, QWidget *parent = 0);
    ~TrucView();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::TrucView *ui;

    Truc *m_truc;
};

#endif // TRUCVIEW_H
