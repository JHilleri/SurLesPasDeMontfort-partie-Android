#ifndef QUIZZ_H
#define QUIZZ_H

#include <QObject>

#include "question.h"

class Quizz : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject *> liste READ liste NOTIFY listeChanged)
    Q_PROPERTY(int count READ count NOTIFY countChanged)
    Q_PROPERTY(Question* questionEnCours READ questionEnCours NOTIFY questionEnCoursChanged)
    Q_PROPERTY(unsigned int nbEssaisEffectue READ nbEssaisEffectue WRITE setNbEssaisEffecte NOTIFY nbEssaisEffectueChanged)
public:
    explicit Quizz(QObject *parent = 0);
    ~Quizz();

    const QList<QObject *> &liste() const;
    void ajouterQuestion(Question *question);
    int count();

    Question *questionEnCours();
    unsigned int nbEssaisEffectue() const;

signals:
    void listeChanged();
    void listeCleared();
    void countChanged();

    void questionEnCoursChanged();
    void nbEssaisEffectueChanged(unsigned int arg);

public slots:
    void clear();
    //void setQuestionEnCours(Question *question);
    Q_INVOKABLE bool questionSuivante();
    void debutQuizz();
    void setNbEssaisEffecte(unsigned int arg);

private:
    QList<QObject *> m_liste;
    Question m_questionVide;
    //Question *m_questionEnCours;
    QList<QObject *>::iterator m_questionEnCours;
    unsigned int m_triesCount;
};

#endif // QUIZZ_H
