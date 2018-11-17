#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "windows.h"
#include "time.h"

#include "Constantes.h"
#include "Entite.h"
#include "Tableaux.h"
#include "Parametres.h"
#include "utils.h"

typedef struct noeud {
    int x;
    int y;
    int f_cost;
    struct noeud* adjacents[4];
}t_noeud;

void gotoligcol(int lig, int col);
void affiche(char _plateau[LIG][COL], int _x, int _y, int _bordure);

#endif // UTILS_H_INCLUDED
