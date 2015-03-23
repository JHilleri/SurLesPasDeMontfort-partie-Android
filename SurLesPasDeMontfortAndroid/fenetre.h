#ifndef FENETRESITE_H
#define FENETRESITE_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QStringList>
#include <QtXml>
#include <QGeoPositionInfo>

#include "site.h"
#include "basededonnees.h"
#include "gps.h"

class Fenetre : public QObject
{
    Q_OBJECT
    //Q_PROPERTY(Site site READ site NOTIFY siteChanged)
    //Q_PROPERTY(Borne borneSelectionne READ borneSelectionne NOTIFY borneSelectionneChanged)
    Q_PROPERTY(bool estSurUneBorne MEMBER m_estSurUneBorne NOTIFY estSurUneBorneChanged)
    Q_PROPERTY(double latitude MEMBER m_latitude NOTIFY latitudeChanged)
    Q_PROPERTY(double longitude MEMBER m_longitude NOTIFY longitudeChanged)
    //Q_PROPERTY(type name READ name WRITE setName NOTIFY nameChanged)

public:
    explicit Fenetre(QObject *parent = 0);
    ~Fenetre();

    //void setSite( Site site);
    //const Site &site()const;
    void start();

    Borne *borneSelectionne()const;
signals:
    void siteChanged();
    void borneSelectionneChanged();
    void arruverSurBorne(Borne *borne);
    void estSurUneBorneChanged();
    void latitudeChanged();
    void longitudeChanged();
public slots:
    //Q_INVOKABLE QStringList site();
    void setBorneEnCours(QString nomBorne);

    Q_INVOKABLE void afficherCarte(QString nomBorne);
    Q_INVOKABLE void afficherItineraire(QString nomBorne);
    Q_INVOKABLE void lireSiteXML();

    void testsPosition(const QGeoPositionInfo &info);
private:
    Site m_site;
    //QStringList m_liste;
    QQmlApplicationEngine m_engine;
    BaseDeDonnees bdd;
    GPS m_gps;

    Borne borneVide;
    Borne *m_borneSelectionne;

    bool m_estSurUneBorne;
    double m_latitude,m_longitude;
};

#endif // FENETRESITE_H
