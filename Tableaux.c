#include "Tableaux.h"

void genererSuccesseurs(t_noeud *_noeud,char _plateau[LIG][COL], t_noeud *successeurs[4])
{
    int i;

    if(_noeud->x-1 < 0 && _noeud->y-1 < 0)
    {
        successeurs[0] = NULL;
        successeurs[3] = NULL;

        successeurs[1] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[1]->g_cost=0;
        successeurs[1]->h_cost=0;
        successeurs[1]->parent=NULL;
        successeurs[1]->x = _noeud->x +1;
        successeurs[1]->y = _noeud->y;

        successeurs[2] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[2]->g_cost=0;
        successeurs[2]->h_cost=0;
        successeurs[2]->parent=NULL;
        successeurs[2]->x = _noeud->x;
        successeurs[2]->y = _noeud->y + 1;
    }
    else if(_noeud->x+1 >= COL && _noeud->y-1 < 0)
    {
        successeurs[0] = NULL;
        successeurs[1] = NULL;

        successeurs[3] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[3]->g_cost=0;
        successeurs[3]->h_cost=0;
        successeurs[3]->parent=NULL;
        successeurs[3]->x = _noeud->x - 1;
        successeurs[3]->y = _noeud->y;

        successeurs[2] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[2]->g_cost=0;
        successeurs[2]->h_cost=0;
        successeurs[2]->parent=NULL;
        successeurs[2]->x = _noeud->x;
        successeurs[2]->y = _noeud->y + 1;
    }
    else if(_noeud->x+1 >= COL && _noeud->y+1 >= LIG)
    {
        successeurs[1] = NULL;
        successeurs[2] = NULL;

        successeurs[3] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[3]->g_cost=0;
        successeurs[3]->h_cost=0;
        successeurs[3]->parent=NULL;
        successeurs[3]->x = _noeud->x - 1;
        successeurs[3]->y = _noeud->y;

        successeurs[0] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[0]->g_cost=0;
        successeurs[0]->h_cost=0;
        successeurs[0]->parent=NULL;
        successeurs[0]->x = _noeud->x;
        successeurs[0]->y = _noeud->y - 1;
    }
    else if(_noeud->x-1 < 0 && _noeud->y+1 >= LIG)
    {
        successeurs[3] = NULL;
        successeurs[2] = NULL;

        successeurs[0] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[0]->g_cost=0;
        successeurs[0]->h_cost=0;
        successeurs[0]->parent=NULL;
        successeurs[0]->x = _noeud->x;
        successeurs[0]->y = _noeud->y - 1;

        successeurs[1] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[1]->g_cost=0;
        successeurs[1]->h_cost=0;
        successeurs[1]->parent=NULL;
        successeurs[1]->x = _noeud->x + 1;
        successeurs[1]->y = _noeud->y;
    }
    else if(_noeud->x-1 < 0)
    {
        successeurs[3] = NULL;

        successeurs[1] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[1]->g_cost=0;
        successeurs[1]->h_cost=0;
        successeurs[1]->parent=NULL;
        successeurs[1]->x = _noeud->x + 1;
        successeurs[1]->y = _noeud->y;

        successeurs[0] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[0]->g_cost=0;
        successeurs[0]->h_cost=0;
        successeurs[0]->parent=NULL;
        successeurs[0]->x = _noeud->x;
        successeurs[0]->y = _noeud->y - 1;

        successeurs[2] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[2]->g_cost=0;
        successeurs[2]->h_cost=0;
        successeurs[2]->parent=NULL;
        successeurs[2]->x = _noeud->x;
        successeurs[2]->y = _noeud->y + 1;
    }
    else if(_noeud->y-1 < 0)
    {
        successeurs[0] = NULL;

        successeurs[1] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[1]->g_cost=0;
        successeurs[1]->h_cost=0;
        successeurs[1]->parent=NULL;
        successeurs[1]->x = _noeud->x + 1;
        successeurs[1]->y = _noeud->y;

        successeurs[3] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[3]->g_cost=0;
        successeurs[3]->h_cost=0;
        successeurs[3]->parent=NULL;
        successeurs[3]->x = _noeud->x - 1;
        successeurs[3]->y = _noeud->y;

        successeurs[2] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[2]->g_cost=0;
        successeurs[2]->h_cost=0;
        successeurs[2]->parent=NULL;
        successeurs[2]->x = _noeud->x;
        successeurs[2]->y = _noeud->y + 1;
    }
    else if(_noeud->x+1 >= COL)
    {
        successeurs[1] = NULL;

        successeurs[0] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[0]->g_cost=0;
        successeurs[0]->h_cost=0;
        successeurs[0]->parent=NULL;
        successeurs[0]->x = _noeud->x;
        successeurs[0]->y = _noeud->y - 1;

        successeurs[3] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[3]->g_cost=0;
        successeurs[3]->h_cost=0;
        successeurs[3]->parent=NULL;
        successeurs[3]->x = _noeud->x - 1;
        successeurs[3]->y = _noeud->y;

        successeurs[2] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[2]->g_cost=0;
        successeurs[2]->h_cost=0;
        successeurs[2]->parent=NULL;
        successeurs[2]->x = _noeud->x;
        successeurs[2]->y = _noeud->y + 1;
    }
    else if(_noeud->y+1 >= LIG)
    {
        successeurs[2] = NULL;

        successeurs[1] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[1]->g_cost=0;
        successeurs[1]->h_cost=0;
        successeurs[1]->parent=NULL;
        successeurs[1]->x = _noeud->x + 1;
        successeurs[1]->y = _noeud->y;

        successeurs[3] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[3]->g_cost=0;
        successeurs[3]->h_cost=0;
        successeurs[3]->parent=NULL;
        successeurs[3]->x = _noeud->x - 1;
        successeurs[3]->y = _noeud->y;

        successeurs[0] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[0]->g_cost=0;
        successeurs[0]->h_cost=0;
        successeurs[0]->parent=NULL;
        successeurs[0]->x = _noeud->x;
        successeurs[0]->y = _noeud->y - 1;
    }
    else
    {
        successeurs[0] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[0]->g_cost=0;
        successeurs[0]->h_cost=0;
        successeurs[0]->parent=NULL;
        successeurs[0]->x = _noeud->x;
        successeurs[0]->y = _noeud->y - 1;

        successeurs[1] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[1]->g_cost=0;
        successeurs[1]->h_cost=0;
        successeurs[1]->parent=NULL;
        successeurs[1]->x = _noeud->x + 1;
        successeurs[1]->y = _noeud->y;

        successeurs[2] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[2]->g_cost=0;
        successeurs[2]->h_cost=0;
        successeurs[2]->parent=NULL;
        successeurs[2]->x = _noeud->x;
        successeurs[2]->y = _noeud->y + 1;

        successeurs[3] = (t_noeud*)malloc(sizeof(t_noeud));
        successeurs[3]->g_cost=0;
        successeurs[3]->h_cost=0;
        successeurs[3]->parent=NULL;
        successeurs[3]->x = _noeud->x - 1;
        successeurs[3]->y = _noeud->y;
    }

    for(i=0;i<4;i++)
    {
        if(successeurs[i] != NULL)
        {
            if(_plateau[successeurs[i]->y][successeurs[i]->x] == '\xDB')
            {
                free(successeurs[i]);
                successeurs[i] = NULL;
            }
        }
    }
}

