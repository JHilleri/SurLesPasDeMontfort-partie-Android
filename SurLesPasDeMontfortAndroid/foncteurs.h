#ifndef FONCTEURS
#define FONCTEURS
#include <QGeoPositionInfo>
#include <QVariant>
#include "borne.h"
#include "config.h"

class FoncteurTestNomBorne
{
public:
    FoncteurTestNomBorne(QString nom);
    bool operator()(QObject * const borne);
private:
    QString m_nom;
};

class FoncteurTestPosition
{
public:
    FoncteurTestPosition(const QGeoCoordinate &coordonnees);
    void operator()(QObject * const borne);
    Borne *borneLaPlusProche()const;
private:
    const QGeoCoordinate &m_coordonnees;
    Borne *m_borneLaPlusproche;
    double m_distanceMin;
};

#endif // FONCTEURS
