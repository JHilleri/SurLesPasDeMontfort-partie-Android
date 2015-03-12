#ifndef FONCTEURS
#define FONCTEURS
#include "borne.h"

class FoncteurTestNomBorne
{
public:
    FoncteurTestNomBorne(QString nom);
    bool operator()(Borne * const borne);
private:
    QString m_nom;
};

#endif // FONCTEURS

