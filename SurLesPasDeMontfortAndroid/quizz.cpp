#include "quizz.h"

Quizz::Quizz(QObject *parent) : QObject(parent), m_questionEnCours(&m_questionVide)
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

Question *Quizz::questionEnCours()const
{
    return m_questionEnCours;
}

void Quizz::setQuestionEnCours(Question *question)
{
    m_questionEnCours = question;
    emit questionEnCoursChanged();
}
