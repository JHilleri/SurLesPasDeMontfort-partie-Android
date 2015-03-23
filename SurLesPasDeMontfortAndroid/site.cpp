#include "site.h"
#include <algorithm>

Site::Site(QObject *parent) : QObject(parent)
{

}

//Site::Site(const Site& site):m_liste(site.liste()){}

Site::~Site()
{
    this->clear();
}

void Site::ajouterBorne(Borne *borne)
{
    if(!m_liste.contains((QObject *)borne))
    {
        m_liste.append((QObject *)borne);
        emit listeChanged();
    }
}
/*
QStringList Site::getNames()
{
    QStringList list;
    QListIterator<Borne *> i(m_liste);


    //TODO utilisation de la version c++ ( avec iterateur)
    while(i.hasNext())
        list.append(i.next()->nom());
    return list;
}*/

void Site::clear()
{
    /*
    //TODO utilisation de la version c++ ( avec iterateur)
    QListIterator<Borne *> i(m_liste);

    while(i.hasNext())
        delete i.next();
    m_liste.clear();
    */
    for(QList<QObject *>::iterator i = m_liste.begin();i != m_liste.end();++i)
    {
        delete *i;
    }
    m_liste.clear();
    emit listeChanged();
}


Borne *Site::getBorneByName(QString nom)
{
    QList<QObject *>::iterator result = std::find_if(m_liste.begin(),m_liste.end(),FoncteurTestNomBorne(nom));
    if(result != m_liste.end())
    {
        return (Borne *)(*result);
    }
    else
    {
        qDebug(QString("borne '").append(nom).append("' non trouve dans le Site").toStdString().c_str());
        return 0;
    }
}

const QList<QObject *> &Site::liste() const
{
    return m_liste;
}
