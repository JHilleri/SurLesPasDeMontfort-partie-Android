#include "fenetre.h"


/*!
  \class Fenetre
  \brief La classe Fenetre remplie la fonction de Contrôleur,
   elle contient le \l{QQmlApplicationEngine} qui execute l'IHM et les classes du modèle.
  \inmodule IHM
 */


Fenetre::Fenetre(QObject *parent) : QObject(parent),m_borneSelectionne(&borneVide),m_gps(this),m_site(this),m_borneAProximite(&borneVide),m_quizz(this)
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

/*!
 * \brief Execute l'application QML et lui fournit un acces vers le modèle sous forme de pointeur globale.
 */
void Fenetre::start()
{
    m_engine.rootContext()->setContextProperty("fenetre",this);
    m_engine.load(QUrl(QStringLiteral("qrc:/qml/FenetrePrincipale.qml")));
}

Fenetre::~Fenetre(){}

/*!
 * \brief Définie la \l{Borne} identifié par le nom \p nomBorne comme borne séléctionné par l'utilisateur.
 */
void Fenetre::setBorneSelectionne(QString nomBorne)
{
    if(nomBorne == m_borneSelectionne->nom())return;
    Borne *borne = m_site.getBorneByName(nomBorne);
    if(borne != NULL)
    {
        this->setBorneSelectionne(borne);
    }
    else
    {
        this->setBorneSelectionne(&borneVide);
    }
}


/*!
 * \brief Définie la \l{Borne}  \p borneSelectionne comme borne séléctionné par l'utilisateur.
 */
void Fenetre::setBorneSelectionne(Borne *borneSelectionne)
{
    m_borneSelectionne = borneSelectionne;
    emit borneSelectionneChanged();
}

/*!
 * \brief Remplie le quizz (\l{Quizz}),
 *  avec des \l{Question} associé a la borne du nom \p nomBorne grace a la \l{BaseDeDonnees}
 */
void Fenetre::lireQuizz(QString nomBorne)
{
    bdd.remplirQuizz(&m_quizz,nomBorne);
    if(m_quizz.count() > 0)
        m_quizz.debutQuizz();
}

/*!
 * \brief Remplie la base SQLite avec le contenu d'un fichier XML
 */
void Fenetre::lireXML()
{
    QDomDocument doc("Site_xml");
    QFile fichier(":/data/Site.xml");
    QDomElement racine;
    QDomNode i;
    QDomElement element;
    Borne *nouvelleBorne;
    Question *nouvelleQuestion;

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
         bdd.ajouterBorne(nouvelleBorne);
         delete nouvelleBorne;

         i = i.nextSibling();
     }



     fichier.setFileName(":/data/Quizz.xml");
     if (!fichier.open(QIODevice::ReadOnly) || !doc.setContent(&fichier))
     {
          fichier.close();
          qDebug("echec de l'ouverture du fichier xml");
          return;
      }
     fichier.close();
     racine = doc.documentElement();
     i = racine.firstChild();
     while(!i.isNull())
     {
         element = i.toElement();
         nouvelleQuestion = new Question(element,this);
         bdd.ajouterQuestion(nouvelleQuestion);
         delete nouvelleQuestion;

         i = i.nextSibling();
     }

     // mise a jour des données du site
     bdd.remplirSite(&m_site);
}

/*!
 * \brief Ouvre une application pour afficher une carte montrant l'emplacement de la borne du nom de \p nomBorne.
 */
void Fenetre::afficherCarte(QString nomBorne)
{
    Borne *borne =  m_site.getBorneByName(nomBorne);
    if(borne->latitude() != 0.0 || borne->longitude() != 0.0 || borne->altitude() != 0.0)
    {
        QString addresseUrl("http://maps.google.com/?q=" + QString::number(borne->latitude()) + "," + QString::number(borne->longitude()));
        QDesktopServices::openUrl(QUrl(addresseUrl));
    }
}

/*!
 * \brief Ouvre une application pour afficher un itineraire vers la borne du nom de \p nomBorne.
 */
void Fenetre::afficherItineraire(QString nomBorne)
{
    Borne *borne =  m_site.getBorneByName(nomBorne);
    if(borne->latitude() != 0.0 || borne->longitude() != 0.0 || borne->altitude() != 0.0)
    {
        QString addresseUrl("http://maps.google.com/maps?&daddr=" + QString::number(borne->latitude()) + "," + QString::number(borne->longitude()));
        QDesktopServices::openUrl(QUrl(addresseUrl));
    }
}

/*!
 * \brief Determine si l'utilisateur est a proximité d'une borne.
 * Calcule la distance entre le point \p info et chaqune des \l{Borne} du \l{Site}, si la \l{Borne} la plus proche est a moin de SENSIBILITE_DETECTION_ZONE mêtres elle est definit comme borne a proximité.
 */
void Fenetre::testsPosition(QGeoPositionInfo &info)
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

Quizz *Fenetre::quizz()
{
    return (&m_quizz);
}

void Fenetre::resetBorneSelectionne()
{
    setBorneSelectionne("");
}

void Fenetre::resetBorneAProximite()
{
    setBorneAProximite(&borneVide);
}
