#ifndef BORNE_H
#define BORNE_H
#include <QString>
#include <QObject>
#include <QFile>

class Borne : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString nom READ nom NOTIFY nomChanged)
    Q_PROPERTY(QString adresse READ adresse NOTIFY adresseChanged)
    Q_PROPERTY(QString description READ description NOTIFY descriptionChanged)
    Q_PROPERTY(double latitude READ latitude NOTIFY latitudeChanged)
    Q_PROPERTY(double longitude READ longitude NOTIFY longitudeChanged)
    Q_PROPERTY(double altitude READ altitude NOTIFY altitudeChanged)
    Q_PROPERTY(QString urlImage READ urlImage NOTIFY urlImageChanged)
    Q_PROPERTY(QString urlPisteAudio READ urlPisteAudio NOTIFY urlPisteAudioChanged)
    Q_PROPERTY(QString text READ text NOTIFY textChanged)

public:
    explicit Borne(QObject *parent = 0);
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

    void operator=(const Borne &borne);

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
};

#endif // BORNE_H
