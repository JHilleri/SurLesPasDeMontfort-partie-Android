#ifndef BORNE_H
#define BORNE_H
#include <QString>
#include <QObject>
#include "ressourcemultimedia.h"

class Borne : public QObject
{
public:
    Borne(QString nom,QString adresse,QString description,QString coordonees,int id);
    ~Borne();
    QString nom();
    QString adresse();
    QString description();
    QString coordonees();
    int id();

private:
    QString m_nom;
    QString m_adresse;
    QString m_description;
    QString m_coordonees;
    int m_id;
    //RessourceMultimedia ressource;
};

#endif // BORNE_H
