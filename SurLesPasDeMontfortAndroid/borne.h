#ifndef BORNE_H
#define BORNE_H
#include <QString>
#include <QObject>
#include <QFile>

class Borne : public QObject
{
    Q_OBJECT
public:
    Borne();
    Borne(QString nom, QString adresse, QString description, QString coordonees, QString text);
    Borne(QString nom,QString description,QString image,QString video,QString text,QString coordonee);
    ~Borne();
    Q_INVOKABLE QString nom()const;
    Q_INVOKABLE QString adresse()const;
    Q_INVOKABLE QString description()const;
    Q_INVOKABLE QString coordonees()const;
    Q_INVOKABLE QString text();
    QString textUrl();
private:
    QString m_nom;
    QString m_adresse;
    QString m_description;
    QString m_coordonees;
    QString m_adrImage;

    QString m_textUrl;
    //RessourceMultimedia ressource;
};

#endif // BORNE_H
