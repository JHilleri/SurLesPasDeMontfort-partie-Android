#include "question.h"


Question::Question(QObject *parent) : QObject(parent)
{

}

Question::~Question()
{

}

Question::Question(const QDomElement &datas, QObject *parent): QObject(parent),
    m_bonneReponse(datas.attribute("bonneReponse")),
    m_mauvaiseReponse1(datas.attribute("m_mauvaiseReponse1")),
    m_mauvaiseReponse2(datas.attribute("m_mauvaiseReponse2")),
    m_mauvaiseReponse3(datas.attribute("m_mauvaiseReponse3")),
    m_question(datas.attribute("m_question"))
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
    return mauvaiseReponse1();
}

QString Question::mauvaiseReponse2()const
{
    return mauvaiseReponse2();
}

QString Question::mauvaiseReponse3()const
{
    return mauvaiseReponse3();
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

void Question::setmauvaiseReponse2(QString mauvaiseReponse2)
{
    m_mauvaiseReponse2 = mauvaiseReponse2;
    emit mauvaiseReponse2Changed();
}

void Question::setmauvaiseReponse3(QString mauvaiseReponse3)
{
    m_mauvaiseReponse3 = mauvaiseReponse3;
    emit mauvaiseReponse3Changed();
}

void Question::setDatas(const QDomElement &datas)
{
    m_bonneReponse=datas.attribute("bonneReponse");
    m_mauvaiseReponse1=datas.attribute("m_mauvaiseReponse1");
    m_mauvaiseReponse2=datas.attribute("m_mauvaiseReponse2");
    m_mauvaiseReponse3=datas.attribute("m_mauvaiseReponse3");
    m_question=datas.attribute("m_question");
}
