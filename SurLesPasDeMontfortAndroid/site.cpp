#include "site.h"
#include <algorithm>

Site::Site()
{

}

Site::~Site()
{
    this->clear();
}

void Site::ajouter(Borne *nouvelleBorne)
{
    if(!m_liste.contains(nouvelleBorne))
    {
        m_liste.append(nouvelleBorne);
    }
    else
    {
        qDebug("cette borne a est dejat dans la liste");
    }
}

QStringList Site::getNames()
{
    QStringList list;
    QListIterator<Borne *> i(m_liste);


    //TODO utilisation de la version c++ ( avec iterateur)
    while(i.hasNext())
        list.append(i.next()->nom());
    return list;
}

void Site::clear()
{
    //TODO utilisation de la version c++ ( avec iterateur)
    QListIterator<Borne *> i(m_liste);

    while(i.hasNext())
        delete i.next();
    m_liste.clear();
}


Borne *Site::getBorneByName(QString name)
{
    QList<Borne *>::iterator result = std::find_if(m_liste.begin(),m_liste.end(),FonctTestNomBorne(name));
    if(result != m_liste.end())return *result;
    else return 0;
}


