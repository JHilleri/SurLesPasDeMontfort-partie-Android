#include "basededonnees.h"

/*!
 * \class BaseDeDonnees
 * \brief La classe BaseDeDonnees regroupe les interactions avec la base de donnee
 * \inmodule BDD
 */

/*!
 * \brief Construit une Base de donnee
 */
BaseDeDonnees::BaseDeDonnees(): m_baseDeDonnees(QSqlDatabase::addDatabase("QSQLITE"))
{
    m_baseDeDonnees.setDatabaseName("SurLesPasDeMontfort");
    if(!m_baseDeDonnees.open())
    {
        qDebug("echec de l'ouverture de la base de donne");
    }
    this->creationTables();
    m_queryAjouterBorne = new QSqlQuery(m_baseDeDonnees);
    m_queryAjouterBorne->prepare("INSERT INTO Borne(Nom,Description,Adresse,UrlImage,UrlPisteAudio,UrlTexte,Latitude,Longitude,Altitude) VALUES "
                  "(:nom,:description,:addresse,:urlImage,:urlPisteAudio,:urlText,:lattitude,:longitude,:altitude)");
    m_queryAjouterQuestion = new QSqlQuery(m_baseDeDonnees);
    m_queryAjouterQuestion->prepare("INSERT INTO Question(NomBorne,Question,BonneReponse,MauvaiseReponse1,MauvaiseReponse2,MauvaiseReponse3)"
                                    " VALUES (:NomBorne,:Question,:BonneReponse,:MauvaiseReponse1,:MauvaiseReponse2,:MauvaiseReponse3)");

}

/*!
 * \brief Detruit une base de donnee
 */
BaseDeDonnees::~BaseDeDonnees()
{
    delete m_queryAjouterBorne;
    delete m_queryAjouterQuestion;
    m_baseDeDonnees.close();
}

/*!
 * \brief Creez les tables de la base de donnee
 */
