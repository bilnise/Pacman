#include "utils.h"

void gotoligcol(int lig, int col)
{
    COORD mycoord;

    mycoord.X  = col;
    mycoord.Y  = lig;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mycoord);
}

void affiche(char _plateau[LIG][COL], int _x, int _y, int _bordure)
{
    if(_bordure)
        gotoligcol(_y+1,_x+1);
    else
        gotoligcol(_y,_x);

    printf("%c", _plateau[_y][_x]);
}

void insertion(t_listeTriee *_liste, t_noeud *_nv)
{
    t_cell *tmp;
    t_cell *pt;
    t_cell *cell;

    cell = (t_cell*)malloc(sizeof(t_cell));

    cell->noeud = _nv;
    tmp = NULL;

    pt = _liste->ancre;
    while(pt && ((pt->noeud->g_cost + pt->noeud->h_cost) < (_nv->g_cost + _nv->h_cost)))
    {
        tmp = pt;
        pt = pt->suivant;
    }
    cell->suivant = pt;
    if(tmp)
        tmp->suivant = cell;
    else
        _liste->ancre = cell;

}

t_noeud* pop(t_listeTriee *_liste)
{
        t_noeud *noeud;
        t_cell *tmp;
        if(_liste->ancre == NULL)
            return NULL;

        tmp = _liste->ancre->suivant;
        noeud = _liste->ancre->noeud;
        free(_liste->ancre);
        _liste->ancre = tmp;
        return noeud;
}

int chercherNoeud(t_listeTriee *_liste, t_noeud *_noeud)
{
    t_cell *cell;

    if(_liste->ancre == NULL)
        return 0;

    cell = _liste->ancre;
    while(cell != NULL)
    {
        if(cell->noeud == _noeud)
            return 1;

        cell = cell->suivant;
    }

    return 0;
}

void supprimer(t_listeTriee *_liste, t_noeud *_noeud)
{
    t_cell *pt, *tmp;

    if(_liste->ancre != NULL && _liste->ancre->suivant != NULL)
    {
        pt = _liste->ancre;
        while(pt->suivant->noeud != _noeud)
        {
            pt = pt->suivant;
        }

        tmp = pt->suivant->suivant;
        free(pt->suivant);
        pt->suivant = tmp;
    }
}