void deplacerGhostIA(t_ghost *_ghost, char _plateau[LIG][COL])
{
    t_listeTriee open, close;
    t_noeud debut, *actuel, fin, *successeurs[4];
    t_noeud *pt;
    int i;

    open.ancre = NULL;
    close.ancre = NULL;

    debut.x = _ghost->posX;
    debut.y = _ghost->posY;
    debut.g_cost = 0;

    fin.x = _ghost->cibleX;
    fin.y = _ghost->cibleY;

    debut.h_cost = sqrt((fin.x-debut.x)*(fin.x-debut.x)+(fin.y-debut.y)*(fin.y-debut.y));


    insertion(&open, &debut);
    while(open.ancre != NULL)
    {
        actuel = pop(&open);
        if(actuel->x == fin.x && actuel->y == fin.y)
            break;

        genererSuccesseurs(actuel,_plateau, successeurs);

        for(i=0; i<4; i++)
        {
            if(successeurs[i]==NULL)
                continue;

            if(chercherNoeud(&open, successeurs[i]))
            {
                if(successeurs[i]->g_cost <= actuel->g_cost + 1)
                    continue;
            }
            else if(chercherNoeud(&close,successeurs[i]))
            {

                if(successeurs[i]->g_cost <= actuel->g_cost + 1)
                    continue;

                insertion(&open, successeurs[i]);
                supprimer(&close, successeurs[i]);
            }
            else
            {
                insertion(&open,successeurs[i]);
                successeurs[i]->h_cost = sqrt((successeurs[i]->x - fin.x)*(successeurs[i]->x - fin.x) + (successeurs[i]->y - fin.y)*(successeurs[i]->y - fin.y));
            }

            successeurs[i]->g_cost = actuel->g_cost + 1;
            successeurs[i]->parent = actuel;
        }

        insertion(&close,actuel);
    }

    pt = &fin;
    while(pt->parent != &debut)
    {
        pt=pt->parent;
    }

    _ghost->posX = pt->x;
    _ghost->posY = pt->y;
}


void initialiserPacman(t_pacman *_pacman, int _vitesseInitiale, char _plateau[LIG][COL])
{
    _pacman->forme = 'X';
    _pacman->vies = VIES;
    _pacman->vitesse = _vitesseInitiale;
    _pacman->dirX = -1+rand()%3;

    if(_pacman->dirX != 0)
    {
        _pacman->dirY = 0;
    }
    else
    {
        do
        {
            _pacman->dirY = -1+rand()%3;
        }
        while(_pacman->dirY == 0);
    }

    /// 1.1.2. Eviter les superpositions
    do
    {
        _pacman->posX = rand()%(COL-2); // Eviter d'apparaître à coté de la bordure pour ne pas perdre une vie bêtement
        _pacman->posY = rand()%(LIG-2); // Eviter d'apparaître à coté de la bordure pour ne pas perdre une vie bêtement
    }
    while(_plateau[_pacman->posY][_pacman->posX] != ' ');
}

void initialiserDiamant(t_diamant *_diamant, char _plateau[LIG][COL])
{
    _diamant->forme = 'D';

    do
    {
        _diamant->posX = rand()%COL;
        _diamant->posY = rand()%LIG;

        ///         1.2.1. Vérifier les superpositions
    }
    while(_plateau[_diamant->posY][_diamant->posX] != ' ');
}

void initialiserGhost(t_ghost *_ghost, int _vitesse, char _plateau[LIG][COL])
{

    _ghost->forme = 'G';
    _ghost->vitesse = _vitesse;
    _ghost->cibleX = 0;
    _ghost->cibleY = 0;
    _ghost->dirX = 1;
    _ghost->dirY = 0;

    do
    {
        _ghost->posX = rand()%COL;
        _ghost->posY = rand()%LIG;

        ///         1.3.1. Vérifier les superpositions
    }
    while(_plateau[_ghost->posY][_ghost->posX] != ' ');

}

void initialiserSnake(t_snake *_snake, int _vitesse, char _plateau[LIG][COL])
{
    t_corps *tete;

    tete = (t_corps*)malloc(sizeof(t_corps));

    if(tete)
    {
        tete->forme = 'X';
        tete->suivant = NULL;
        tete->precedent = NULL;
        tete->dirX = -1+rand()%3;

        if(tete->dirX != 0)
        {
            tete->dirY = 0;
        }
        else
        {
            do
            {
                tete->dirY = -1+rand()%3;
            }
            while(tete->dirY == 0);
        }

        /// 1.1.2. Eviter les superpositions
        do
        {
            tete->posX = rand()%COL-2;
            tete->posY = rand()%LIG-2;
        }
        while(_plateau[tete->posY][tete->posX] != ' ');
    }

    _snake->ancre = tete;
    _snake->vies = VIES;
    _snake->vitesse = _vitesse;
}

void afficherPlateau(char _plateau[LIG][COL], int _bordure)
{
    int i,j;
    ///         2.1. Mettre la bordure si activée
    if(_bordure)
    {
        system("mode con lines=27 cols=52");

        printf("%c", 201); // Affiche ╔
        for(i=0; i<COL; i++) // Pour chaque colonne
        {
            printf("%c",205); // Affiche ═
        }
        printf("%c\n", 187); // Affiche ╗

        for(i=0; i<LIG; i++) // Pour chaque ligne
        {
            printf("%c", 186); // Affiche ║
            for(j=0; j<COL; j++)
            {
                printf("%c", _plateau[i][j]);
            }
            printf("%c\n", 186); // Affiche ║
        }

        printf("%c", 200); // Affiche ╚
        for(i=0; i<COL; i++)
        {
            printf("%c", 205); // Affiche ═
        }
        printf("%c", 188); // Affiche ╝
    }
    else ///    2.2. Sinon, ne pas dessiner la bordure
    {
        system("mode con lines=27 cols=50");
        for(i=0; i<LIG; i++)
        {
            for(j=0; j<COL; j++)
            {
                printf("%c", _plateau[i][j]);
            }
        }

        // Dessiner la frontière entre les infos du jeu (scores et vies) et le plateau
        for(i=0; i<COL; i++)
        {
            printf("\xC4"); // Affiche ─
        }
    }
}

void afficherSnake(t_snake *_snake, char _plateau[LIG][COL], int _bordure)
{
    t_corps *pt;

    pt = _snake->ancre;
    while(pt != NULL)
    {
        _plateau[pt->posY][pt->posX] = pt->forme;
        affiche(_plateau, pt->posX, pt->posY, _bordure);
        pt = pt->suivant;
    }
}

void effacerSnake(t_snake *_snake, char plateau[LIG][COL])
{
    t_corps *pt;

    pt=_snake->ancre;

    if(pt == NULL)
    {
        return;
    }
    else
    {
        while(pt!=NULL)
        {
            pt->forme = ' ';
            plateau[pt->posY][pt->posX] = pt->forme;
            pt = pt->suivant;
        }
    }

}

void updatePacman(t_pacman *_pacman, char _plateau[LIG][COL], int _bordure)
{
    _plateau[_pacman->posY][_pacman->posX] = ' ';
    affiche(_plateau, _pacman->posX, _pacman->posY, _bordure);

    _pacman->posX += _pacman->dirX;
    _pacman->posY += _pacman->dirY;
}

void updateGhost(t_ghost *_ghost, char _plateau[LIG][COL], int _bordure)
{
    _plateau[_ghost->posY][_ghost->posX] = ' ';
    affiche(_plateau, _ghost->posX,_ghost->posY, _bordure);

    _ghost->posX += _ghost->dirX;
    _ghost->posY += _ghost->dirY;
}

