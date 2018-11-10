#include "Jeu.h"
#include "Tableaux.h"

void affiche(char _plateau[LIG][COL], int _x, int _y, int _bordure)
{
    if(_bordure)
        gotoligcol(_y+1,_x+1);
    else
        gotoligcol(_y,_x);

    printf("%c", _plateau[_y][_x]);
}

void jeu(Parametres _params, int _scores[NB_TAB], int *_tableau)
{
    switch(*_tableau)
    {
    case 1:
        if(tableau1(_params,_scores))
            *_tableau = 2;
        else
            _scores[0] = 0;
        break;

    case 2:
        if(tableau2(_params,_scores))
            *_tableau = 3;
        else
            _scores[1] = 0;
        break;

    case 3:
        if(tableau3(_params,_scores))
            *_tableau = 4;
        else
            _scores[2] = 0;
        break;

    case 4:
        if(tableau4(_params,_scores))
            *_tableau = 1;
        else
            _scores[3] = 0;
        break;
    }
}
