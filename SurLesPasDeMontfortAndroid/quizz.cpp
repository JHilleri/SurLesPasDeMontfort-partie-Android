#include "quizz.h"

/*!
  \class Quizz
  \brief La classe Quizz contient les questions lies a une borne
  \inmodule Quizz
 */


Quizz::Quizz(QObject *parent) : QObject(parent), m_questionEnCours(m_liste.end())
{
    m_questionVide.setQuestion("question 0");
    m_questionVide.setBonneReponse("bonne reponse");
    m_questionVide.setMauvaiseReponse1("mauvaise reponse 1");
    m_questionVide.setMauvaiseReponse2("mauvaise reponse 2");
    m_questionVide.setMauvaiseReponse3("mauvaise reponse 3");
}

Quizz::~Quizz()
{
    this->clear();// inutile car les bornes ont le site comme parent;
}

void Quizz::ajouterQuestion(Question *question)
{
    if(!m_liste.contains((QObject *)question))
    {
        m_liste.append((QObject *)question);
        emit listeChanged();
        emit countChanged();
    }
}


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


const QList<QObject *> &Quizz::liste() const
{
    return m_liste;
}

int Quizz::count()
{
    return m_liste.count();
}

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

unsigned int Quizz::triesCount() const
{
    return m_triesCount;
}
/*
void Quizz::setQuestionEnCours(Question *question)
{
    m_questionEnCours = question;
    emit questionEnCoursChanged();
}*/

bool Quizz::questionSuivante()
{
    if( m_liste.count() > 0 && ++m_questionEnCours != m_liste.end())
    {
        emit questionEnCoursChanged();
        return true;
    }
    return false;
}

void Quizz::debutQuizz()
{
    if(m_liste.count() > 0)
    {
        m_questionEnCours = m_liste.begin();
        emit questionEnCoursChanged();
    }
}

void Quizz::setTriesCount(unsigned int arg)
{
    if (m_triesCount == arg)
        return;

    m_triesCount = arg;
    emit triesCountChanged(arg);
}
