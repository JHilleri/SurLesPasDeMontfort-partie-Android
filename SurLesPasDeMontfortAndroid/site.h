#ifndef SITE_H
#define SITE_H

#include <QObject>
#include <QStringList>
#include <QString>
#include "borne.h"
#include "foncteurs.h"


/*
class Site : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<Borne *> liste READ liste WRITE setListe NOTIFY listeChanged)
public:
    explicit Site(QObject *parent = 0);
    //Site(const Site&site);
    ~Site();
    void ajouter(Borne *nouvelleBorne);
    QStringList getNames();
    void clear();
    Borne *getBorneByName(QString name);
    QList<Borne *> liste() const;
signals:
    void siteChanged();
    void listeChanged();
public slots:
    void setListe(QList<Borne *> nouvelleListe);
private:

    QList<Borne *> m_liste;
};
*/

class Site : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject *> liste READ liste NOTIFY listeChanged)
public:
    explicit Site(QObject *parent = 0);
    ~Site();

    const QList<QObject *> &liste() const;
    void ajouterBorne(Borne *borne);
    Borne *getBorneByName(QString nom);
signals:
    void listeChanged();
public slots:
    void clear();
private:
    QList<QObject *> m_liste;
};

#endif // SITE_H
