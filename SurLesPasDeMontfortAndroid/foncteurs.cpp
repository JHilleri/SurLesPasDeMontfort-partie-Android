#include "foncteurs.h"


FonctTestNomBorne::FonctTestNomBorne(QString nom):m_nom(nom)
{}

bool FonctTestNomBorne::operator ()( Borne * const borne)
{
    return (borne->nom() == m_nom);
}
