#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "windows.h"
#include "time.h"

#include "Constantes.h"
#include "Entite.h"
#include "Parametres.h"
#include "utils.h"

// Pour l'algorithme A*
typedef struct noeud {
    int x;
    int y;
    int g_cost;
    int h_cost;
    struct noeud* adjacents[4];
    struct noeud* parent;
}t_noeud;

typedef struct cell {
    t_noeud *noeud;
    struct cell *suivant;
}t_cell;

typedef struct listeTriee {
    t_cell *ancre;
}t_listeTriee;

void insertion(t_listeTriee *_liste, t_noeud *_nv);
t_noeud* pop(t_listeTriee *_liste);
int chercherNoeud(t_listeTriee *_liste, t_noeud *noeud);
void supprimer(t_listeTriee *_liste, t_noeud *_noeud);

// Pour l'affichage
void gotoligcol(int lig, int col);
void affiche(char _plateau[LIG][COL], int _x, int _y, int _bordure);


#endif // UTILS_H_INCLUDED
