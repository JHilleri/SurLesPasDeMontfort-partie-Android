#ifndef GPS_H
#define GPS_H
#include <QGeoPositionInfoSource>
#include <QObject>
#include "config.h"


class GPS :public QObject
{
    Q_OBJECT
public:
    GPS(QObject *parent = 0);
    ~GPS();
signals:
    void nouvellePosition(QGeoPositionInfo position);
public slots:
    void positionUpdated(const QGeoPositionInfo &position);
private:
    QGeoPositionInfoSource *m_source;
};

#endif // GPS_H

