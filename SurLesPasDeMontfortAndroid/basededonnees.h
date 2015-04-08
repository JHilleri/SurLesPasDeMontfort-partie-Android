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
#include "config.h"

class BaseDeDonnees
{
public:
    BaseDeDonnees();
    ~BaseDeDonnees();

    void ajouterEnregistrement(Borne *borne);
    void remplirSite(Site *site);

    void clear();

protected:
    void creationTables();
    QSqlDatabase m_baseDeDonnees;
};

#endif // BASEDEDONNEES_H
