#ifndef WIDGETSOUHAIT_H
#define WIDGETSOUHAIT_H

#include <QWidget>

namespace Ui {
    class WidgetSouhait;
}

class WidgetSouhait : public QWidget
{
    Q_OBJECT
    
public:
    explicit WidgetSouhait(QWidget *parent = 0);
    ~WidgetSouhait();

    void setBudgetMax(unsigned int budget);
    void setSurfaceHabitableSouhaitee(unsigned int surf);
    void setSurfaceJardinSouhaitee(unsigned int surf);

    int getBudgetMax();
    int getSurfaceHabitableSouhaitee();
    int getSurfaceJardinSouhaitee();
    
private:
    Ui::WidgetSouhait *ui;
};

#endif // WIDGETSOUHAIT_H
