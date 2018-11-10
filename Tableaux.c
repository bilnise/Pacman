#include "Tableaux.h"

void initialiserPacman(t_pacman *_pacman, int _vitesseInitiale,  int _tab_positions[][2])
{
    _pacman->forme = 'X';
    _pacman->vies = 5;
    _pacman->vitesse = _vitesseInitiale;
    _pacman->posX = rand()%COL;
    _pacman->posY = rand()%LIG;
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

    _tab_positions[0][0] = _pacman->posX;
    _tab_positions[0][1] = _pacman->posY;
}

void initialiserDiamants(t_diamant _diamants[4], int _tab_positions[][2], int _nb_elements)
{
    int i,j;
    int superposition;

    superposition = 0;

    for(i=0; i<5; i++)
    {
        _diamants[i].forme = 'D';

        do
        {
            _diamants[i].posX = rand()%COL;
            _diamants[i].posY = rand()%LIG;

            ///         1.2.1. Vérifier les superpositions
            for(j=0; j<_nb_elements; j++)
            {
                if(_diamants[i].posX == _tab_positions[j][0] && _diamants[i].posY == _tab_positions[j][1])
                    superposition = 1;
                else
                    superposition = 0;
            }
        }
        while(superposition);

        _tab_positions[i+1][0] = _diamants[i].posX;
        _tab_positions[i+1][1] = _diamants[i].posY;
    }
}

void initialiserGhosts(t_ghost _ghosts[4], int _vitesse, int _tab_positions[][2], int _nb_elements)
{
    int i, j, superposition;

    for(i=0; i<4; i++)
    {
        _ghosts[i].forme = 'G';
        _ghosts[i].vitesse = _vitesse;
        _ghosts[i].cibleX = 0;
        _ghosts[i].cibleY = 0;
        _ghosts[i].dirX = 1;
        _ghosts[i].dirY = 0;

        do
        {
            _ghosts[i].posX = rand()%COL;
            _ghosts[i].posY = rand()%LIG;

            ///         1.3.1. Vérifier les superpositions

            for(j=0; j<_nb_elements; j++)
            {
                if(_ghosts[i].posX == _tab_positions[j][0] && _ghosts[i].posY == _tab_positions[j][1])
                    superposition = 1;
                else
                    superposition = 0;
            }
        }
        while(superposition);

        _tab_positions[i+6][0] = _ghosts[i].posX;
        _tab_positions[i+6][1] = _ghosts[i].posY;
    }
}

