#include "fenetre.h"



Fenetre::Fenetre(QObject *parent) : QObject(parent),m_borneSelectionne(&borneVide),m_gps(this),m_site(this),m_borneAProximite(&borneVide)
{
    bdd.remplirSite(&m_site);
    connect(&m_gps,SIGNAL(nouvellePosition(QGeoPositionInfo)),this,SLOT(testsPosition(QGeoPositionInfo)));

    borneVide.setNom("pas de borne");

    QDomDocument doc("Quizz_xml");
    QFile fichier(":/data/Quizz.xml");
    QDomElement element;
    if (!fichier.open(QIODevice::ReadOnly) || !doc.setContent(&fichier))
    {
         fichier.close();
         qDebug("echec de l'ouverture du fichier xml");
         return;
     }
     fichier.close();
     element =doc.documentElement().firstChild().toElement();

     connect(&m_site,SIGNAL(listeCleared()),this,SLOT(resetBorneAProximite()));
     connect(&m_site,SIGNAL(listeCleared()),this,SLOT(resetBorneSelectionne()));
}

void Fenetre::start()
{

    m_engine.rootContext()->setContextProperty("fenetre",this);
    m_engine.load(QUrl(QStringLiteral("qrc:/qml/FenetrePrincipale.qml")));
}

Fenetre::~Fenetre(){}

void Fenetre::setBorneSelectionne(QString nomBorne)
{
    if(nomBorne == m_borneSelectionne->nom())return;
    Borne *borne = m_site.getBorneByName(nomBorne);
    if(borne != NULL)
    {
        m_borneSelectionne = borne;
    }
    else
    {
        m_borneSelectionne = &borneVide;
    }
    emit borneSelectionneChanged();
}

void Fenetre::setBorneSelectionne(Borne *borneSelectionne)
{
    m_borneSelectionne = borneSelectionne;
    emit borneSelectionneChanged();
}

void Fenetre::lireSiteXML()
{
    QDomDocument doc("Site_xml");
    QFile fichier(":/data/Site.xml");
    QDomElement racine;
    QDomNode i;
    QDomElement element;
    Borne *nouvelleBorne;


    if (!fichier.open(QIODevice::ReadOnly) || !doc.setContent(&fichier))
    {
         fichier.close();
         qDebug("echec de l'ouverture du fichier xml");
         return;
     }
     fichier.close();
     bdd.clear();
     racine = doc.documentElement();
     i = racine.firstChild();

     while(!i.isNull())
     {
         element = i.toElement();
         nouvelleBorne = new Borne(element,this);
         bdd.ajouterEnregistrement(nouvelleBorne);
         delete nouvelleBorne;

         i = i.nextSibling();
     }

     bdd.remplirSite(&m_site);
}

//http://stackoverflow.com/questions/2660201/what-parameters-should-i-use-in-a-google-maps-url-to-go-to-a-lat-lon
void Fenetre::afficherCarte(QString nomBorne)
{
    Borne *borne =  m_site.getBorneByName(nomBorne);
    if(borne->latitude() != 0.0 || borne->longitude() != 0.0 || borne->altitude() != 0.0)
    {
        QString addresseUrl("http://maps.google.com/?q=" + QString::number(borne->latitude()) + "," + QString::number(borne->longitude()));
        QDesktopServices::openUrl(QUrl(addresseUrl));
    }
}

void Fenetre::afficherItineraire(QString nomBorne)
{
    Borne *borne =  m_site.getBorneByName(nomBorne);
    if(borne->latitude() != 0.0 || borne->longitude() != 0.0 || borne->altitude() != 0.0)
    {
        QString addresseUrl("http://maps.google.com/maps?&daddr=" + QString::number(borne->latitude()) + "," + QString::number(borne->longitude()));
        QDesktopServices::openUrl(QUrl(addresseUrl));
    }
}


void Fenetre::testsPosition(const QGeoPositionInfo &info)
{
    if(FENETRE_VERBOSE){qDebug("debut test positions");}

    FoncteurTestPosition foncteur(std::for_each(m_site.liste().begin(),m_site.liste().end(),FoncteurTestPosition(info.coordinate())));
    this->setBorneAProximite(foncteur.borneLaPlusProche());
    if(FENETRE_VERBOSE){qDebug()<<QString("latitude : ").append(QString::number(info.coordinate().latitude())).append(" longitude : ").append(QString::number(info.coordinate().longitude()));}
    m_latitude = info.coordinate().latitude();
    m_longitude = info.coordinate().longitude();

    emit longitudeChanged();
    emit latitudeChanged();
    if(FENETRE_VERBOSE){qDebug("fin test positions");}
}

Borne *Fenetre::borneSelectionne()const
{
    return m_borneSelectionne;
}

QString Fenetre::nomPosition()const
{
    return m_nomPosition;
}

Borne *Fenetre::borneAProximite()const
{
    return m_borneAProximite;
}

void Fenetre::setBorneAProximite(Borne *nouvelleBorne)
{
    if(nouvelleBorne != m_borneAProximite)
    {
        if(nouvelleBorne == NULL)
        {
            m_borneAProximite = &borneVide;
        }
        else
        {
            m_borneAProximite = nouvelleBorne;
        }
        emit borneAProximiteChanged();
    }
}

Site *Fenetre::site()
{
    return (&m_site);
}

void Fenetre::resetBorneSelectionne()
{
    setBorneSelectionne("");
}

void Fenetre::resetBorneAProximite()
{
    setBorneAProximite(&borneVide);
}
