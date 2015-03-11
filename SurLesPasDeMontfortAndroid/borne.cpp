#include "borne.h"

Borne::Borne(){}

Borne::Borne(QString nom, QString adresse, QString description, QString coordonees, QString text)
    :m_nom(nom),m_adresse(adresse),m_description(description),m_coordonees(coordonees),m_textUrl(text)
{}

Borne::Borne(QString nom, QString description, QString image, QString video, QString text, QString coordonee)
    :m_nom(nom), m_description(description),m_coordonees(coordonee),m_textUrl(text)
{}

Borne::~Borne()
{}


QString Borne::nom()const
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


QString Borne::text()
{
    qDebug(m_textUrl.toStdString().c_str());
    QFile text(m_textUrl);
    if(text.open(QIODevice::ReadOnly))
    {
        return QString(text.readAll());
    }
    else
    {
        qDebug("echec de louverture du fichier");
        return QString("");
    }
}

QString Borne::textUrl()
{
    return m_textUrl;
}
