#ifndef FONCTEURS
#define FONCTEURS
#include <QGeoPositionInfo>
#include <QVariant>
#include "borne.h"

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
    FoncteurTestPosition(const QGeoPositionInfo &info);
    bool operator()(QObject * const borne);
private:
    const QGeoPositionInfo &m_info;
};

#endif // FONCTEURS

