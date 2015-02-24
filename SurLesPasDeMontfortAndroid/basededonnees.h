#ifndef BASEDEDONNEES_H
#define BASEDEDONNEES_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QStringList>
#include <QVariant>
#include <QSqlResult>

#include "borne.h"
#include "site.h"

class BaseDeDonnees
{
public:
    BaseDeDonnees();
    ~BaseDeDonnees();

    void ajouterEnregistrement(Borne *borne);
    void remplirTab(Site *site);
    QStringList liste();
    void setListe(QStringList liste);

protected:
    void creationTables();
    QSqlDatabase m_baseDeDonnees;
    QStringList m_liste;
};

#endif // BASEDEDONNEES_H
