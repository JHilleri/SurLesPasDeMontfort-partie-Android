#ifndef FENETRESITE_H
#define FENETRESITE_H

#include <QObject>

#include <QtQuick>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QtXml>

#include <QGeoPositionInfo>
#include <QDesktopServices>

#include <QString>

#include <algorithm>

#include "site.h"
#include "basededonnees.h"
#include "gps.h"
#include "config.h"
#include "quizz.h"
#include "question.h"

class Fenetre : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool estSurUneBorne MEMBER m_estSurUneBorne NOTIFY estSurUneBorneChanged)
    Q_PROPERTY(double latitude MEMBER m_latitude NOTIFY latitudeChanged)
    Q_PROPERTY(double longitude MEMBER m_longitude NOTIFY longitudeChanged)
    Q_PROPERTY(QString nomPosition READ nomPosition NOTIFY nomPositionChanged)

    Q_PROPERTY(Borne* borneSelectionne READ borneSelectionne WRITE setBorneSelectionne NOTIFY borneSelectionneChanged)
    Q_PROPERTY(Borne* borneAProximite READ borneAProximite WRITE setBorneAProximite NOTIFY borneAProximiteChanged)
    Q_PROPERTY(Site* site READ site NOTIFY siteChanged)
    Q_PROPERTY(Quizz* quizz READ quizz NOTIFY quizzChanged)

public:
    explicit Fenetre(QObject *parent = 0);
    ~Fenetre();

    void start();

    Borne *borneSelectionne()const;
    Borne *borneAProximite()const;
    QString nomPosition()const;
    Site *site();
    Quizz *quizz();

signals:
    void siteChanged();
    void borneSelectionneChanged();
    void arriverSurBorne(Borne *borne);
    void estSurUneBorneChanged();
    void latitudeChanged();
    void longitudeChanged();
    void nomPositionChanged();
    void borneAProximiteChanged();
    void quizzChanged();

public slots:

    Q_INVOKABLE void afficherCarte(QString nomBorne);
    Q_INVOKABLE void afficherItineraire(QString nomBorne);
    Q_INVOKABLE void lireXML();

    void testsPosition(QGeoPositionInfo &info);

    Q_INVOKABLE void setBorneSelectionne(QString nomBorne);
    Q_INVOKABLE void lireQuizz(QString nomBorne);

    void setBorneSelectionne(Borne *borneSelectionne);
    void setBorneAProximite(Borne *nouvelleBorne);

    void resetBorneSelectionne();
    void resetBorneAProximite();
private:
    Site m_site;
    Quizz m_quizz;

    QQmlApplicationEngine m_engine;
    BaseDeDonnees bdd;
    GPS m_gps;

    Borne borneVide;
    Borne *m_borneSelectionne;
    Borne *m_borneAProximite;

    bool m_estSurUneBorne;
    double m_latitude,m_longitude;
    QString m_nomPosition;
};

#endif // FENETRESITE_H
