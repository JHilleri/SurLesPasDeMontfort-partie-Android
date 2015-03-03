#ifndef SITE_H
#define SITE_H
#include <QStringList>
#include <QString>
#include "borne.h"


class TestNomBorne
{
public:
    TestNomBorne(QString nom);
    bool operator()(Borne * const borne);
private:
    QString m_nom;
};

class Site
{
public:
    Site();
    ~Site();
    void ajouter(Borne *nouvelleBorne);
    QStringList getNames();
    void clear();
    Borne *getBorneByName(QString name);
private:
    QList<Borne *> m_liste;
};

#endif // SITE_H
