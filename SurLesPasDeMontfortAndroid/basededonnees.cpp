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
                       ",Image VARCHAR(255), "
                       "Video VARCHAR(255), Texte VARCHAR, "
                       "CoordoneeGPS VARCHAR(255))"))
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

    if(!query.exec("INSERT INTO Borne(Nom,Description,Texte,CoordoneeGPS) VALUES ('"
                   + borne->nom().toUpper() + "','" + borne->description() + "','" + borne->textUrl() + "','" + borne->coordonees() + "')"))

    {
        qDebug("echec de l'enregistrement");
        qDebug(query.lastError().text().toStdString().c_str());
        QString requete(query.lastQuery());
        qDebug(requete.toStdString().c_str());
    }
    else{
        qDebug("ajout d'un nouvel enregistrement");
    }
}

void BaseDeDonnees::remplirTab(Site *site)
{
    QSqlQuery query;
    if(!query.exec("SELECT Nom, Description, Image, Video, Texte, CoordoneeGPS FROM Borne"))
    {
        qDebug(query.lastError().text().toStdString().c_str());
    }
    else
    {
        site->clear();
        while(query.next())
        {
            site->ajouter(new Borne(query.value(0).toString(),query.value(1).toString(),query.value(2).toString(),query.value(3).toString(),query.value(4).toString(),query.value(5).toString()));
            qDebug(query.value(0).toString().toStdString().c_str());
            qDebug(query.value(4).toString().toStdString().c_str());
        }
    }
}

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
}

void BaseDeDonnees::setListe(QStringList liste)
{
    m_liste = liste;
}

void BaseDeDonnees::clear()
{
    QSqlQuery query;
    qDebug("suppression de la base de donnees");
    if(!query.exec("DELETE FROM Borne;"))
    {
            qDebug("echec de la suppression de la base de donnee");
    }
}
