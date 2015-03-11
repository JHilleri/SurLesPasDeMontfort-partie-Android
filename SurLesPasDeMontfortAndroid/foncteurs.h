#ifndef FONCTEURS
#define FONCTEURS
#include "borne.h"

class FonctTestNomBorne
{
public:
    FonctTestNomBorne(QString nom);
    bool operator()(Borne * const borne);
private:
    QString m_nom;
};

#endif // FONCTEURS

