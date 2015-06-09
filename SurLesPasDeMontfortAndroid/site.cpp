#include "site.h"

/*!
  \class Site
  \brief La classe Site contient une liste des Bornes (\l{Borne}) du parcours
  \inmodule Parcours
 */


Site::Site(QObject *parent) : QObject(parent)
{}

Site::~Site()
{
    this->clear();// inutile car les bornes ont le site comme parent;
}

/*!
 * \brief Ajoute la \l{Borne} \a borne a la liste.
 */
void Site::ajouterBorne(Borne *borne)
{
    if(!m_liste.contains((QObject *)borne))
    {
        m_liste.append((QObject *)borne);
        emit listeChanged();
    }
}

/*!
 * \brief Detruit et supprime le contenu de la liste.
 */
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


/*!
 * \brief Retourne la \l{Borne} portant le nom \a nom
 */
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

/*!
 * \brief Retourne une copie de la liste.
 */
const QList<QObject *> &Site::liste() const
{
    return m_liste;
}
