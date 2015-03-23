#include <QApplication>
#include "fenetre.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    Fenetre fenetre;
    fenetre.start();
    return app.exec();
}
