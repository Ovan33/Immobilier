#include <QApplication>
#include <QPushButton>

using namespace Qt;

int main (int argc, char *argv[]) {
    QApplication app(argc, argv);
    QPushButton bouton("Pouet pouet");
    bouton.setToolTip("C'est à moi que tu t'exprimes bouffon ?");
    bouton.setCursor(PointingHandCursor);
    bouton.setIcon(QIcon("smile.png"));
    bouton.show();
    return app.exec();
}
