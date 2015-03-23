#include "basededonnees.h"

BaseDeDonnees::BaseDeDonnees():/* QObject(),*/ m_baseDeDonnees(QSqlDatabase::addDatabase("QSQLITE"))
{
    m_baseDeDonnees.setDatabaseName("SurLesPasDeMontfort");
    if(!m_baseDeDonnees.open())
    {
        qDebug("echec de l'ouverture de la base de donne");
    }
    this->creationTables();
}

BaseDeDonnees::~BaseDeDonnees()
{
    m_baseDeDonnees.close();
}

void BaseDeDonnees::creationTables()
{
    if(! (m_baseDeDonnees.tables().contains("Borne")))
    {
        QSqlQuery query;
        if(!query.exec("CREATE TABLE Borne"
                       "(idBorne INTEGER PRIMARY KEY  "
                       "AUTOINCREMENT,Nom VARCHAR(100)"
                       " UNIQUE ,Description VARCHAR(300)"
                       ",Adresse VARCHAR(255),UrlImage VARCHAR(255), "
                       "UrlPisteAudio VARCHAR(255), UrlTexte VARCHAR(255), "
                       "Latitude DOUBLE ,Longitude DOUBLE ,Altitude DOUBLE )"))
        {
            qDebug("echec de la creation de la table Borne");
            qDebug(query.lastError().text().toStdString().c_str());
        }
        else{
            qDebug("creation de la table Borne");
        }
    }
}

void BaseDeDonnees::ajouterEnregistrement(Borne *borne)
{
    QSqlQuery query;
    QString requete = "INSERT INTO Borne(Nom,Description,Adresse,UrlImage,UrlPisteAudio,UrlTexte,Latitude,Longitude,Altitude) VALUES ('";
    requete.append(borne->nom().toUpper() + "','");
    requete.append(borne->description() + "','");
    requete.append(borne->adresse()+ "','");
    requete.append(borne->urlImage()+ "','");
    requete.append(borne->urlPisteAudio()+ "','");
    requete.append(borne->urlText()+ "',");
    requete.append(QString::number(borne->latitude())+ ",");
    requete.append(QString::number(borne->longitude())+ ",");
    requete.append(QString::number(borne->altitude())+  ")");

    qDebug(requete.toStdString().c_str());

    if(!query.exec(requete))

    {
        qDebug("\nechec de l'enregistrement");
        qDebug(query.lastError().text().toStdString().c_str());
    }
    else{
        qDebug("ajout d'un nouvel enregistrement");
    }
}

void BaseDeDonnees::remplirTab(Site *site)
{
    QSqlQuery query;
    Borne *borne;
    if(!query.exec("SELECT Nom, Description, UrlImage, UrlPisteAudio, UrlTexte, Latitude, Longitude, Altitude  FROM Borne"))
    {
        qDebug(query.lastError().text().toStdString().c_str());
    }
    else
    {
        site->clear();
        while(query.next())
        {
            //site->ajouter(new Borne(query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString()));
            borne = new Borne;
            borne->setNom(query.value(0).toString());
            borne->setDescription(query.value(1).toString());
            borne->setUrlImage(query.value(2).toString());
            borne->setUrlPisteAudio(query.value(3).toString());
            borne->setUrlText(query.value(4).toString());
            borne->setLatitude(query.value(5).toDouble());
            borne->setLongitude(query.value(6).toDouble());
            borne->setAltitude(query.value(7).toDouble());
            site->ajouterBorne(borne);
        }
    }
}
/*
QStringList BaseDeDonnees::liste()
{
    QStringList liste;
    liste.clear();
    QSqlQuery query;
    if(query.exec("SELECT Nom FROM Borne "))
    {

        while(query.next())
        {
            liste.append(query.value(0).toString());
        }
    }
    else
    {
        qDebug(query.lastError().text().toStdString().c_str());
    }
    return liste;
}*/
/*
void BaseDeDonnees::setListe(QStringList liste)
{
    m_liste = liste;
}*/

void BaseDeDonnees::clear()
{
    QSqlQuery query;
    qDebug("suppression de la base de donnees");
    if(!query.exec("DELETE FROM Borne;"))
    {
            qDebug("echec de la suppression de la base de donnee");
    }
}
