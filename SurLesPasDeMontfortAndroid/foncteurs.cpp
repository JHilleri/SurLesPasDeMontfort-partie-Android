#include "foncteurs.h"


FoncteurTestNomBorne::FoncteurTestNomBorne(QString nom):m_nom(nom)
{}

bool FoncteurTestNomBorne::operator ()( QObject * const borne)
{
    //return (borne->nom() == m_nom);
    return (borne->property("nom") == m_nom);
}

FoncteurTestPosition::FoncteurTestPosition(const QGeoPositionInfo &info):m_info(info){}

bool FoncteurTestPosition::operator()(QObject * const borne)
{
    //return (borne->property("longitude") == m_info.coordinate().longitude()&& borne->property("latitude") == m_info.coordinate().latitude()&& borne->property("altitude") == m_info.coordinate().altitude());
    return (m_info.coordinate().distanceTo(QGeoCoordinate(borne->property("latitude").toDouble(),borne->property("longitude").toDouble(),borne->property("altitude").toDouble()))>= 5);
}
