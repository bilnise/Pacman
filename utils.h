#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include "windows.h"

typedef struct noeud {
    int x;
    int y;
    int f_cost;
    struct noeud* adjacents[4];
}t_noeud;

void gotoligcol(int lig, int col);

#endif // UTILS_H_INCLUDED
