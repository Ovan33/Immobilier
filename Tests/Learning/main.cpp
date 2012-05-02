#include <QApplication>
#include <QFont>
#include <QPushButton>
#include <QWidget>
#include <QLCDNumber>
#include <QGridLayout>
#include <QSlider>
#include <QVBoxLayout>

// Classe simple contenant un simple composant LCDRange
class LCDRange : public QWidget
{
public:
    LCDRange(QWidget *parent=0);
};

/* Constructeur de LCDRange contenant
   - 2 composants graphiques : un QLCDNumber et un QSlider
   - 2 layouts
        - un GridLayout de 3 lignes x 3 colonnes. Chaque cellule du GridLayout contient un LCDRange
        - Un Vertical Layout contenant un PushButton et le GridLayout
   */
LCDRange::LCDRange (QWidget *parent)
    : QWidget(parent)
{
    QLCDNumber *lcd = new QLCDNumber(2);
    lcd->setSegmentStyle(QLCDNumber::Filled);
    QSlider *slider = new QSlider(Qt::Horizontal);
    slider->setRange(0,99);
    slider->setValue(0);
    connect(slider, SIGNAL(valueChanged(int)), lcd, SLOT(display(int)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lcd);
    layout->addWidget(slider);
    setLayout(layout);
}

class MyWidget : public QWidget {
public:
    MyWidget(QWidget *parent=0);
};

MyWidget::MyWidget(QWidget *parent)
    : QWidget(parent)
{
    QPushButton *quit = new QPushButton(tr("Quitter"));
    quit->setFont(QFont("Deja Vu Sans", 18, QFont::Bold));
    connect(quit, SIGNAL(clicked()),qApp, SLOT(quit()));

    QGridLayout *grid = new QGridLayout();
    for (int row=0; row<3; ++row)
    {
        for (int column=0; column<3; ++column)
        {
            LCDRange *lcdRange =new LCDRange;
            grid->addWidget(lcdRange,row,column);
        }
    }

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(quit);
    layout->addLayout(grid);
    setLayout(layout);
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MyWidget widget;

    widget.show();

    return app.exec();
}