void BaseDeDonnees::creationTables()
{
    QSqlQuery query;
    if(! (m_baseDeDonnees.tables().contains("Borne")))
    {
        if(!query.exec("CREATE TABLE Borne"
                       "(IdBorne INTEGER PRIMARY KEY  "
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
    if(!(m_baseDeDonnees.tables().contains("Question")))
    {
        if(!query.exec("CREATE TABLE Question (IdQuestion INTEGER PRIMARY KEY AUTOINCREMENT,"
                       " NomBorne VARCHAR(255), Question VARCHAR(255) UNIQUE, BonneReponse VARCHAR(255),"
                       " MauvaiseReponse1 VARCHAR(255), MauvaiseReponse2 VARCHAR(255),"
                       " MauvaiseReponse3 VARCHAR(255), Commentaire VARCHAR(255))"))
        {
            qDebug("echec de la creation de la table Question");
            qDebug(query.lastError().text().toStdString().c_str());
        }
    }
}

/*!
 * \brief Ajoute la Borne \a borne dans la table Borne de la base de donnee
 */
void BaseDeDonnees::ajouterBorne(Borne *borne)
{
    m_queryAjouterBorne->bindValue(":nom",borne->nom().toUpper());
    m_queryAjouterBorne->bindValue(":description",borne->description());
    m_queryAjouterBorne->bindValue(":addresse",borne->adresse());
    m_queryAjouterBorne->bindValue(":urlImage",borne->urlImage());
    m_queryAjouterBorne->bindValue(":urlPisteAudio",borne->urlPisteAudio());
    m_queryAjouterBorne->bindValue(":urlText",borne->urlText());
    m_queryAjouterBorne->bindValue(":lattitude",QString::number(borne->latitude()));
    m_queryAjouterBorne->bindValue(":longitude",QString::number(borne->longitude()));
    m_queryAjouterBorne->bindValue(":altitude",QString::number(borne->altitude()));


    if(!m_queryAjouterBorne->exec())

    {
        qDebug() << "echec de l'enregistrement" << endl << m_queryAjouterBorne->lastError().text();
        m_queryAjouterBorne->lastQuery();
    }
    else{
        if(BDD_VERBOSE)
        {
            QString requete = m_queryAjouterBorne->lastQuery();
            QMapIterator<QString, QVariant> i(m_queryAjouterBorne->boundValues());
            while (i.hasNext())
            {
                i.next();
                requete.replace(i.key(),i.value().toString());
            }
            qDebug() << " BDD: ajout d'un nouvel enregistrement : " << requete;
        }
    }
}

/*!
 * \brief Ajoute la Question \a question dans la table Question de la base de donnee
 */
void BaseDeDonnees::ajouterQuestion(Question *question)
{

    m_queryAjouterQuestion->prepare("INSERT INTO Question(NomBorne,Question,BonneReponse,MauvaiseReponse1,MauvaiseReponse2,MauvaiseReponse3)"
                    " VALUES (:NomBorne,:Question,:BonneReponse,:MauvaiseReponse1,:MauvaiseReponse2,:MauvaiseReponse3)");
    m_queryAjouterQuestion->bindValue(":NomBorne",question->nomBorne());
    m_queryAjouterQuestion->bindValue(":Question",question->question());
    m_queryAjouterQuestion->bindValue(":BonneReponse",question->bonneReponse());
    m_queryAjouterQuestion->bindValue(":MauvaiseReponse1",question->mauvaiseReponse1());
    m_queryAjouterQuestion->bindValue(":MauvaiseReponse2",question->mauvaiseReponse2());
    m_queryAjouterQuestion->bindValue(":MauvaiseReponse3",question->mauvaiseReponse3());
    if(!m_queryAjouterQuestion->exec())
    {
        qDebug() << "BDD: echec de l'enregistrement" << endl << m_queryAjouterQuestion->lastError().text();
    }
    if(BDD_VERBOSE)
    {
        QString requete = m_queryAjouterQuestion->lastQuery();
        QMapIterator<QString, QVariant> i(m_queryAjouterQuestion->boundValues());
        while (i.hasNext())
        {
            i.next();
            requete.replace(i.key(),i.value().toString());
        }
        qDebug() << "BDD: ajout d'une nouvelle question : " << requete;
    }
}

/*!
 * \brief Remplie le Site \a site avec les enregistrements de la table Borne de la base de donnee
 */
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

/*!
 * \brief Remplie le Quizz \a quizz avec les enregistrements de la table Question associe a la borne du nom de \a nomBorne
 */
void BaseDeDonnees::remplirQuizz(Quizz *quizz, QString nomBorne)
{
    QSqlQuery query;
    Question *question;

    if(!query.exec(QString("SELECT Question.Question, Question.BonneReponse, Question.MauvaiseReponse1,"
                   " Question.MauvaiseReponse2, Question.MauvaiseReponse3, Question.Commentaire FROM Question"
                   "  WHERE  Question.NomBorne = '").append(nomBorne.toUpper()).append("' ORDER BY Random() LIMIT ").append(NB_MAX_QUESTION_PAR_QUIZZ).append(";")))

    {
        qDebug()<<query.lastQuery();
        qDebug()<<query.lastError().text();
    }
    else
    {
        quizz->clear();
        while(query.next())
        {
            question = new Question(quizz);
            question->setNomBorne(nomBorne.toUpper());
            question->setQuestion(query.value(0).toString());
            question->setBonneReponse(query.value(1).toString());
            question->setMauvaiseReponse1(query.value(2).toString());
            question->setMauvaiseReponse2(query.value(3).toString());
            question->setMauvaiseReponse3(query.value(4).toString());
            //question->setCommentaire(query.value(5).toString());
            quizz->ajouterQuestion(question);
        }
    }
}

/*!
 * \brief Supprime tout le contenu de la base de donnee
 */
void BaseDeDonnees::clear()
{
    QSqlQuery query;
    if(BDD_VERBOSE){qDebug("suppression de la base de donnees");}
    if(!query.exec("DELETE FROM Borne;"))
    {
            qDebug("echec de la suppression de la base de donnee");
    }
    if(!query.exec("DELETE FROM Question;"))
    {
            qDebug("echec de la suppression de la base de donnee");
    }
}

void BaseDeDonnees::majBDD(QString adresseWebBdd)
{
    QSqlDatabase bddWeb = QSqlDatabase::addDatabase("QMYSQL");
    bddWeb.setHostName(adresseWebBdd);
    bddWeb.setDatabaseName("nomBase");
    bddWeb.setUserName("user");
    bddWeb.setPassword("password");
    bddWeb.setPort(0);
    bddWeb.open();
}
