#include "site.h"

Site::Site()
{

}

Site::~Site()
{

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
    /*
    for(i=m_liste.begin();i!=m_liste.end();i++)
    {
        list.append(i.i.reference->nom());
    }*/
    while(i.hasNext())
        list.append(i.next()->nom());
    return list;
}