void updateSnake(t_snake *_snake, char _plateau[LIG][COL], int _bordure)
{
    t_corps *dernier;

    dernier = _snake->ancre;
    while(dernier->suivant!=NULL)
    {
        dernier = dernier->suivant;
    }

    _plateau[dernier->posY][dernier->posX] = ' ';
    affiche(_plateau, dernier->posX, dernier->posY, _bordure);

    while(dernier->precedent != NULL)
    {
        dernier->posX = dernier->precedent->posX;
        dernier->posY = dernier->precedent->posY;
        dernier = dernier->precedent;
    }

    _snake->ancre->posX = _snake->ancre->posX + _snake->ancre->dirX;
    _snake->ancre->posY = _snake->ancre->posY + _snake->ancre->dirY;
}

void deplacerGhost(t_ghost *_ghost)
{
    if(rand()%5 == 1) // Permet des mouvements moins "aléatoires"
    {
        _ghost->dirX=(rand()%3)-1;
        _ghost->dirY=(rand()%3)-1;

        // On évite les déplacements en diagonale
        if(_ghost->dirX != 0)
        {
            _ghost->dirY = 0;
        }
        else
        {
            do
            {
                _ghost->dirY = -1+rand()%3;
            }
            while(_ghost->dirY == 0); // si par mal chance dirY vaut 0 on recommence

        }
    }
}

int testBordurePacman(t_pacman *_pacman, int _bordure)
{
    ///         3.2.1. Si bordure activé, décrémenter nombre de vie de 1 et arreter Pacman
    if(_bordure)
    {
        if(_pacman->posX < 0)
        {
            _pacman->vies--;
            _pacman->posX = 0;
            _pacman->dirX = 0;
            return 1;
        }
        else if(_pacman->posX >= COL)
        {
            _pacman->vies--;
            _pacman->posX = COL-1;
            _pacman->dirX = 0;
            return 1;
        }
        else if(_pacman->posY < 0)
        {
            _pacman->vies--;
            _pacman->posY = 0;
            _pacman->dirY = 0;
            return 1;
        }
        else if(_pacman->posY >= LIG)
        {
            _pacman->vies--;
            _pacman->posY = LIG-1;
            _pacman->dirY = 0;
            return 1;
        }
    }
    ///         3.2.2. Sinon, faire réapparaitre Pacman de l'autre coté
    else
    {
        if(_pacman->posX < 0)
        {
            _pacman->posX = COL-1;
            return 1;
        }
        else if(_pacman->posX >= COL)
        {
            _pacman->posX = 0;
            return 1;
        }
        else if(_pacman->posY < 0)
        {
            _pacman->posY = LIG-1;
            return 1;
        }
        else if(_pacman->posY >= LIG)
        {
            _pacman->posY = 0;
            return 1;
        }
    }

    return 0;
}

int testBordureGhost(t_ghost *fantome, int _bordure)
{
    ///         3.5.1. Si bordure activé, faire rebondir fantôme
    if(_bordure)
    {
        if(fantome->posX<0)
        {
            fantome->posX=0;
            fantome->dirX=1;
            return 1;
        }
        else if(fantome->posX>=COL)
        {
            fantome->posX=COL-1;
            fantome->dirX=-1;
            return 1;
        }
        else if(fantome->posY>=LIG)
        {
            fantome->posY=LIG-1;
            fantome->dirY=-1;
            return 1;
        }
        else if(fantome->posY<0)
        {
            fantome->posY=0;
            fantome->dirY=1;
            return 1;
        }
    }
    ///         3.5.2. Sinon, faire réapparaitre fantôme de l'autre coté
    else
    {
        if(fantome->posX < 0)
        {
            fantome->posX = COL-1;
            return 1;
        }
        else if(fantome->posX >= COL)
        {
            fantome->posX = 0;
            return 1;
        }
        else if(fantome->posY < 0)
        {
            fantome->posY = LIG-1;
            return 1;
        }
        else if(fantome->posY >= LIG)
        {
            fantome->posY = 0;
            return 1;
        }
    }

    return 0;
}

int testPacmanGhost(t_pacman *_pacman, t_ghost *_ghost)
{
    if((_pacman->posX==_ghost->posX)&&(_pacman->posY==_ghost->posY))
    {
        _pacman->vies--;
        return 1;
    }

    return 0;
}

int testPacmanDiamant(t_pacman *_pacman, t_diamant *_diamant, char _plateau[LIG][COL])
{
    if(_pacman->posX == _diamant->posX && _pacman->posY == _diamant->posY && _plateau[_pacman->posY][_pacman->posX] == 'D')
    {
        ///         3.3.3. Mettre à jour diamant
        _diamant->forme = ' ';

        return 1;
    }

    return 0;
}

int testPacmanMur(t_pacman *_pacman, char _plateau[LIG][COL])
{
    if(_plateau[_pacman->posY][_pacman->posX] == '\xDB') //Si le pacman se trouve sur un █ alors
        //repositionner à la position précèdente et immobiliser le pacman
    {
        _pacman->posX = _pacman->posX - _pacman->dirX;
        _pacman->posY = _pacman->posY - _pacman->dirY;
        _pacman->dirX = 0;
        _pacman->dirY = 0;
        return 1;
    }

    return 0;
}

int testGhostMur(t_ghost *_ghost, char _plateau[LIG][COL])
{
    if(_plateau[_ghost->posY][_ghost->posX] == '\xDB') //Si le fantome se trouve sur un █ alors
        //repositionner à la position précèdente et immobiliser le pacman
    {
        _ghost->posX = _ghost->posX - _ghost->dirX;
        _ghost->posY = _ghost->posY - _ghost->dirY;
        _ghost->dirX = 0;
        _ghost->dirY = 0;
        return 1;
    }

    return 0;
}

int testBordureSnake(t_snake *_snake, int _bordure)
{
    ///         3.2.1. Si bordure activé, décrémenter nombre de vie de 1 et arreter Snake
    if(_bordure)
    {
        if(_snake->ancre->posX < 0)
        {
            _snake->vies--;
            _snake->ancre->posX = 0;
            _snake->ancre->dirX = 0;
            return 1;
        }
        else if(_snake->ancre->posX >= COL)
        {
            _snake->vies--;
            _snake->ancre->posX = COL-1;
            _snake->ancre->dirX = 0;
            return 1;
        }
        else if(_snake->ancre->posY < 0)
        {
            _snake->vies--;
            _snake->ancre->posY = 0;
            _snake->ancre->dirY = 0;
            return 1;
        }
        else if(_snake->ancre->posY >= LIG)
        {
            _snake->vies--;
            _snake->ancre->posY = LIG-1;
            _snake->ancre->dirY = 0;
            return 1;
        }
    }
    ///         3.2.2. Sinon, faire réapparaitre Snake de l'autre coté
    else
    {
        if(_snake->ancre->posX < 0)
        {
            _snake->ancre->posX = COL-1;
            return 1;
        }
        else if(_snake->ancre->posX >= COL)
        {
            _snake->ancre->posX = 0;
            return 1;
        }
        else if(_snake->ancre->posY < 0)
        {
            _snake->ancre->posY = LIG-1;
            return 1;
        }
        else if(_snake->ancre->posY >= LIG)
        {
            _snake->ancre->posY = 0;
            return 1;
        }
    }

    return 0;
}

int testTeteSnakeGhost(t_snake *_snake, t_ghost *_ghost)
{
    if((_snake->ancre->posX==_ghost->posX)&&(_snake->ancre->posY==_ghost->posY))
    {
        return 1;
    }

    return 0;
}