void afficherPlateau(char _plateau[LIG][COL], int _bordure)
{
    int i,j;
    ///         2.1. Mettre la bordure si activée
    if(_bordure)
    {
        system("mode con lines=25 cols=52");
        for(i=0; i<COL+2; i++)
        {
            printf("_");
        }
        printf("\n");
        for(i=0; i<LIG; i++)
        {
            printf("|");
            for(j=0; j<COL; j++)
            {
                printf("%c", _plateau[i][j]);
            }
            printf("|\n");
        }
        for(i=0; i<COL+2; i++)
        {
            printf("_");
        }
    }
    else ///    2.2. Sinon, ne pas dessiner la bordure
    {
        system("mode con lines=25 cols=50");
        for(i=0; i<LIG; i++)
        {
            for(j=0; j<COL; j++)
            {
                printf("%c", _plateau[i][j]);
            }
        }

        for(i=0; i<COL; i++)
        {
            printf("-");
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

void updateGhosts(t_ghost _ghosts[4], char _plateau[LIG][COL], int _bordure)
{
    int i;

    for(i=0; i<4; i++)
    {
        _plateau[_ghosts[i].posY][_ghosts[i].posX] = ' ';
        affiche(_plateau, _ghosts[i].posX,_ghosts[i].posY, _bordure);

        _ghosts[i].posX += _ghosts[i].dirX;
        _ghosts[i].posY += _ghosts[i].dirY;
        _ghosts[i].dirX=(rand()%3)-1;
        _ghosts[i].dirY=(rand()%3)-1;

        if(_ghosts[i].dirX != 0)
        {
            _ghosts[i].dirY = 0;
        }
        else
        {
            do
            {
                _ghosts[i].dirY = -1+rand()%3;
            }
            while(_ghosts[i].dirY == 0); // si par mal chance dirY vaut 0 on recommence

        }
    }
}

void testBordurePacman(t_pacman * _pacman, int _bordure)
{
    ///         3.2.1. Si bordure activé, décrémenter nombre de vie de 1 et arreter Pacman
    if(_bordure)
    {
        if(_pacman->posX < 0)
        {
            _pacman->vies--;
            _pacman->posX = 0;
            _pacman->dirX = 0;
        }
        else if(_pacman->posX >= COL)
        {
            _pacman->vies--;
            _pacman->posX = COL-1;
            _pacman->dirX = 0;
        }
        else if(_pacman->posY < 0)
        {
            _pacman->vies--;
            _pacman->posY = 0;
            _pacman->dirY = 0;
        }
        else if(_pacman->posY >= LIG)
        {
            _pacman->vies--;
            _pacman->posY = LIG-1;
            _pacman->dirY = 0;
        }
    }
    ///         3.2.2. Sinon, faire réapparaitre Pacman de l'autre coté
    else
    {
        if(_pacman->posX < 0)
        {
            _pacman->posX = COL-1;
        }
        else if(_pacman->posX >= COL)
        {
            _pacman->posX = 0;
        }
        else if(_pacman->posY < 0)
        {
            _pacman->posY = LIG-1;
        }
        else if(_pacman->posY >= LIG)
        {
            _pacman->posY = 0;
        }
    }
}

void testBordureGhosts(t_ghost fantomes[4], int _bordure)
{
    int i;
    ///     3.5. Tester collision bordure (fantômes)
    ///         3.5.1. Si bordure activé, faire rebondir fantôme

    if(_bordure)
    {
        for(i=0; i<4; i++)
        {
            if(fantomes[i].posX<0)
            {
                fantomes[i].posX=0;
                fantomes[i].dirX=1;
            }
            else if(fantomes[i].posX>=COL)
            {
                fantomes[i].posX=COL-1;
                fantomes[i].dirX=-1;
            }
            else if(fantomes[i].posY>=LIG)
            {
                fantomes[i].posY=LIG-1;
                fantomes[i].dirY=-1;
            }
            else if(fantomes[i].posY<0)
            {
                fantomes[i].posY=0;
                fantomes[i].dirY=1;
            }
        }
    }

    ///         3.5.2. Sinon, faire réapparaitre fantôme de l'autre coté

    else
    {
        for(i=0; i<4; i++)
        {
            if(fantomes[i].posX < 0)
            {
                fantomes[i].posX = COL-1;
            }
            else if(fantomes[i].posX >= COL)
            {
                fantomes[i].posX = 0;
            }
            else if(fantomes[i].posY < 0)
            {
                fantomes[i].posY = LIG-1;
            }
            else if(fantomes[i].posY >= LIG)
            {
                fantomes[i].posY = 0;
            }
        }
    }
}

void testPacmanGhosts(t_pacman *_pacman, t_ghost _ghosts[4])
{
    int i;
    for (i=0; i<4; i++)
    {
        if((_pacman->posX==_ghosts[i].posX)&&(_pacman->posY==_ghosts[i].posY))
        {
            _pacman->vies--;

        }
    }
}

void testPacmanDiamants(t_pacman _pacman, t_diamant _diamants[4], char _plateau[LIG][COL], int *_score, int *_nbDiamants)
{
    int i;
    if(_plateau[_pacman.posY][_pacman.posX] == 'D')
    {
        ///         3.3.1. Augmenter score de 10
        *_score += 10;
        ///         3.3.2. Décrémenter nombre de diamants restants de 1
        (*_nbDiamants)--;
        ///         3.3.3. Mettre à jour plateau
        for(i=0; i<5; i++)
        {
            if(_diamants[i].posX == _pacman.posX && _diamants[i].posY == _pacman.posY)
                _diamants[i].forme = ' ';
        }
    }
}

int tableau1(Parametres _params, int _score[NB_TAB])
{
    char plateau[LIG][COL];
    int tab_positions[6][2];
    int nbDiamants, i, j, fin, gagne;
    t_diamant diamants[5];
    t_pacman pacman;

    srand(time(NULL));
    /// 1. Initialiser tableau
    nbDiamants = 5;
    fin = 0;
    gagne = 0;

    for(i=0; i<6; i++)
    {
        tab_positions[i][0] = -1;
        tab_positions[i][1] = -1;
    }

    ///     1.1. Initialiser pacman
    initialiserPacman(&pacman, _params.vitesseInitale, tab_positions);

    tab_positions[0][0] = pacman.posX;
    tab_positions[0][1] = pacman.posY;

    ///     1.2. Initialiser les diamants
    initialiserDiamants(diamants, tab_positions, 6);

    ///     1.3. Initialiser plateau
    for(i=0; i<LIG; i++)
    {
        for(j=0; j<COL; j++)
        {
            plateau[i][j] = ' ';
        }
    }

    plateau[pacman.posY][pacman.posX] = pacman.forme;
    for(i=0; i<5; i++)
    {
        plateau[diamants[i].posY][diamants[i].posX] = diamants[i].forme;
    }

    system("cls");
    /// 2. Afficher plateau
    afficherPlateau(plateau, _params.bordure);

    gotoligcol(LIG+3,0);
    printf("Score : %d",_score[0]);

    gotoligcol(LIG+4,0);
    printf("Vies : %d",pacman.vies);

    /// 3. Boucle de jeu
    while(!fin)
    {
        fflush(stdin);
        Sleep(250/_params.vitesseInitale);
        ///     3.1. Mise à jour position Pacman selon la direction
        updatePacman(&pacman,plateau, _params.bordure);
        ///     3.2. Tester collision bordure
        testBordurePacman(&pacman, _params.bordure);
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
        testPacmanDiamants(pacman,diamants,plateau,&_score[0],&nbDiamants);
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
        for(i=0; i<5; i++)
        {
            plateau[diamants[i].posY][diamants[i].posX] = diamants[i].forme;
            affiche(plateau, diamants[i].posX, diamants[i].posY, _params.bordure);
        }
        ///         3.7.2. Afficher Pacman
        plateau[pacman.posY][pacman.posX] = pacman.forme;
        affiche(plateau, pacman.posX, pacman.posY, _params.bordure);
        ///         3.7.3. Afficher score
        gotoligcol(LIG+3,8);
        printf("%d",_score[0]);
        ///         3.7.4. Afficher vies
        gotoligcol(LIG+4,7);
        printf("%d",pacman.vies);
    }

    return gagne;
}

int tableau2(Parametres _params, int _score[NB_TAB])
{
    char plateau[LIG][COL];
    int tab_positions[10][2];
    int nbDiamants, i, j, fin, gagne;
    t_diamant diamants[5];
    t_pacman pacman;
    t_ghost fantomes[4];

    srand(time(NULL));

    /// 1. Initialiser tableau
    nbDiamants = 5;
    fin = 0;
    gagne = 0;

    for(i=0; i<10; i++)
    {
        tab_positions[i][0] = -1;
        tab_positions[i][1] = -1;
    }

    ///     1.1. Initialiser pacman
    initialiserPacman(&pacman,_params.vitesseInitale, tab_positions);

    ///     1.2. Initialiser les diamants
    initialiserDiamants(diamants, tab_positions, 10);

    ///     1.3. Initialiser fantômes
    initialiserGhosts(fantomes,_params.vitesseInitale, tab_positions, 10);

    ///     1.4. Initialiser plateau
    for(i=0; i<LIG; i++)
    {
        for (j=0; j<COL; j++)
        {
            plateau[i][j]=' ';
        }
    }

    plateau[pacman.posY][pacman.posX] = pacman.forme;
    for(i=0; i<5; i++)
    {
        plateau[diamants[i].posY][diamants[i].posX] = diamants[i].forme;
    }

    for(i=0; i<4; i++)
    {
        plateau[fantomes[i].posY][fantomes[i].posX]=fantomes[i].forme;
    }


    /// 2. Afficher plateau
    afficherPlateau(plateau,_params.bordure);

    gotoligcol(LIG+3,0);
    printf("Score : %d",_score[0]+_score[1]);

    gotoligcol(LIG+4,0);
    printf("Vies : %d",pacman.vies);

    /// 3. Boucle de jeu
    while(!fin)
    {
        Sleep(250/_params.vitesseInitale);

        ///     3.3. Mise à jour fantômes
        updateGhosts(fantomes,plateau,_params.bordure);

        ///     3.1. Mise à jour position Pacman selon la direction
        updatePacman(&pacman,plateau,_params.bordure);

        ///     3.4. Tester collision bordure (Pacman)
        ///         3.4.1. Si bordure activé, décrémenter nombre de vie de 1 et faire rebondir Pacman
        testBordurePacman(&pacman,_params.bordure);

        ///     3.5. Tester collision bordure (fantômes)
        testBordureGhosts(fantomes, _params.bordure);

        ///     3.6. Tester collision fantôme
        testPacmanGhosts(&pacman,fantomes);

        ///     3.7. Tester collision diamant
        testPacmanDiamants(pacman,diamants,plateau,&_score[1],&nbDiamants);

        ///     3.8. Tester nombre de vie
        ///         3.8.1. Si nombre de vie nul, afficher "Game over" et retourner 0
        if(pacman.vies == 0)
        {
            gotoligcol(LIG/2, COL/2-5);
            printf("GAME OVER");
            fin=1;
            gagne=0;
        }

        ///     3.9. Tester nombre de diamants restants
        ///         3.9.1. Si nombre de diamants restants nul, afficher "Gagné !" et retourner 1
        if(nbDiamants == 0)
        {
            gotoligcol(LIG/2, COL/2-3);
            printf("WIN !");
            fin=1;
            gagne=1;
        }

        ///     3.10. Appuie d'une touche utilisateur
        if(kbhit())
        {
            char touche;
            int pause;
            touche = getch();

            switch(touche)
            {
            ///         3.10.1. Selon la touche, modifier la direction du pacman

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

            ///         3.10.2. Mise en pause
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

        ///     3.11. Afficher éléments
        ///         3.11.1. Afficher diamants
        for(i=0; i<5; i++)
        {
            plateau[diamants[i].posY][diamants[i].posX] = diamants[i].forme;
            affiche(plateau, diamants[i].posX, diamants[i].posY, _params.bordure);
        }

        ///         3.11.2. Afficher Pacman
        plateau[pacman.posY][pacman.posX] = pacman.forme;
        affiche(plateau, pacman.posX, pacman.posY, _params.bordure);

        ///         3.11.3. Afficher fantômes
        for(i=0; i<4; i++)
        {
            plateau[fantomes[i].posY][fantomes[i].posX]=fantomes[i].forme;
            affiche(plateau, fantomes[i].posX, fantomes[i].posY, _params.bordure);
        }

        ///         3.1.4. Afficher score
        gotoligcol(LIG+3,8);
        printf("%d",_score[0]+_score[1]);

        ///         3.12.5. Afficher vies
        gotoligcol(LIG+4,7);
        printf("%d",pacman.vies);
    }

    Sleep(2000);
    return gagne;
}

int tableau3(Parametres _params, int _score[NB_TAB])
{

    /// 1. Initialiser tableau
    ///     1.1. Initialiser pacman
    ///     1.2. Initialiser diamants
    ///     1.3. Initialiser fantômes
    ///     1.4. Initialiser murs (aléatoirement ?)
    ///     1.5. Initialiser plateau
    ///         1.5.1. Mettre la bordure si activée
    /// 2. Afficher plateau
    /// 3. Boucle de jeu
    ///     3.1. Afficher éléments
    ///         3.1.1. Afficher diamants
    ///         3.1.2. Afficher Pacman
    ///         3.1.3. Afficher fantômes
    ///         3.1.4. Afficher score
    ///         3.1.5. Afficher vies
    ///     3.2. Mise à jour position Pacman selon la direction
    ///     3.3. Algorithme A*/pathfinding pour les fantômes
    ///     3.4. Mise à jour position fantômes selon la direction
    ///     3.5. Tester collision bordure (Pacman)
    ///         3.5.1. Si bordure activé, décrémenter nombre de vie de 1 et faire rebondir Pacman
    ///         3.5.2. Sinon, faire réapparaitre Pacman de l'autre coté
    ///     3.6. Tester collision bordure (fantômes)
    ///         3.6.1. Si bordure activé, faire rebondir fantôme
    ///         3.6.2. Sinon, faire réapparaitre fantôme de l'autre coté
    ///     3.7. Tester collision fantôme
    ///         3.7.1. Décrémenter nombre de vie de 1
    ///         3.7.2. Activer immunité pendant 3 déplacement du Pacman
    ///     3.8. Tester collision diamant
    ///         3.8.1. Augmenter score de 10
    ///         3.8.2. Augmenter vitesse du Pacman
    ///         3.8.3. Décrémenter nombre de diamants restants de 1
    ///         3.8.4. Mettre à jour plateau
    ///     3.9. Tester collision murs
    ///         3.9.1. Arrêter le déplacement du Pacman
    ///     3.9. Tester nombre de vie
    ///         3.9.1. Si nombre de vie nul, afficher "Game over" et retourner 0
    ///     3.10. Tester nombre de diamants restants
    ///         3.10.1. Si nombre de diamants restants nul, afficher "Gagné !" et retourner 1
    ///     3.11. Appuie d'une touche utilisateur
    ///         3.11.1. Selon la touche, modifier la direction du pacman
    ///         3.11.2. Mise en pause
    ///         3.11.3. Quitter
    ///             3.11.3.1. Retourner 0

    return 0;
}

int tableau4(Parametres _params, int _score[NB_TAB])
{
    return 0;
}

