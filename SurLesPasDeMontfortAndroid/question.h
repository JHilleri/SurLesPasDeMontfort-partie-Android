#ifndef QUESTION_H
#define QUESTION_H

#include <QObject>
#include <QDomElement>
#include <QtQuick>
#include "config.h"

class Question : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString question READ question WRITE setQuestion NOTIFY questionChanged)
    Q_PROPERTY(QString bonneReponse READ bonneReponse WRITE setBonneReponse NOTIFY bonneReponseChanged)
    Q_PROPERTY(QString mauvaiseReponse1 READ mauvaiseReponse1 WRITE setMauvaiseReponse1 NOTIFY mauvaiseReponse1Changed)
    Q_PROPERTY(QString mauvaiseReponse2 READ mauvaiseReponse2 WRITE setmauvaiseReponse2 NOTIFY mauvaiseReponse2Changed)
    Q_PROPERTY(QString mauvaiseReponse3 READ mauvaiseReponse3 WRITE setmauvaiseReponse3 NOTIFY mauvaiseReponse3Changed)
    //Q_PROPERTY(QString urlImage READ urlImage WRITE setUrlImage NOTIFY urlImageChanged)
public:
    explicit Question(QObject *parent = 0);
    Question(const QDomElement &datas,QObject *parent = 0);
    ~Question();

    QString question()const;
    QString bonneReponse()const;
    QString mauvaiseReponse1()const;
    QString mauvaiseReponse2()const;
    QString mauvaiseReponse3()const;
    //QString urlImage()const;

    void setDatas(const QDomElement &datas);

signals:

    void questionChanged();
    void bonneReponseChanged();
    void mauvaiseReponse1Changed();
    void mauvaiseReponse2Changed();
    void mauvaiseReponse3Changed();
    //void urlImageChanged();

public slots:
    void setQuestion(QString question);
    void setBonneReponse(QString bonneReponse);
    void setMauvaiseReponse1(QString mauvaiseReponse1);
    void setmauvaiseReponse2(QString mauvaiseReponse2);
    void setmauvaiseReponse3(QString mauvaiseReponse3);
    //void setUrlImage(QString urlImage);
private:
    QString m_question;
    QString m_bonneReponse;
    QString m_mauvaiseReponse1;
    QString m_mauvaiseReponse2;
    QString m_mauvaiseReponse3;
    //QString m_urlImage;
};


#endif // QUESTION_H
