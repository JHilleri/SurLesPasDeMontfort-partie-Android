#include "fenetre.h"
#include <QString>
#include <QDesktopServices>
#include <algorithm>

Fenetre::Fenetre(QObject *parent) : QObject(parent),m_borneSelectionne(&borneVide)
{
    //m_site = new Site;
/*
    bdd.ajouterEnregistrement(new Borne("Le calvaire symbole monfortain","St Laurent sur sevre","calvaire","46.9672881,-0.898719,15z",":/textes/TextCalvaire.txt"));
    bdd.ajouterEnregistrement(new Borne("Chapelle de la Sagesse","St Laurent sur sevre","chapelle","",""));
    bdd.ajouterEnregistrement(new Borne("Maison longue","St Laurent sur sevre","maison","",""));
    bdd.ajouterEnregistrement(new Borne("Pont Eiffel","St Laurent sur sevre","maison","",""));

    bdd.ajouterEnregistrement(new Borne("Saint-Gabriel","St Laurent sur sevre", "st gab", "",":/textes/SaintGab.txt"));
*/
    bdd.remplirTab(&m_site);
    //this->setSite( m_site.getNames());
    connect(&m_gps,SIGNAL(nouvellePosition(QGeoPositionInfo)),this,SLOT(testsPosition(QGeoPositionInfo)));
}

void Fenetre::start()
{
    m_engine.rootContext()->setContextProperty("fenetre",this);
    m_engine.rootContext()->setContextProperty("site",QVariant::fromValue(&(this->m_site)));
    m_engine.rootContext()->setContextProperty("borneSelectionne",QVariant::fromValue(m_borneSelectionne));

    //qDebug(QString::number(m_liste.size()).toStdString().c_str() );
    m_engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
}

Fenetre::~Fenetre(){}

/*
QStringList Fenetre::site()
{
    return m_liste;
}
*/
/*
void Fenetre::setSite(Site site)
{
    if(m_site.liste() != site.liste())
    {
        m_site.setListe(site.liste());
        emit siteChanged();
    }
}*/

void Fenetre::setBorneEnCours(QString nomBorne)
{
    //m_engine.rootContext()->setContextProperty("borne",this->m_site.getBorneByName(nomBorne));
    if(nomBorne == m_borneSelectionne->nom())return;
    if(nomBorne == "")
    {
        *m_borneSelectionne = borneVide;
    }
    else
    {
        *m_borneSelectionne = *(m_site.getBorneByName(nomBorne));
    }
    emit borneSelectionneChanged();
}

void Fenetre::lireSiteXML()
{
    bdd.clear();
    QDomDocument doc("Site_xml");
    QFile fichier(":/data/Site.xml");
    if (!fichier.open(QIODevice::ReadOnly))
         return;
     if (!doc.setContent(&fichier)) {
         fichier.close();
         return;
     }
     fichier.close();
     QDomElement racine = doc.documentElement();
     QDomNode i = racine.firstChild();
     QDomElement element;
     Borne *nouvelleBorne;
     QString messageDebug;
     while(!i.isNull())
     {
         element = i.toElement();
         
         nouvelleBorne = new Borne;
         nouvelleBorne->setAdresse(element.attribute("adresse",""));
         nouvelleBorne->setAltitude(element.attribute("altitude","").toDouble());
         nouvelleBorne->setDescription(element.attribute("description",""));
         nouvelleBorne->setLatitude(element.attribute("latitude","").toDouble());
         nouvelleBorne->setLongitude(element.attribute("longitude","").toDouble());
         nouvelleBorne->setNom(element.attribute("nom",""));
         nouvelleBorne->setUrlImage(element.attribute("urlImage",""));
         nouvelleBorne->setUrlPisteAudio(element.attribute("urlPisteAudio",""));
         nouvelleBorne->setUrlText(element.attribute("urlText",""));
         bdd.ajouterEnregistrement(nouvelleBorne);
         
         messageDebug.clear();
         messageDebug.append(element.attribute("adresse",""));
         messageDebug.append("," + element.attribute("altitude",""));
         messageDebug.append("," + element.attribute("description",""));
         messageDebug.append("," + element.attribute("latitude",""));
         messageDebug.append("," + element.attribute("longitude",""));
         messageDebug.append("," + element.attribute("nom",""));
         messageDebug.append("," + element.attribute("urlImage",""));
         messageDebug.append("," + element.attribute("urlPisteAudio",""));
         messageDebug.append("," + element.attribute("urlText",""));
         qDebug(messageDebug.toStdString().c_str());

         i = i.nextSibling();
     }

     bdd.remplirTab(&m_site);
     //this->setSite( m_site.getNames());
}

//http://stackoverflow.com/questions/2660201/what-parameters-should-i-use-in-a-google-maps-url-to-go-to-a-lat-lon
void Fenetre::afficherCarte(QString nomBorne)
{
    Borne *borne =  m_site.getBorneByName(nomBorne);
    QString addresseUrl("http://maps.google.com/?q=" + QString::number(borne->latitude()) + "," + QString::number(borne->longitude()));
    QDesktopServices::openUrl(QUrl(addresseUrl));
}

void Fenetre::afficherItineraire(QString nomBorne)
{
    Borne *borne =  m_site.getBorneByName(nomBorne);
    QString addresseUrl("http://maps.google.com/maps?&daddr=" + QString::number(borne->latitude()) + "," + QString::number(borne->longitude()));
    QDesktopServices::openUrl(QUrl(addresseUrl));
}


void Fenetre::testsPosition(const QGeoPositionInfo &info)
{
    qDebug("debut test positions");
    QList<QObject *>::const_iterator resultat = std::find_if(m_site.liste().begin(),m_site.liste().end(),FoncteurTestPosition(info));
    if(resultat != m_site.liste().end())
    {
        emit arruverSurBorne((Borne *)*resultat);
        m_estSurUneBorne = true;
        emit estSurUneBorneChanged();
    }



    qDebug(QString("latitude : ").append(QString::number(info.coordinate().latitude())).append(" longitude : ").append(QString::number(info.coordinate().longitude())).toStdString().c_str());
    m_latitude = info.coordinate().latitude();
    m_longitude = info.coordinate().longitude();
    emit longitudeChanged();
    emit latitudeChanged();

    qDebug("fin test positions");
}

/*
const Site &Fenetre::site() const
{
    return m_site;
}
*/

Borne *Fenetre::borneSelectionne()const
{
    return m_borneSelectionne;
}