int testCorpsSnakeGhost(t_snake *_snake, t_ghost *_ghost, t_corps **_queueAcouper)
{
    t_corps *pt;

///             3.8.1.	Chercher l’élément touché par un fantôme
    pt = _snake->ancre->suivant;
    while(pt!=NULL)
    {
        if((pt->posX==_ghost->posX)&&(pt->posY==_ghost->posY))
        {
            *_queueAcouper = pt;
            return 1;
        }

        pt = pt->suivant;
    }

    return 0;
}

int testCorpsTeteSnake(t_snake *_snake)
{
    t_corps *pt;

    pt = _snake->ancre;
    while(pt!=NULL)
    {
        if(pt->suivant != NULL)
        {
            if(_snake->ancre->posX == pt->suivant->posX && _snake->ancre->posY == pt->suivant->posY)
                return 1;
        }

        pt = pt->suivant;
    }

    return 0;
}

int testSnakeDiamant(t_snake *_snake, t_diamant *_diamant, char _plateau[LIG][COL])
{
    if(_snake->ancre->posX == _diamant->posX && _snake->ancre->posY == _diamant->posY && _plateau[_snake->ancre->posY][_snake->ancre->posX] == 'D')
    {
        ///         3.3.3. Mettre à jour diamant
        _diamant->forme = ' ';

        return 1;
    }

    return 0;
}

int testSnakeYukunkun(t_snake *_snake, t_diamant *_yukunkun, char _plateau[LIG][COL])
{
    if(_snake->ancre->posX == _yukunkun->posX && _snake->ancre->posY == _yukunkun->posY && _plateau[_snake->ancre->posY][_snake->ancre->posX] == '*')
    {
        ///         3.3.3. Mettre à jour diamant
        _yukunkun->forme = ' ';

        return 1;
    }

    return 0;
}

int testSnakeMur(t_snake *_snake, char _plateau[LIG][COL])
{
    if(_plateau[_snake->ancre->posY][_snake->ancre->posX] == '\xDB') //Si le snake se trouve sur un █ alors
        //repositionner à la position précèdente et immobiliser le snake
    {
        _snake->ancre->posX = _snake->ancre->posX - _snake->ancre->dirX;
        _snake->ancre->posY = _snake->ancre->posY - _snake->ancre->dirY;
        _snake->ancre->dirX = 0;
        _snake->ancre->dirY = 0;
        return 1;
    }

    return 0;
}

void ajouter_queue(t_snake *_snake)
{
    t_corps *dernier;
    t_corps *nv;

    nv = (t_corps*)malloc(sizeof(t_corps));

    if(nv)
    {
        if(_snake->ancre == NULL)
        {
            _snake->ancre = nv;
            nv->suivant = NULL;
            nv->precedent = NULL;
        }
        else
        {
            nv->forme = 'O';
            nv->posX = _snake->ancre->posX - _snake->ancre->dirX;
            nv->posY = _snake->ancre->posY - _snake->ancre->dirY;

            dernier = _snake->ancre;
            while(dernier->suivant != NULL)
            {
                dernier = dernier->suivant;
            }

            nv->precedent = dernier;
            dernier->suivant = nv;
            nv->suivant = NULL;
        }
    }
}

void supprimer_queue(t_snake *_snake, t_corps *_queueAcouper)
{
    t_corps *pt;

    if(_snake->ancre != NULL && _snake->ancre->suivant != NULL)
    {
        pt = _snake->ancre;
        while(pt->suivant!=_queueAcouper)
        {
            pt = pt->suivant;
        }
        free(pt->suivant);
        pt->suivant = NULL;
    }
}

void supprimerSnake(t_snake *_snake)
{
    t_corps *pt;

    while(_snake->ancre != NULL)
    {
        if(_snake->ancre->suivant == NULL)
        {
            free(_snake->ancre);
            _snake->ancre = NULL;
        }
        else
        {
            pt = _snake->ancre;
            while(pt->suivant->suivant != NULL)
            {
                pt = pt->suivant;
            }

            free(pt->suivant);
            pt->suivant = NULL;
        }
    }
}

int tableau1(Parametres *_params, int _score[NB_TAB], int _totalDiamants)
{
    char plateau[LIG][COL];
    int nbDiamants, i, j, fin, gagne;
    t_diamant *diamants;
    t_pacman pacman;

    /// 1. Initialiser tableau
    nbDiamants = _totalDiamants;
    fin = 0;
    gagne = 0;

    diamants = (t_diamant*)malloc(_totalDiamants*sizeof(t_diamant));
    if(!diamants)
    {
        printf("Erreur initialisation des diamants. Veuillez relancer le jeu.");
        return 0;
    }

    for(i=0; i<LIG; i++)
    {
        for(j=0; j<COL; j++)
        {
            plateau[i][j] = ' ';
        }
    }

    ///     1.1. Initialiser pacman
    initialiserPacman(&pacman, _params->vitesseInitale, plateau);

    ///     1.2. Initialiser les diamants
    for(i=0; i<_totalDiamants; i++)
    {
        initialiserDiamant(&diamants[i], plateau);
    }

    ///     1.3. Initialiser plateau
    plateau[pacman.posY][pacman.posX] = pacman.forme;
    for(i=0; i<_totalDiamants; i++)
    {
        plateau[diamants[i].posY][diamants[i].posX] = diamants[i].forme;
    }

    system("cls");
    /// 2. Afficher plateau
    afficherPlateau(plateau, _params->bordure);

    gotoligcol(LIG+3,0);
    printf("Score : %d",_score[0]);

    gotoligcol(LIG+4,0);
    printf("Vies : %d",pacman.vies);

    printf("\nAppuyer sur q pour revenir au menu\n");
    printf("Appuyer sur p pour mettre en pause");

    /// 3. Boucle de jeu
    while(!fin)
    {
        switch(_params->vitesseInitale)
        {
        case 1:
            Sleep(200);
            break;

        case 2:
            Sleep(100);
            break;

        case 3:
            Sleep(50);
            break;
        }
        ///     3.1. Mise à jour position Pacman selon la direction
        updatePacman(&pacman,plateau, _params->bordure);
        ///     3.2. Tester collision bordure
        testBordurePacman(&pacman, _params->bordure);
        ///     3.5. Tester nombre de diamants restants
        ///         3.5.1. Si nombre de diamants restants nul, afficher "Gagné !" et retourner 1
        if(nbDiamants == 0)
        {
            gotoligcol(LIG/2, COL/2-3);
            printf("WIN !");
            Sleep(2000);
            gagne = 1;
            fin = 1;
        }
        ///     3.4. Tester nombre de vie
        ///         3.4.1. Si nombre de vie nul, afficher "Game over" et retourner 0
        if(pacman.vies == 0)
        {
            gotoligcol(LIG/2, COL/2-5);
            printf("GAME OVER");
            Sleep(2000);
            gagne = 0;
            fin = 1;
        }
        ///     3.3. Tester collision diamant
        for(i=0; i<_totalDiamants; i++)
        {
            if(testPacmanDiamant(&pacman,&diamants[i],plateau))
            {
                ///         3.3.1. Augmenter score de 10
                _score[0] += 10;
                ///         3.3.2. Décrémenter nombre de diamants restants de 1
                nbDiamants--;
            }
        }

        ///     3.6. Appuie d'une touche utilisateur
        if(kbhit())
        {
            char touche;
            int pause;
            touche = getch();

            switch(touche)
            {
            ///         3.6.1. Selon la touche, modifier la direction du pacman
            case '8':
                pacman.dirX = 0;
                pacman.dirY = -1;
                break;

            case '2':
                pacman.dirX = 0;
                pacman.dirY = 1;
                break;

            case '4':
                pacman.dirX = -1;
                pacman.dirY = 0;
                break;

            case '6':
                pacman.dirX = 1;
                pacman.dirY = 0;
                break;

            ///         3.6.2. Mise en pause
            case 'p':
                pause = 1;
                while(pause)
                {
                    if(getch() == 'p')
                        pause = 0;
                }
                break;

            ///         3.6.3. Quitter
            case 'q':
                fin = 1;
                break;
            }
        }
        ///     3.7. Afficher éléments
        ///         3.7.1. Afficher diamants
        color(11,0);
        for(i=0; i<_totalDiamants; i++)
        {
            plateau[diamants[i].posY][diamants[i].posX] = diamants[i].forme;
            affiche(plateau, diamants[i].posX, diamants[i].posY, _params->bordure);
        }
        ///         3.7.2. Afficher Pacman
        color(2,0);
        plateau[pacman.posY][pacman.posX] = pacman.forme;
        affiche(plateau, pacman.posX, pacman.posY, _params->bordure);

        ///         3.7.3. Afficher score
        color(15,0);
        gotoligcol(LIG+3,8);
        printf("%d",_score[0]);
        ///         3.7.4. Afficher vies
        gotoligcol(LIG+4,7);
        printf("%d",pacman.vies);
    }

    free(diamants);

    return gagne;
}

