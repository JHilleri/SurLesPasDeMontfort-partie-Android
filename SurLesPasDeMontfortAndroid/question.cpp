#include "question.h"

/*!
  \class Question
  \brief La classe Question regroupe les donnees decrivant une question de quizz
  \inmodule Quizz
 */


Question::Question(QObject *parent) : QObject(parent)
{

}

Question::~Question()
{

}

Question::Question(const QDomElement &datas, QObject *parent): QObject(parent),
    m_bonneReponse(datas.attribute("bonneReponse")),
    m_mauvaiseReponse1(datas.attribute("mauvaiseReponse1")),
    m_mauvaiseReponse2(datas.attribute("mauvaiseReponse2")),
    m_mauvaiseReponse3(datas.attribute("mauvaiseReponse3")),
    m_question(datas.attribute("question")),
    m_nomBorne(datas.attribute("borne").toUpper())
{}

QString Question::question()const
{
    return m_question;
}

QString Question::bonneReponse()const
{
    return m_bonneReponse;
}

QString Question::mauvaiseReponse1()const
{
    return m_mauvaiseReponse1;
}

QString Question::mauvaiseReponse2()const
{
    return m_mauvaiseReponse2;
}

QString Question::mauvaiseReponse3()const
{
    return m_mauvaiseReponse3;
}

QString Question::nomBorne()const
{
    return m_nomBorne;
}

void Question::setQuestion(QString question)
{
    m_question = question;
    emit questionChanged();
}

void Question::setBonneReponse(QString bonneReponse)
{
    m_bonneReponse = bonneReponse;
    emit bonneReponseChanged();
}

void Question::setMauvaiseReponse1(QString mauvaiseReponse1)
{
    m_mauvaiseReponse1 = mauvaiseReponse1;
    emit mauvaiseReponse1Changed();
}

void Question::setMauvaiseReponse2(QString mauvaiseReponse2)
{
    m_mauvaiseReponse2 = mauvaiseReponse2;
    emit mauvaiseReponse2Changed();
}

void Question::setMauvaiseReponse3(QString mauvaiseReponse3)
{
    m_mauvaiseReponse3 = mauvaiseReponse3;
    emit mauvaiseReponse3Changed();
}

void Question::setDatas(const QDomElement &datas)
{
    this->setBonneReponse(datas.attribute("bonneReponse"));
    this->setMauvaiseReponse1(datas.attribute("mauvaiseReponse1"));
    this->setMauvaiseReponse2(datas.attribute("mauvaiseReponse2"));
    this->setMauvaiseReponse3(datas.attribute("mauvaiseReponse3"));
    this->setQuestion(datas.attribute("question"));
    this->setNomBorne(datas.attribute("borne"));
}

void Question::setNomBorne(QString nomBorne)
{
    m_nomBorne = nomBorne.toUpper();
    emit nomBorneChanged();
}
