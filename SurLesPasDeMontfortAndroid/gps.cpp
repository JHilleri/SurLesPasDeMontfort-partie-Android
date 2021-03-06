#include "gps.h"

/*!
  \class GPS
  \brief La classe GPS fournit la position GPS de l'utilisateur
  \inmodule Parcours
 */

/*!
 * \brief Met en place le GPS.
 */
GPS::GPS(QObject *parent):QObject(parent)
{
    m_source = QGeoPositionInfoSource::createDefaultSource(0);
    m_source->setUpdateInterval(GPS_UPDATE_INTERVAL);
    m_source->startUpdates();
    connect(m_source,SIGNAL(positionUpdated(const QGeoPositionInfo &)),this,SLOT(positionUpdated(const QGeoPositionInfo &)));
}

GPS::~GPS()
{
    delete m_source;
}

void GPS::positionUpdated(const QGeoPositionInfo &position)
{
    emit nouvellePosition(position);
    if(GPS_VERBOSE){qDebug("reception d'une nouvelle position");}
}
