#ifndef FENETRESITE_H
#define FENETRESITE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStringList>
#include "site.h"
#include "basededonnees.h"

class FenetreSite : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QStringList site READ site WRITE setSite NOTIFY siteChanged)
public:
    explicit FenetreSite(QObject *parent = 0);
    ~FenetreSite();

    void setSite( QStringList site);
    void start();
signals:
    void siteChanged();
public slots:
    Q_INVOKABLE QStringList site();
private:
    Site *m_site;
    QStringList m_liste;
     QQmlApplicationEngine m_engine;
     BaseDeDonnees bdd;
};

#endif // FENETRESITE_H
