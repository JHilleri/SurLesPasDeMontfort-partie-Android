#include <QApplication>
#include <QtQuick>
#include "fenetre.h"
//#include "question.h"
#include "site.h"
#include "borne.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    //qmlRegisterType<Question>("quizz",1,0,"Question");
    qmlRegisterType<Borne>("site",1,0,"Borne");
    qmlRegisterType<Site>("site",1,0,"Site");

    Fenetre fenetre;
    fenetre.start();
    return app.exec();
}
