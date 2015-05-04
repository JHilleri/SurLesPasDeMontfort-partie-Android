#include <QApplication>
#include <QtQuick>

#include "fenetre.h"

#include "site.h"
#include "borne.h"
#include "question.h"
#include "quizz.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<Borne>("site",1,0,"Borne");
    qmlRegisterType<Site>("site",1,0,"Site");

    qmlRegisterType<Question>("quizz",1,0,"Question");
    qmlRegisterType<Quizz>("quizz",1,0,"Quizz");

    Fenetre fenetre;
    fenetre.start();
    return app.exec();
}
