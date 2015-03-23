#include "borne.h"


Borne::Borne(QObject *parent) : QObject(parent)
,m_altitude(0),m_latitude(0),m_longitude(0)
{}

Borne::~Borne()
{

}


QString Borne::nom()const
{
    return m_nom;
}

QString Borne::adresse()const
{
    return m_adresse;
}

QString Borne::description()const
{
    return m_description;
}

double Borne::latitude()const
{
    return m_latitude;
}

double Borne::longitude()const
{
    return m_longitude;
}

double Borne::altitude()const
{
    return m_altitude;
}

QString Borne::urlImage()const
{
    return m_urlImage;
}

QString Borne::urlPisteAudio()const
{
    return m_urlPisteAudio;
}

QString Borne::text()const
{
    if(m_urlText.isEmpty())
    {
        qDebug(QString("la borne '").append(m_nom).append("' n'a pas de text").toStdString().c_str());
        return QString();
    }
    QFile text(m_urlText);
    if(text.open(QIODevice::ReadOnly))
    {
        return QString(text.readAll());
    }
    else
    {
        qDebug(QString("echec de louverture du fichier : ").append(m_urlText).toStdString().c_str());
        return QString("");
    }
}

void Borne::setNom(QString nom)
{
    m_nom=nom;
    emit nomChanged();
}

void Borne::setAdresse(QString adresse)
{
    m_adresse=adresse;
    emit adresseChanged();
}

void Borne::setDescription(QString description)
{
    m_description=description;
    emit descriptionChanged();
}

void Borne::setLatitude(double latitude)
{
    m_latitude=latitude;
    emit latitudeChanged();
}

void Borne::setLongitude(double longitude)
{
    m_longitude=longitude;
    emit longitudeChanged();
}

void Borne::setAltitude(double altitude)
{
    m_altitude=altitude;
    emit altitudeChanged();
}

void Borne::setUrlImage(QString urlImage)
{
    m_urlImage=urlImage;
    emit urlImageChanged();
}

void Borne::setUrlPisteAudio(QString urlPisteAudio)
{
    m_urlPisteAudio=urlPisteAudio;
    emit urlPisteAudioChanged();
}

void Borne::setUrlText(QString urlText)
{
    m_urlText=urlText;
    emit textChanged();
}

QString Borne::urlText()const
{
    return m_urlText;
}

void Borne::operator=(const Borne &borne)
{
    this->setNom(borne.nom());
    this->setAdresse(borne.adresse());
    this->setDescription(borne.description());
    this->setLatitude(borne.latitude());
    this->setLongitude(borne.longitude());
    this->setAltitude(borne.altitude());
    this->setUrlImage(borne.urlImage());
    this->setUrlPisteAudio(borne.urlPisteAudio());
    this->setUrlText(borne.urlText());
}