int tableau2(Parametres *_params, int _score[NB_TAB], int _totalDiamants)
{
    char plateau[LIG][COL];
    int nbDiamants, i, j, fin, gagne;
    t_diamant *diamants;
    t_pacman pacman;
    t_ghost fantomes[NB_GHOSTS];

    /// 1. Initialiser tableau
    nbDiamants = _totalDiamants;
    fin = 0;
    gagne = 0;

    diamants = (t_diamant*)malloc(_totalDiamants*sizeof(t_diamant));
    if(!diamants)
    {
        printf("Erreur initialisation des diamants. Veuillez relancer le jeu.");
        return 0;
    }

    for(i=0; i<LIG; i++)
    {
        for(j=0; j<COL; j++)
        {
            plateau[i][j] = ' ';
        }
    }

    ///     1.1. Initialiser pacman
    initialiserPacman(&pacman,_params->vitesseInitale, plateau);

    ///     1.2. Initialiser les diamants
    for(i=0; i<_totalDiamants; i++)
        initialiserDiamant(&diamants[i], plateau);

    ///     1.3. Initialiser fantômes
    for(i=0; i<NB_GHOSTS; i++)
        initialiserGhost(&fantomes[i],_params->vitesseInitale, plateau);

    ///     1.4. Initialiser plateau
    plateau[pacman.posY][pacman.posX] = pacman.forme;
    for(i=0; i<_totalDiamants; i++)
    {
        plateau[diamants[i].posY][diamants[i].posX] = diamants[i].forme;
    }

    for(i=0; i<NB_GHOSTS; i++)
    {
        plateau[fantomes[i].posY][fantomes[i].posX]=fantomes[i].forme;
    }


    /// 2. Afficher plateau
    afficherPlateau(plateau,_params->bordure);

    gotoligcol(LIG+3,0);
    printf("Score : %d",_score[0]+_score[1]);

    gotoligcol(LIG+4,0);
    printf("Vies : %d",pacman.vies);

    printf("\nAppuyer sur q pour revenir au menu\n");
    printf("Appuyer sur p pour mettre en pause");

    /// 3. Boucle de jeu
    while(!fin)
    {
        switch(_params->vitesseInitale)
        {
        case 1:
            Sleep(200);
            break;

        case 2:
            Sleep(100);
            break;

        case 3:
            Sleep(50);
            break;
        }

        ///     3.1. Mise à jour fantômes
        for(i=0; i<NB_GHOSTS; i++)
        {
            updateGhost(&fantomes[i],plateau,_params->bordure);
        }

        ///     3.2. Mise à jour Pacman
        updatePacman(&pacman,plateau,_params->bordure);

        ///     3.3. Tester collision bordure (Pacman)
        ///         3.3.1. Si bordure activé, décrémenter nombre de vie de 1 et faire rebondir Pacman
        testBordurePacman(&pacman,_params->bordure);

        ///     3.4. Tester collision bordure (fantômes)
        for(i=0; i<NB_GHOSTS; i++)
            testBordureGhost(&fantomes[i], _params->bordure);

        ///     3.5. Tester collision fantôme
        for(i=0; i<NB_GHOSTS; i++)
            testPacmanGhost(&pacman,&fantomes[i]);

        ///     3.6. Tester collision diamant
        for(i=0; i<_totalDiamants; i++)
        {
            if(testPacmanDiamant(&pacman,&diamants[i],plateau))
            {
                ///         3.3.1. Augmenter score de 10
                _score[1] += 10;
                ///         3.3.2. Décrémenter nombre de diamants restants de 1
                nbDiamants--;
            }
        }

        ///     3.7. Tester nombre de vie
        ///         3.7.1. Si nombre de vie nul, afficher "Game over" et retourner 0
        if(pacman.vies == 0)
        {
            gotoligcol(LIG/2, COL/2-5);
            printf("GAME OVER");
            fin=1;
            gagne=0;
        }

        ///     3.8. Tester nombre de diamants restants
        ///         3.8.1. Si nombre de diamants restants nul, afficher "Gagné !" et retourner 1
        if(nbDiamants == 0)
        {
            gotoligcol(LIG/2, COL/2-3);
            printf("WIN !");
            fin=1;
            gagne=1;
        }

        ///     3.8. Modifier la direction des fantômes aléatoirement
        for(i=0; i<NB_GHOSTS; i++)
        {
            deplacerGhost(&fantomes[i]);
        }

        ///     3.9. Appuie d'une touche utilisateur
        if(kbhit())
        {
            char touche;
            int pause;
            touche = getch();

            switch(touche)
            {
            ///         3.9.1. Selon la touche, modifier la direction du pacman

            case '8':
                pacman.dirX = 0;
                pacman.dirY = -1;
                break;

            case '2':
                pacman.dirX = 0;
                pacman.dirY = 1;
                break;

            case '4':
                pacman.dirX = -1;
                pacman.dirY = 0;
                break;

            case '6':
                pacman.dirX = 1;
                pacman.dirY = 0;
                break;

            ///         3.9.2. Mise en pause
            case 'p':
                pause = 1;
                while(pause)
                {
                    if(getch() == 'p')
                        pause = 0;
                }
                break;

            ///         3.9.3. Quitter
            case 'q':
                fin = 1;
                break;
            }
        }

        ///     3.10. Afficher éléments
        ///         3.10.1. Afficher diamants
        color(11,0);
        for(i=0; i<_totalDiamants; i++)
        {
            plateau[diamants[i].posY][diamants[i].posX] = diamants[i].forme;
            affiche(plateau, diamants[i].posX, diamants[i].posY, _params->bordure);
        }

        ///         3.10.2. Afficher Pacman
        color(2,0);
        plateau[pacman.posY][pacman.posX] = pacman.forme;
        affiche(plateau, pacman.posX, pacman.posY, _params->bordure);

        ///         3.10.3. Afficher fantômes
        color(12,0);
        for(i=0; i<NB_GHOSTS; i++)
        {
            plateau[fantomes[i].posY][fantomes[i].posX]=fantomes[i].forme;
            affiche(plateau, fantomes[i].posX, fantomes[i].posY, _params->bordure);
        }

        ///         3.10.4. Afficher score
        color(15,0);
        gotoligcol(LIG+3,8);
        printf("%d",_score[0]+_score[1]);

        ///         3.10.5. Afficher vies
        gotoligcol(LIG+4,7);
        printf("%d",pacman.vies);
    }

    free(diamants);
    Sleep(2000);
    return gagne;
}

