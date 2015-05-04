#ifndef QUIZZ_H
#define QUIZZ_H

#include <QObject>

#include "question.h"

class Quizz : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject *> liste READ liste NOTIFY listeChanged)
    Q_PROPERTY(int count READ count NOTIFY countChanged)
    Q_PROPERTY(Question* questionEnCours READ questionEnCours WRITE setQuestionEnCours NOTIFY questionEnCoursChanged)
public:
    explicit Quizz(QObject *parent = 0);
    ~Quizz();

    const QList<QObject *> &liste() const;
    void ajouterQuestion(Question *question);
    int count();

    Question *questionEnCours() const;
signals:
    void listeChanged();
    void listeCleared();
    void countChanged();

    void questionEnCoursChanged();
public slots:
    void clear();
    void setQuestionEnCours(Question *question);
private:
    QList<QObject *> m_liste;
    Question m_questionVide;
    Question *m_questionEnCours;
};

#endif // QUIZZ_H
