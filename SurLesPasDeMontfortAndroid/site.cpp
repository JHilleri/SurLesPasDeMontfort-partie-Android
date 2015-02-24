#include "site.h"

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


    while(i.hasNext())
        list.append(i.next()->nom());
    return list;
}

void Site::clear()
{
    QListIterator<Borne *> i(m_liste);

    while(i.hasNext())
        delete i.next();
    m_liste.clear();
}