int tableau3(Parametres *_params, int _score[NB_TAB], int _totalDiamants)
{
    // design du plateau /xDB correspond à █
    char plateau[LIG][COL] = {"                                                  ",
                              "                                                  ",
                              "     \xDB\xDB\xDB\xDB\xDB                              \xDB\xDB\xDB\xDB\xDB     ",
                              "     \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB     \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB     ",
                              "     \xDB\xDB\xDB\xDB\xDB                              \xDB\xDB\xDB\xDB\xDB     ",
                              "       \xDB                                  \xDB       ",
                              "       \xDB                                  \xDB       ",
                              "       \xDB                                  \xDB       ",
                              "                      \xDB\xDB\xDB\xDB\xDB                       ",
                              "                      \xDB\xDB\xDB\xDB\xDB                       ",
                              "                      \xDB\xDB\xDB\xDB\xDB                       ",
                              "                      \xDB\xDB\xDB\xDB\xDB                       ",
                              "       \xDB                                  \xDB       ",
                              "       \xDB                                  \xDB       ",
                              "       \xDB                                  \xDB       ",
                              "     \xDB\xDB\xDB\xDB\xDB                              \xDB\xDB\xDB\xDB\xDB     ",
                              "     \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB     \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB     ",
                              "     \xDB\xDB\xDB\xDB\xDB                              \xDB\xDB\xDB\xDB\xDB     ",
                              "                                                  ",
                              "                                                  "
                             };
    int nbDiamants, i, fin, gagne, compteurBoucle;
    int vitesseFantomes[NB_GHOSTS];
    t_diamant *diamants;
    t_pacman pacman;
    t_ghost fantomes[NB_GHOSTS];

    /// 1. Initialiser tableau
    nbDiamants = _totalDiamants;
    fin = 0;
    gagne = 0;
    compteurBoucle = 0;

    vitesseFantomes[0] = 4;
    vitesseFantomes[1] = 4;
    vitesseFantomes[2] = 1;
    vitesseFantomes[3] = 1;

    diamants = (t_diamant*)malloc(_totalDiamants*sizeof(t_diamant));
    if(!diamants)
    {
        printf("Erreur initialisation des diamants. Veuillez relancer le jeu.");
        return 0;
    }

    ///     1.1. Initialiser pacman
    initialiserPacman(&pacman,5, plateau);

    ///     1.2. Initialiser les diamants
    for(i=0; i<_totalDiamants; i++)
        initialiserDiamant(&diamants[i], plateau);

    ///     1.3. Initialiser fantômes
    for(i=0; i<NB_GHOSTS; i++)
        initialiserGhost(&fantomes[i],vitesseFantomes[i], plateau);

    ///     1.4. Initialiser plateau
    plateau[pacman.posY][pacman.posX] = pacman.forme;
    for(i=0; i<_totalDiamants; i++)
    {
        plateau[diamants[i].posY][diamants[i].posX] = diamants[i].forme;
    }

    for(i=0; i<NB_GHOSTS; i++)
    {
        plateau[fantomes[i].posY][fantomes[i].posX]=fantomes[i].forme;
    }

    /// 2. Afficher plateau
    afficherPlateau(plateau,_params->bordure);

    gotoligcol(LIG+3,0);
    printf("Score : %d",_score[0]+_score[1]+_score[2]);

    gotoligcol(LIG+4,0);
    printf("Vies : %d",pacman.vies);

    printf("\nAppuyer sur q pour revenir au menu\n");
    printf("Appuyer sur p pour mettre en pause");
    /// 3. Boucle de jeu
    while(!fin)
    {
        switch(_params->vitesseInitale)
        {
        case 1:
            Sleep(200);
            break;

        case 2:
            Sleep(100);
            break;

        case 3:
            Sleep(50);
            break;
        }

        ///     3.1. Mise à jour Ghosts selon la vitesse des fantômes
        for(i=0; i<NB_GHOSTS; i++)
        {
            if(compteurBoucle%fantomes[i].vitesse == 0)
            {
                updateGhost(&fantomes[i],plateau,_params->bordure);
            }
        }

        ///     3.2. Mise à jour Pacman selon la vitesse du pacman
        if(compteurBoucle%pacman.vitesse == 0)
            updatePacman(&pacman,plateau,_params->bordure);

        ///     3.3. Traquer Pacman (pathfinding A*)

        ///     3.3. Tester collision bordure (Pacman)
        testBordurePacman(&pacman,_params->bordure);

        ///     3.4. Tester collision bordure (fantômes)
        for(i=0; i<NB_GHOSTS; i++)
            testBordureGhost(&fantomes[i], _params->bordure);

        ///     3.5. Tester collision fantôme
        for(i=0; i<NB_GHOSTS; i++)
            testPacmanGhost(&pacman,&fantomes[i]);

        ///     3.6. Tester collision diamant
        for(i=0; i<_totalDiamants; i++)
        {
            if(testPacmanDiamant(&pacman,&diamants[i],plateau))
            {
                ///         3.3.1. Augmenter score de 10
                _score[2] += 10;
                ///         3.3.2. Décrémenter nombre de diamants restants de 1
                nbDiamants--;
                ///         3.6.4. Augmenter la vitesse du pacman
                pacman.vitesse--;
                if(pacman.vitesse <= 0)
                    pacman.vitesse = 1;
            }
        }

        ///     3.7. Tester collision Pacman et murs
        testPacmanMur(&pacman,plateau);

        ///     3.8. Tester collision fantômes et murs
        for(i=0; i<NB_GHOSTS; i++)
            testGhostMur(&fantomes[i],plateau);

        ///     3.9. Tester nombre de vie
        ///         3.9.1. Si nombre de vie nul, afficher "Game over" et retourner 0
        if(pacman.vies == 0)
        {
            gotoligcol(LIG/2, COL/2-5);
            printf("GAME OVER");
            fin=1;
            gagne=0;
        }

        ///     3.10. Tester nombre de diamants restants
        ///         3.10.1. Si nombre de diamants restants nul, afficher "Gagné !" et retourner 1
        if(nbDiamants == 0)
        {
            gotoligcol(LIG/2, COL/2-3);
            printf("WIN !");
            fin=1;
            gagne=1;
        }

        ///     3.8. Traquer Pacman
        for(i=0; i<NB_GHOSTS; i++)
        {
            deplacerGhost(&fantomes[i]);
        }

        ///     3.11. Appuie d'une touche utilisateur
        if(kbhit())
        {
            char touche;
            int pause;
            touche = getch();

            switch(touche)
            {
            ///         3.11.1. Selon la touche, modifier la direction du pacman

            case '8':
                pacman.dirX = 0;
                pacman.dirY = -1;
                break;

            case '2':
                pacman.dirX = 0;
                pacman.dirY = 1;
                break;

            case '4':
                pacman.dirX = -1;
                pacman.dirY = 0;
                break;

            case '6':
                pacman.dirX = 1;
                pacman.dirY = 0;
                break;

            ///         3.11.2. Mise en pause
            case 'p':
                pause = 1;
                while(pause)
                {
                    if(getch() == 'p')
                        pause = 0;
                }
                break;

            ///         3.11.3. Quitter
            case 'q':
                fin = 1;
                break;
            }
        }

        ///     3.12. Afficher éléments
        ///         3.12.1. Afficher diamants
        color(11,0);
        for(i=0; i<_totalDiamants; i++)
        {
            plateau[diamants[i].posY][diamants[i].posX] = diamants[i].forme;
            affiche(plateau, diamants[i].posX, diamants[i].posY, _params->bordure);
        }

        ///         3.12.2. Afficher Pacman
        color(2,0);
        plateau[pacman.posY][pacman.posX] = pacman.forme;
        affiche(plateau, pacman.posX, pacman.posY, _params->bordure);

        ///         3.12.3. Afficher fantômes
        color(12,0);
        for(i=0; i<NB_GHOSTS; i++)
        {
            plateau[fantomes[i].posY][fantomes[i].posX]=fantomes[i].forme;
            affiche(plateau, fantomes[i].posX, fantomes[i].posY, _params->bordure);
        }

        ///         3.12.4. Afficher score
        color(15,0);
        gotoligcol(LIG+3,8);
        printf("%d",_score[0]+_score[1]+_score[2]);

        ///         3.12.5. Afficher vies
        gotoligcol(LIG+4,7);
        printf("%d",pacman.vies);

        compteurBoucle++;
    }

    free(diamants);
    Sleep(2000);
    return gagne;
}

