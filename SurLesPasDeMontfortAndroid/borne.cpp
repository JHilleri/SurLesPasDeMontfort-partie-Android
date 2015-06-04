#include "borne.h"

/*!
  \class Borne
  \brief La classe Borne decrit une borne du parcours
  \inmodule Parcours
 */


/*!
 * \brief Construit une Borne et la lie a l'objet \a parent
 */
Borne::Borne(QObject *parent) : QObject(parent),m_altitude(0),m_latitude(0),m_longitude(0)
{
    connect(this,SIGNAL(urlPisteAudioChanged()),this,SLOT(testUrlPisteAudio()));
}

Borne::Borne( QDomElement &element,QObject *parent) : QObject(parent)
{
    connect(this,SIGNAL(urlPisteAudioChanged()),this,SLOT(testUrlPisteAudio()));

    // Utilisation des seters pour effectuer les tests sur la validite des donnees
    setAdresse(element.attribute("adresse",""));
    setDescription(element.attribute("description",""));
    setNom(element.attribute("nom",""));
    setUrlImage(element.attribute("urlImage",""));
    setUrlPisteAudio(element.attribute("urlPisteAudio",""));
    setUrlText(element.attribute("urlText",""));
    setAltitude(element.attribute("altitude","").toDouble());
    setLatitude(element.attribute("latitude","").toDouble());
    setLongitude(element.attribute("longitude","").toDouble());
}

Borne::~Borne()
{

}

/*!
 * \brief donne le nom de la borne
 */
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
        qDebug() << "la borne '" << m_nom << "' n'a pas de texte";
        return QString("la borne n'a pas de texte");
    }
    QFile text(m_urlText);
    if(!text.exists())
    {
        qDebug() << "le fichier texte '" << m_urlText << "' associe a la borne '" << m_nom << "' n'existe pas,";
        return QString("le fichier texte '").append(m_urlText).append("' n'existe pas,");
    }
    if(text.open(QIODevice::ReadOnly))
    {
        return QString(text.readAll());
    }
    else
    {
        qDebug() << "echec de louverture du fichier ': '" << m_urlText << "' de la borne '" << m_nom << "'";
        return QString("echec de louverture du fichier ': '").append(m_urlText).append("'");
    }
}




void Borne::setNom(QString nom)
{
    if(nom.contains("'"))return;
    m_nom=nom;
    emit nomChanged();
}

void Borne::setAdresse(QString adresse)
{
    if(adresse.contains("'"))return;
    m_adresse=adresse;
    emit adresseChanged();
}

void Borne::setDescription(QString description)
{
    if(description.contains("'"))return;
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
    if(urlImage.contains("'"))return;
    m_urlImage=urlImage;
    emit urlImageChanged();
}

void Borne::setUrlPisteAudio(QString urlPisteAudio)
{
    if(urlPisteAudio.contains("'"))return;
    m_urlPisteAudio=urlPisteAudio;
    emit urlPisteAudioChanged();
    //testUrlPisteAudio();
}

void Borne::setUrlText(QString urlText)
{
    if(urlText.contains("'"))return;
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
    this->testUrlPisteAudio();
}


double Borne::distanceTo(const QGeoCoordinate &coordonees)
{
    return coordonees.distanceTo(QGeoCoordinate(this->latitude(),this->longitude()));
}

bool Borne::operator ==(const Borne &borne2)const
{
    return ((this->adresse() == borne2.adresse())
            && this->altitude() == borne2.altitude()
            && this->description() == borne2.description()
            && this->latitude() == borne2.latitude()
            && this->longitude() == borne2.longitude()
            && this->nom() == borne2.nom()
            && this->urlText() == borne2.urlText()
            && this->urlImage() == borne2.urlImage()
            && this->urlPisteAudio() == borne2.urlPisteAudio()
            );
}

bool Borne::urlPisteAudioEstValid()const
{
    return m_urlPisteAudioEstValid;
}

void Borne::testUrlPisteAudio()
{
    if(m_urlPisteAudio.isEmpty() || !QFile(":" + QUrl(m_urlPisteAudio).path()).exists())
    {
        m_urlPisteAudioEstValid = false;
    }
    else
    {
        m_urlPisteAudioEstValid = true;
    }
    emit urlPisteAudioEstValidChanged();
}
