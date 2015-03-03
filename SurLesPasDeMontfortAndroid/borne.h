#ifndef BORNE_H
#define BORNE_H
#include <QString>
#include <QObject>
#include "ressourcemultimedia.h"

class Borne : public QObject
{
    Q_OBJECT
public:
    Borne(QString nom,QString adresse,QString description,QString coordonees,int id,QString text,QString nomFichier);
    Borne(QString nom,QString description,QString image, QString video,QString text,QString coordonee);
    ~Borne();
    Q_INVOKABLE QString nom();
    Q_INVOKABLE QString adresse()const;
    Q_INVOKABLE QString description()const;
    Q_INVOKABLE QString coordonees()const;
    Q_INVOKABLE int id()const;
    RessourceMultimedia ressource;
private:
    QString m_nom;
    QString m_adresse;
    QString m_description;
    QString m_coordonees;
    QString m_adrImage;
    int m_id;
    //RessourceMultimedia ressource;
};

#endif // BORNE_H