int tableau4(Parametres *_params, int _score[NB_TAB], int _totalDiamants)
{
    char plateau[LIG][COL] = {"                                                  ",
                              "                                                  ",
                              "     \xDB\xDB\xDB\xDB\xDB                              \xDB\xDB\xDB\xDB\xDB     ",
                              "     \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB     \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB     ",
                              "     \xDB\xDB\xDB\xDB\xDB                              \xDB\xDB\xDB\xDB\xDB     ",
                              "       \xDB                                  \xDB       ",
                              "       \xDB                                  \xDB       ",
                              "       \xDB                                  \xDB       ",
                              "                      \xDB\xDB\xDB\xDB\xDB                       ",
                              "                      \xDB\xDB\xDB\xDB\xDB                       ",
                              "                      \xDB\xDB\xDB\xDB\xDB                       ",
                              "                      \xDB\xDB\xDB\xDB\xDB                       ",
                              "       \xDB                                  \xDB       ",
                              "       \xDB                                  \xDB       ",
                              "       \xDB                                  \xDB       ",
                              "     \xDB\xDB\xDB\xDB\xDB                              \xDB\xDB\xDB\xDB\xDB     ",
                              "     \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB     \xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB\xDB     ",
                              "     \xDB\xDB\xDB\xDB\xDB                              \xDB\xDB\xDB\xDB\xDB     ",
                              "                                                  ",
                              "                                                  "
                             };
    t_snake snake;
    t_diamant *diamants;
    t_diamant yukunkun;
    t_ghost ghosts[NB_GHOSTS];

    int nbDiamants, i, fin, gagne, compteurBoucle, recommencer;
    int vitesseFantomes[NB_GHOSTS];

///1.	Initialiser tableau
    nbDiamants = _totalDiamants;
    fin = 0;
    gagne = 0;
    compteurBoucle = 0;
    recommencer = 0;

    vitesseFantomes[0] = 4;
    vitesseFantomes[1] = 4;
    vitesseFantomes[2] = 1;
    vitesseFantomes[3] = 1;

    diamants = (t_diamant*)malloc(_totalDiamants*sizeof(t_diamant));
    if(!diamants)
    {
        printf("Erreur initialisation des diamants. Veuillez relancer le jeu.");
        return 0;
    }

///     1.1.	Initialiser snake
    initialiserSnake(&snake,6,plateau);

///     1.2.	Initialiser diamants
    for(i=0; i<_totalDiamants; i++)
        initialiserDiamant(&diamants[i],plateau);

///     1.3.	Initialiser Yukunkun
    initialiserDiamant(&yukunkun,plateau);
    yukunkun.forme = ' '; // Ne doit pas apparaître à l'initialisation

///     1.4.	Initialiser fantômes
    for(i=0; i<NB_GHOSTS; i++)
        initialiserGhost(&ghosts[i],vitesseFantomes[i],plateau);

///     1.5.	Initialiser plateau
    plateau[snake.ancre->posY][snake.ancre->posX] = snake.ancre->forme;

    for(i=0; i<_totalDiamants; i++)
        plateau[diamants[i].posY][diamants[i].posX] = diamants[i].forme;

    for(i=0; i<NB_GHOSTS; i++)
        plateau[ghosts[i].posY][ghosts[i].posX] = ghosts[i].forme;

    plateau[yukunkun.posY][yukunkun.posX] = yukunkun.forme;

///2.	Afficher plateau
    afficherPlateau(plateau,_params->bordure);

    gotoligcol(LIG+3,0);
    printf("Score : %d",_score[0]+_score[1]+_score[2]+_score[3]);

    gotoligcol(LIG+4,0);
    printf("Vies : %d",snake.vies);

    printf("\nAppuyer sur q pour revenir au menu\n");
    printf("Appuyer sur p pour mettre en pause");

///3.	Boucle de jeu
    while(!fin)
    {
///     3.1.	Si le tableau doit être recommencé
        if(recommencer)
        {
            Sleep(2000);

            int nbViesPrecedent;

            nbViesPrecedent = snake.vies;

///         3.1.1. Effacer éléments
            for(i=0; i<_totalDiamants; i++)
            {
                plateau[diamants[i].posY][diamants[i].posX] = ' ';
            }

            plateau[yukunkun.posY][yukunkun.posX] = ' ';

            for(i=0; i<NB_GHOSTS; i++)
            {
                plateau[ghosts[i].posY][ghosts[i].posX]=' ';
            }

            effacerSnake(&snake, plateau);

///         3.1.2.	Initialiser tableau
            fin = 0;
            gagne = 0;
            compteurBoucle = 0;
            recommencer = 0;

            supprimerSnake(&snake);
            initialiserSnake(&snake,6,plateau);
            snake.vies = nbViesPrecedent;

            for(i=0; i<_totalDiamants; i++)
                initialiserDiamant(&diamants[i],plateau);

            initialiserDiamant(&yukunkun,plateau);
            yukunkun.forme = ' '; // Ne doit pas apparaître à l'initialisation

            for(i=0; i<NB_GHOSTS; i++)
                initialiserGhost(&ghosts[i],vitesseFantomes[i],plateau);

            plateau[snake.ancre->posY][snake.ancre->posX] = snake.ancre->forme;

            for(i=0; i<_totalDiamants-nbDiamants; i++)
                diamants[i].forme = ' '; // Effacer les diamants déjà mangés avant de recommencer

            for(i=0; i<_totalDiamants; i++)
                plateau[diamants[i].posY][diamants[i].posX] = diamants[i].forme;

            for(i=0; i<NB_GHOSTS; i++)
                plateau[ghosts[i].posY][ghosts[i].posX] = ghosts[i].forme;

            plateau[yukunkun.posY][yukunkun.posX] = yukunkun.forme;

///         3.1.3.	Effacer écran
            system("cls");

///         3.1.4.	Afficher plateau
            afficherPlateau(plateau,_params->bordure);

            gotoligcol(LIG+3,0);
            printf("Score : %d",_score[0]+_score[1]+_score[2]+_score[3]);

            gotoligcol(LIG+4,0);
            printf("Vies : %d",snake.vies);

            printf("\nAppuyer sur q pour revenir au menu\n");
            printf("Appuyer sur p pour mettre en pause");
        }

        switch(_params->vitesseInitale)
        {
        case 1:
            Sleep(200);
            break;

        case 2:
            Sleep(100);
            break;

        case 3:
            Sleep(50);
            break;
        }

///     3.2.	Mise à jour fantômes selon la vitesse
        for(i=0; i<NB_GHOSTS; i++)
        {
            if(compteurBoucle%ghosts[i].vitesse == 0)
            {
                updateGhost(&ghosts[i],plateau,_params->bordure);
            }
        }

///     3.3.	Mise à jour Snake
        updateSnake(&snake,plateau,_params->bordure);

///     3.4.	Générer Yukunkun
///         3.4.1.	Si le Yukunkun n’est pas déjà apparu alors le Yukunkun a une probabilité de 1/10 d’apparaître à chaque boucle
        if(plateau[yukunkun.posY][yukunkun.posX] == ' ' && (rand()%20 == 1))
        {
///             3.4.1.1.	Mettre à jour forme
            yukunkun.forme = '*';
///             3.4.1.2.	Positionner Yukunkun
            do
            {
                yukunkun.posX = rand()%COL;
                yukunkun.posY = rand()%LIG;
            }
            while(plateau[yukunkun.posY][yukunkun.posX] != ' ');
        }
///         3.4.2.	Sinon le Yukunkun a une probabilité de 1/10 de disparaître
        else if(plateau[yukunkun.posY][yukunkun.posX] == '*' && (rand()%50 == 1))
        {
///             3.4.2.1.	Mettre à jour forme
            yukunkun.forme = ' ';
        }

///     3.5.	Tester collision bordure (Snake)
        if(testBordureSnake(&snake,_params->bordure) && _params->bordure)
        {
            recommencer = 1;
        }

///     3.6.	Tester collision bordure (fantômes)
        for(i=0; i<NB_GHOSTS; i++)
            testBordureGhost(&ghosts[i],_params->bordure);

///     3.7.	Tester collision fantômes et tête du snake
        for(i=0; i<NB_GHOSTS; i++)
        {
            if(testTeteSnakeGhost(&snake, &ghosts[i]))
            {
///         3.7.1.	Décrémenter le nombre de vie de 1
                snake.vies--;
///         3.7.2.	Redémarrer le tableau
                recommencer = 1;
            }
        }


///     3.8.	Tester collision fantômes et corps du Snake
        for(i=0; i<NB_GHOSTS; i++)
        {
            t_corps *queueAcouper, *pt;
            if(testCorpsSnakeGhost(&snake,&ghosts[i],&queueAcouper))
            {
///         3.8.2.	Afficher la queue coupée par du vide
                pt = queueAcouper;
                while(pt!=NULL)
                {
                    plateau[pt->posY][pt->posX] = ' ';
                    affiche(plateau, pt->posX, pt->posY, _params->bordure);
                    pt = pt->suivant;
                }
///         3.8.3.	Couper le snake
                supprimer_queue(&snake,queueAcouper);
            }
        }
///     3.9.	Tester collision tête et corps du Snake
        if(testCorpsTeteSnake(&snake))
        {
///         3.9.2.	Diminuer le nombre de vie de 1 et recommencer
            snake.vies--;
            recommencer = 1;
        }

///     3.9.	Tester collision diamants
        for(i=0; i<_totalDiamants; i++)
        {
            if(testSnakeDiamant(&snake, &diamants[i], plateau))
            {
///         3.3.1. Augmenter score de 10
                _score[3] += 1;
///         3.3.2. Décrémenter nombre de diamants restants de 1
                nbDiamants--;
///         3.9.3.	Allonger le snake en queue de 1
                ajouter_queue(&snake);
            }

        }

///     3.10.	Tester collision Yukunkun
        if(testSnakeYukunkun(&snake, &yukunkun, plateau))
        {
///         3.10.1.	Augmenter score de 5
            _score[3] += 5;
///         3.10.3.	Allonger le snake en queue de 5
            for(i=0; i<5; i++)
                ajouter_queue(&snake);
///         3.10.4.	Incrémenter le nombre de vie de 1
            snake.vies++;
        }

///     3.11.	Tester collision Snake et murs
        if(testSnakeMur(&snake,plateau))
        {
            if(snake.ancre->suivant != NULL)
            {
                snake.ancre->suivant->posX = snake.ancre->posX - snake.ancre->dirX;
                snake.ancre->suivant->posY = snake.ancre->posY - snake.ancre->dirY;
            }
        }

///     3.12.	Tester collision fantômes et murs
        for(i=0; i<NB_GHOSTS; i++)
            testGhostMur(&ghosts[i], plateau);

///     3.13. Tester nombre de vie
///         3.13.1. Si nombre de vie nul, afficher "Game over" et retourner 0
        if(snake.vies <= 0)
        {
            gotoligcol(LIG/2, COL/2-5);
            printf("GAME OVER");
            fin=1;
            gagne=0;
        }

///     3.14. Tester nombre de diamants restants
///         3.14.1. Si nombre de diamants restants nul, afficher "Gagné !" et retourner 1
        if(nbDiamants == 0)
        {
            gotoligcol(LIG/2, COL/2-3);
            printf("WIN !");
            fin=1;
            gagne=1;
        }

///     3.15. Traquer Pacman
        for(i=0; i<NB_GHOSTS; i++)
        {
            deplacerGhost(&ghosts[i]);
        }

///     3.16. Appuie d'une touche utilisateur
        if(kbhit())
        {
            char touche;
            int pause;
            touche = getch();

            switch(touche)
            {
///         3.16.1. Selon la touche, modifier la direction du pacman

            case '8':
                snake.ancre->dirX = 0;
                snake.ancre->dirY = -1;
                break;

            case '2':
                snake.ancre->dirX = 0;
                snake.ancre->dirY = 1;
                break;

            case '4':
                snake.ancre->dirX = -1;
                snake.ancre->dirY = 0;
                break;

            case '6':
                snake.ancre->dirX = 1;
                snake.ancre->dirY = 0;
                break;

///         3.16.2. Mise en pause
            case 'p':
                pause = 1;
                while(pause)
                {
                    if(getch() == 'p')
                        pause = 0;
                }
                break;

///         3.16.3. Quitter
            case 'q':
                fin = 1;
                break;
            }
        }

///     3.17. Afficher éléments
///         3.17.1. Afficher diamants
        color(11,0);
        for(i=0; i<_totalDiamants; i++)
        {
            plateau[diamants[i].posY][diamants[i].posX] = diamants[i].forme;
            affiche(plateau, diamants[i].posX, diamants[i].posY, _params->bordure);
        }

///         3.17.2. Afficher Yukunkun
        color(14,0);
        plateau[yukunkun.posY][yukunkun.posX] = yukunkun.forme;
        affiche(plateau, yukunkun.posX, yukunkun.posY, _params->bordure);

///         3.17.3. Afficher Snake
        color(2,0);
        afficherSnake(&snake, plateau, _params->bordure);

///         3.17.4. Afficher fantômes
        color(12,0);
        for(i=0; i<NB_GHOSTS; i++)
        {
            plateau[ghosts[i].posY][ghosts[i].posX]=ghosts[i].forme;
            affiche(plateau, ghosts[i].posX, ghosts[i].posY, _params->bordure);
        }

///         3.17.5. Afficher score
        color(15,0);
        gotoligcol(LIG+3,8);
        printf("%d",_score[0]+_score[1]+_score[2]+_score[3]);

///         3.17.6. Afficher vies
        gotoligcol(LIG+4,7);
        printf("%d",snake.vies);

        compteurBoucle++;
    }

    supprimerSnake(&snake);
    free(diamants);

    Sleep(2000);
    return gagne;
}

