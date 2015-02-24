#ifndef RESSOURCEMULTIMEDIA_H
#define RESSOURCEMULTIMEDIA_H
#include <QString>

enum typesFichier{Audio,Video};
class RessourceMultimedia
{
public:
    RessourceMultimedia(QString text,QString nomFichier, typesFichier typeFichier);
    ~RessourceMultimedia();
    void afficher();

    QString m_addresse;
    QString m_text;
    typesFichier m_type;
private:

};

#endif // RESSOURCEMULTIMEDIA_H
