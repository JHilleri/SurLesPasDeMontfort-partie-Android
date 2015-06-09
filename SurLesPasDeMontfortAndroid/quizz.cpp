#include "quizz.h"

/*!
  \class Quizz
  \brief La classe Quizz contient une liste des questions liés a une borne et un iterateur qui permet de parcourire cette liste au file du quizz.
  \inmodule Quizz
 */

Quizz::Quizz(QObject *parent) : QObject(parent), m_questionEnCours(m_liste.end())
{
    m_questionVide.setQuestion("question");
    m_questionVide.setBonneReponse("bonne reponse");
    m_questionVide.setMauvaiseReponse1("mauvaise reponse 1");
    m_questionVide.setMauvaiseReponse2("mauvaise reponse 2");
    m_questionVide.setMauvaiseReponse3("mauvaise reponse 3");
}

/*!
 * \brief Detruit le \l{Quizz} et les \l{Question} qu'il contient.
 */
Quizz::~Quizz()
{
    this->clear();// inutile car les Questions ont le Quizz comme parent;
}

/*!
 * \brief Ajoute la \l{Question} \a question dans  la liste
 */
void Quizz::ajouterQuestion(Question *question)
{
    if(!m_liste.contains((QObject *)question))
    {
        m_liste.append((QObject *)question);
        emit listeChanged();
        emit countChanged();
    }
}

/*!
 * \brief Vide la liste et detruit les \l{Borne} de la liste
 */
void Quizz::clear()
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
 * \brief retourne la liste des questions
 */
const QList<QObject *> &Quizz::liste() const
{
    return m_liste;
}

/*!
 * \brief retourne le nombre de \l{Borne} de la liste.
 */
int Quizz::count()
{
    return m_liste.count();
}

/*!
 * \brief retourne la question en cours.
 */
Question *Quizz::questionEnCours()
{
    if(m_questionEnCours != m_liste.end())
    {
        return (Question*)*m_questionEnCours;
    }
    else
    {
        return &m_questionVide;
    }
}

unsigned int Quizz::nbEssaisEffectue() const
{
    return m_triesCount;
}

/*
void Quizz::setQuestionEnCours(Question *question)
{
    m_questionEnCours = question;
    emit questionEnCoursChanged();
}*/

/*!
 * \brief Positionne l'iterateur m_questionEnCours sur la question suivante
 */
bool Quizz::questionSuivante()
{
    if( m_liste.count() > 0 && ++m_questionEnCours != m_liste.end())
    {
        emit questionEnCoursChanged();
        return true;
    }
    return false;
}

/*!
 * \brief Positionne l'iterateur m_questionEnCours au debut du quizz
 */
void Quizz::debutQuizz()
{
    if(m_liste.count() > 0)
    {
        m_questionEnCours = m_liste.begin();
        emit questionEnCoursChanged();
    }
}

/*!
 * \brief definit le nombre d'éssais effectué
 */
void Quizz::setNbEssaisEffecte(unsigned int arg)
{
    if (m_triesCount == arg)
        return;

    m_triesCount = arg;
    emit nbEssaisEffectueChanged(arg);
}
