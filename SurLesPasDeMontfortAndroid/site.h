#ifndef SITE_H
#define SITE_H

#include <QObject>
#include <QString>
#include <algorithm>
#include "borne.h"
#include "foncteurs.h"

class Site : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<QObject *> liste READ liste NOTIFY listeChanged)
public:
    explicit Site(QObject *parent = 0);
    ~Site();

    const QList<QObject *> &liste() const;
    void ajouterBorne(Borne *borne);
    Borne *getBorneByName(QString nom);
signals:
    void listeChanged();
    void listeCleared();
public slots:
    void clear();
private:
    QList<QObject *> m_liste;
};

#endif // SITE_H
