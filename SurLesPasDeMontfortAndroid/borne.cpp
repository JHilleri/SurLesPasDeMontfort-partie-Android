#include "borne.h"

Borne::Borne(QString nom,QString adresse,QString description,QString coordonees,int id)
    :m_nom(nom),m_adresse(adresse),m_description(description),m_coordonees(coordonees),m_id(id)
{}

Borne::~Borne()
{}


QString Borne::nom()
{
    return m_nom;
}

QString Borne::adresse()
{
    return m_adresse;
}

QString Borne::description()
{
    return m_description;
}

QString Borne::coordonees()
{
    return m_coordonees;
}

int Borne::id()
{
    return m_id;
}
