#include "foncteurs.h"


FoncteurTestNomBorne::FoncteurTestNomBorne(QString nom):m_nom(nom)
{}

bool FoncteurTestNomBorne::operator ()( QObject * const borne)
{
    return (borne->property("nom") == m_nom);
}

FoncteurTestPosition::FoncteurTestPosition(const QGeoCoordinate &coordonnees):m_coordonnees(coordonnees),m_borneLaPlusproche(NULL),m_distanceMin(SENSIBILITE_DETECTION_ZONE + 1){}

void FoncteurTestPosition::operator()(QObject * const borne)
{
    double distance = ((Borne *)borne)->distanceTo(m_coordonnees);

    if(m_borneLaPlusproche == NULL)
    {
        m_distanceMin = distance;
        m_borneLaPlusproche = (Borne *)borne;
    }
    else
    {
        if(distance < m_distanceMin)
        {
            m_distanceMin = distance;
            m_borneLaPlusproche = (Borne *)borne;
        }
    }

    if(CALCULEDISTANCE_VERBOSE){
        QString debug("distance avec la borne ");
        debug.append(borne->property("nom").toString());
        debug.append(" = ");
        debug.append(QString::number(distance));
        qDebug() << debug;
    }
}

Borne *FoncteurTestPosition::borneLaPlusProche()const
{
    if(m_distanceMin <= SENSIBILITE_DETECTION_ZONE)// si m_borneLaPlusproche == NULL return NULL
    {
        return m_borneLaPlusproche;
    }
    else
    {
        return NULL;
    }
}
