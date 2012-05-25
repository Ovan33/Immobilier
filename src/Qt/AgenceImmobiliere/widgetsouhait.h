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
    QPushButton* getBoutonSupprimer();
    
private:
    Ui::WidgetSouhait *ui;
    Souhait *m_souhait;

    QList<Ville *> m_listeVilles;
};

#endif // WIDGETSOUHAIT_H
