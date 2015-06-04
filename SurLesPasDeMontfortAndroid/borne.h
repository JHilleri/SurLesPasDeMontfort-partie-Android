#ifndef BORNE_H
#define BORNE_H
#include <QString>
#include <QObject>
#include <QFile>
#include <QGeoCoordinate>
#include <QDomElement>
#include <QUrl>

#include "config.h"


class Borne : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString nom READ nom WRITE setNom NOTIFY nomChanged)
    Q_PROPERTY(QString adresse READ adresse WRITE setAdresse NOTIFY adresseChanged)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged)
    Q_PROPERTY(double latitude READ latitude WRITE setLatitude NOTIFY latitudeChanged)
    Q_PROPERTY(double longitude READ longitude WRITE setLongitude NOTIFY longitudeChanged)
    Q_PROPERTY(double altitude READ altitude WRITE setAltitude NOTIFY altitudeChanged)
    Q_PROPERTY(QString urlImage READ urlImage WRITE setUrlImage NOTIFY urlImageChanged)
    Q_PROPERTY(QString urlPisteAudio READ urlPisteAudio WRITE setUrlPisteAudio NOTIFY urlPisteAudioChanged)
    Q_PROPERTY(QString text READ text WRITE setUrlText NOTIFY textChanged)
    Q_PROPERTY(bool urlPisteAudioEstValid READ urlPisteAudioEstValid NOTIFY urlPisteAudioEstValidChanged)


public:
    explicit Borne(QObject *parent = 0);
    Borne( QDomElement &element,QObject *parent = 0);
    ~Borne();

    QString nom()const;
    QString adresse()const;
    QString description()const;
    double latitude()const;
    double longitude()const;
    double altitude()const;
    QString urlImage()const;
    QString urlPisteAudio()const;
    QString text()const;
    QString urlText()const;

    double distanceTo(const QGeoCoordinate &coordonees);

    void operator=(const Borne &borne);
    bool operator ==( const Borne &borne2)const;

    bool urlPisteAudioEstValid()const;


signals:
    void nomChanged();
    void adresseChanged();
    void descriptionChanged();
    void latitudeChanged();
    void longitudeChanged();
    void altitudeChanged();
    void urlImageChanged();
    void urlPisteAudioChanged();
    void textChanged();
    void urlPisteAudioEstValidChanged();

public slots:
     void setNom(QString nom);
     void setAdresse(QString adresse);
     void setDescription(QString description);
     void setLatitude(double latitude);
     void setLongitude(double longitude);
     void setAltitude(double altitude);
     void setUrlImage(QString urlImage);
     void setUrlPisteAudio(QString urlPisteAudio);
     void setUrlText(QString urlText);

     void testUrlPisteAudio();

private:
    QString m_nom;
    QString m_adresse;
    QString m_description;
    double m_latitude;
    double m_longitude;
    double m_altitude;
    QString m_urlImage;
    QString m_urlPisteAudio;
    QString m_urlText;
    bool m_urlPisteAudioEstValid;


};

#endif // BORNE_H
