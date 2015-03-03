#include "borne.h"

Borne::Borne(QString nom,QString adresse,QString description,QString coordonees,int id,QString text,QString nomFirchier)
    :m_nom(nom),m_adresse(adresse),m_description(description),m_coordonees(coordonees),m_id(id),ressource(text,nomFirchier,typesFichier::Audio)
{}

Borne::Borne(QString nom,QString description,QString image, QString video,QString text,QString coordonee)
    :m_nom(nom), m_description(description),m_coordonees(coordonee),ressource(text,video,typesFichier::Audio)
{}

Borne::~Borne()
{}


QString Borne::nom()
{
    return m_nom;
}

QString Borne::adresse()const
{
    return m_adresse;
}

QString Borne::description()const
{
    return m_description;
}

QString Borne::coordonees()const
{
    return m_coordonees;
}

int Borne::id()const
{
    return m_id;
}
