#include "site.h"




Site::Site(QObject *parent) : QObject(parent)
{

}

Site::~Site()
{
    this->clear();// inutile car les bornes ont le site comme parent;
}

void Site::ajouterBorne(Borne *borne)
{
    if(!m_liste.contains((QObject *)borne))
    {
        m_liste.append((QObject *)borne);
        emit listeChanged();
    }
}


void Site::clear()
{
    for(QList<QObject *>::iterator i = m_liste.begin();i != m_liste.end();++i)
    {
        delete *i;
    }
    m_liste.clear();
    emit listeChanged();
    emit listeCleared();
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
