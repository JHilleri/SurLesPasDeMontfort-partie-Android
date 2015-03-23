#include "gps.h"

GPS::GPS(QObject *parent):QObject(parent)
{
    m_source = QGeoPositionInfoSource::createDefaultSource(0);
    m_source->setUpdateInterval(15000);
    m_source->startUpdates();
    connect(m_source,SIGNAL(positionUpdated(const QGeoPositionInfo &)),this,SLOT(positionUpdated(const QGeoPositionInfo &)));
    //this->setPreferredPositioningMethods(this->supportedPositioningMethods());
    //this->setUpdateInterval(10000);
    //this->startUpdates();
}

GPS::~GPS()
{
    delete m_source;
}

void GPS::positionUpdated(const QGeoPositionInfo &position)
{
    emit nouvellePosition(position);
    qDebug("reception d'une nouvelle position");
}
