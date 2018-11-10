#ifndef JEU_H_INCLUDED
#define JEU_H_INCLUDED

#include "Parametres.h"
#include "Constantes.h"

void jeu(Parametres _params, int _scores[NB_TAB], int *_tableau);
void affiche(char _plateau[LIG][COL], int _x, int _y, int _bordure);

#endif // JEU_H_INCLUDED
