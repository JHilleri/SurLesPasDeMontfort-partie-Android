#ifndef SITE_H
#define SITE_H
#include <QStringList>
#include <QString>
#include "borne.h"


class Site
{
public:
    Site();
    ~Site();
    void ajouter(Borne *nouvelleBorne);
    QStringList getNames();
    void clear();
private:
    QList<Borne *> m_liste;
};

#endif // SITE_H
