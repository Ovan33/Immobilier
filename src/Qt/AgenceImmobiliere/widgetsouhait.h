#ifndef WIDGETSOUHAIT_H
#define WIDGETSOUHAIT_H

#include <QWidget>
#include <QPushButton>
#include <Souhait.h>

namespace Ui {
    class WidgetSouhait;
}

class WidgetSouhait : public QWidget
{
    Q_OBJECT
    
public:
    explicit WidgetSouhait(QWidget *parent = 0);
    WidgetSouhait(Souhait *souhait, QWidget *parent = 0);
    ~WidgetSouhait();

    void setBudgetMax(unsigned int budget);
    void setSurfaceHabitableSouhaitee(unsigned int surf);
    void setSurfaceJardinSouhaitee(unsigned int surf);

    int getBudgetMax();
    int getSurfaceHabitableSouhaitee();
    int getSurfaceJardinSouhaitee();

    QPushButton* getBoutonDialogSouhait();
    
private:
    Ui::WidgetSouhait *ui;
    Souhait *m_souhait;
};

#endif // WIDGETSOUHAIT_H
