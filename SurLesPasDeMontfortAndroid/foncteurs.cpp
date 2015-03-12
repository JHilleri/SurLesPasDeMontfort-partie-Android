#include "foncteurs.h"


FoncteurTestNomBorne::FoncteurTestNomBorne(QString nom):m_nom(nom)
{}

bool FoncteurTestNomBorne::operator ()( Borne * const borne)
{
    return (borne->nom() == m_nom);
}
