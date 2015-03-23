#ifndef GPS_H
#define GPS_H
#include <QGeoPositionInfoSource>
#include <QObject>


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
/*
MyClass(QObject *parent = 0)
      : QObject(parent)
  {
      QGeoPositionInfoSource *source = QGeoPositionInfoSource::createDefaultSource(this);
      if (source) {
          connect(source, SIGNAL(positionUpdated(QGeoPositionInfo)),
                  this, SLOT(positionUpdated(QGeoPositionInfo)));
          source->startUpdates();
      }
  }

private slots:
  void positionUpdated(const QGeoPositionInfo &info)
  {
      qDebug() << "Position updated:" << info;
  }
*/
