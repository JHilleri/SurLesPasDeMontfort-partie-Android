#include "fenetresite.h"
#include <QString>

FenetreSite::FenetreSite(QObject *parent) : QObject(parent)
{
    m_site = new Site;
/*
    bdd.ajouterEnregistrement(new Borne("Le calvaire symbole monfortain","St Laurent sur sevre","calvaire","46.9672881,-0.898719,15z",":/textes/TextCalvaire.txt"));
    bdd.ajouterEnregistrement(new Borne("Chapelle de la Sagesse","St Laurent sur sevre","chapelle","",""));
    bdd.ajouterEnregistrement(new Borne("Maison longue","St Laurent sur sevre","maison","",""));
    bdd.ajouterEnregistrement(new Borne("Pont Eiffel","St Laurent sur sevre","maison","",""));

    bdd.ajouterEnregistrement(new Borne("Saint-Gabriel","St Laurent sur sevre", "st gab", "",":/textes/SaintGab.txt"));
*/
    lireSiteXML();
    bdd.remplirTab(m_site);
    m_liste = m_site->getNames();

}

void FenetreSite::start()
{
    m_engine.rootContext()->setContextProperty("fenetreSite",this);
    m_engine.rootContext()->setContextProperty("site",QVariant::fromValue(this->m_liste));
    m_engine.rootContext()->setContextProperty("borne",&borneVide);

    qDebug(QString::number(m_liste.size()).toStdString().c_str() );
    m_engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
}

FenetreSite::~FenetreSite()
{

}

QStringList FenetreSite::site()
{
    return m_liste;
}

void FenetreSite::setSite( QStringList site)
{
    m_liste = site;
}


void FenetreSite::ouvrirFenetreBorne(QString nomBorne)
{
    m_engine.rootContext()->setContextProperty("borne",this->m_site->getBorneByName(nomBorne));
}

void FenetreSite::lireSiteXML()
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
     while(!i.isNull())
     {
         QDomElement element = i.toElement();

         bdd.ajouterEnregistrement(new Borne(element.attribute("nom",""),element.attribute("adresse",""),element.attribute("description",""),element.attribute("coordonees",""),element.attribute("text","")));
         qDebug(element.attribute("nom","").toStdString().c_str());
         i = i.nextSibling();
     }

     bdd.remplirTab(m_site);
     m_liste = m_site->getNames();
}

