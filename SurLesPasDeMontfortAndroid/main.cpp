#include <QApplication>
#include "fenetresite.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
/*
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
*/

    FenetreSite fenetre;
    fenetre.start();
    return app.exec();
}
