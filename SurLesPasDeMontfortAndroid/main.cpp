#include <QApplication>
#include "fenetresite.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    FenetreSite fenetre;
    fenetre.start();
    return app.exec();
}
