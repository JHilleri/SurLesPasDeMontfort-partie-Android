#ifndef BASEDEDONNEES_H
#define BASEDEDONNEES_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStringList>
#include <QVariant>
#include <QSqlResult>

#include "config.h"

#include "borne.h"
#include "site.h"

#include "question.h"
#include "quizz.h"

class BaseDeDonnees
{
public:
    BaseDeDonnees();
    ~BaseDeDonnees();

    void ajouterEnregistrement(Borne *borne);
    void ajouterQuestion(Question *question);
    void remplirSite(Site *site);
    void remplirQuizz(Quizz *quizz, QString nomBorne);

    void clear();

protected:
    void creationTables();
    QSqlDatabase m_baseDeDonnees;
    QSqlQuery *m_queryAjouterBorne;
    QSqlQuery *m_queryAjouterQuestion;
};

#endif // BASEDEDONNEES_H
