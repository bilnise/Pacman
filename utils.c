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

