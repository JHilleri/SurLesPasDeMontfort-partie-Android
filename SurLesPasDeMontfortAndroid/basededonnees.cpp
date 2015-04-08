#include "basededonnees.h"

BaseDeDonnees::BaseDeDonnees(): m_baseDeDonnees(QSqlDatabase::addDatabase("QSQLITE"))
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
            if(BDD_VERBOSE){qDebug("creation de la table Borne");}
        }
    }
}

void BaseDeDonnees::ajouterEnregistrement(Borne *borne)
{
    /*
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
    */
    QSqlQuery requeteAjoutBorne(m_baseDeDonnees);
    requeteAjoutBorne.prepare("INSERT INTO Borne(Nom,Description,Adresse,UrlImage,UrlPisteAudio,UrlTexte,Latitude,Longitude,Altitude) VALUES "
                  "(:nom,:description,:addresse,:urlImage,:urlPisteAudio,:urlText,:lattitude,:longitude,:altitude)");

    requeteAjoutBorne.bindValue(":nom",borne->nom().toUpper());
    requeteAjoutBorne.bindValue(":description",borne->description());
    requeteAjoutBorne.bindValue(":addresse",borne->adresse());
    requeteAjoutBorne.bindValue(":urlImage",borne->urlImage());
    requeteAjoutBorne.bindValue(":urlPisteAudio",borne->urlPisteAudio());
    requeteAjoutBorne.bindValue(":urlText",borne->urlText());
    requeteAjoutBorne.bindValue(":lattitude",QString::number(borne->latitude()));
    requeteAjoutBorne.bindValue(":longitude",QString::number(borne->longitude()));
    requeteAjoutBorne.bindValue(":altitude",QString::number(borne->altitude()));


    if(!requeteAjoutBorne.exec())

    {
        qDebug() << "echec de l'enregistrement" << endl << requeteAjoutBorne.lastError().text();
    }
    else{
        if(BDD_VERBOSE)
        {
            QString requete = requeteAjoutBorne.lastQuery();
            QMapIterator<QString, QVariant> i(requeteAjoutBorne.boundValues());
            while (i.hasNext())
            {
                i.next();
                requete.replace(i.key(),i.value().toString());
            }
            qDebug() << "ajout d'un nouvel enregistrement : " << requete;
        }
    }
}

void BaseDeDonnees::remplirSite(Site *site)
{
    QSqlQuery query;
    Borne *borne;
    if(!query.exec("SELECT Nom, Description, UrlImage, UrlPisteAudio, UrlTexte, Latitude, Longitude, Altitude  FROM Borne"))
    {
        qDebug()<<query.lastError().text();
    }
    else
    {
        site->clear();
        while(query.next())
        {
            borne = new Borne(site);
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

void BaseDeDonnees::clear()
{
    QSqlQuery query;
    if(BDD_VERBOSE){qDebug("suppression de la base de donnees");}
    if(!query.exec("DELETE FROM Borne;"))
    {
            qDebug("echec de la suppression de la base de donnee");
    }
}
