#include "Tableaux.h"

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
        _pacman->posX = rand()%COL;
        _pacman->posY = rand()%LIG;
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

void updateGhost(t_ghost *_ghost, char _plateau[LIG][COL], int _bordure)
{
    _plateau[_ghost->posY][_ghost->posX] = ' ';
    affiche(_plateau, _ghost->posX,_ghost->posY, _bordure);

    _ghost->posX += _ghost->dirX;
    _ghost->posY += _ghost->dirY;

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

int testPacmanGhost(t_pacman *_pacman, t_ghost _ghost)
{
    if((_pacman->posX==_ghost.posX)&&(_pacman->posY==_ghost.posY))
    {
        _pacman->vies--;
        return 1;
    }

    return 0;
}

int testPacmanDiamant(t_pacman _pacman, t_diamant *_diamant, char _plateau[LIG][COL], int *_score, int *_nbDiamants)
{
    if(_pacman.posX == _diamant->posX && _pacman.posY == _diamant->posY && _plateau[_pacman.posY][_pacman.posX] == 'D')
    {
        ///         3.3.1. Augmenter score de 10
        *_score += 10;
        ///         3.3.2. Décrémenter nombre de diamants restants de 1
        (*_nbDiamants)--;
        ///         3.3.3. Mettre à jour diamant
        _diamant->forme = ' ';

        return 1;
    }

    return 0;
}

int testPacmanMur(t_pacman *_pacman, char _plateau[LIG][COL])
{
    if(_plateau[_pacman->posY][_pacman->posX] == '#')
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
    if(_plateau[_ghost->posY+_ghost->dirY][_ghost->posX+_ghost->dirX] == '#')
    {
        _ghost->dirX = 0;
        _ghost->dirY = 0;
        return 1;
    }

    return 0;
}

int tableau1(Parametres _params, int _score[NB_TAB])
{
    char plateau[LIG][COL];
    int nbDiamants, i, j, fin, gagne;
    t_diamant diamants[5];
    t_pacman pacman;

    srand(time(NULL));
    /// 1. Initialiser tableau
    nbDiamants = 5;
    fin = 0;
    gagne = 0;

    for(i=0; i<LIG; i++)
    {
        for(j=0; j<COL; j++)
        {
            plateau[i][j] = ' ';
        }
    }

    ///     1.1. Initialiser pacman
    initialiserPacman(&pacman, _params.vitesseInitale, plateau);

    ///     1.2. Initialiser les diamants
    for(i=0; i<5; i++)
    {
        initialiserDiamant(&diamants[i], plateau);
    }

    ///     1.3. Initialiser plateau
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
        switch(_params.vitesseInitale)
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
        for(i=0;i<5;i++)
            testPacmanDiamant(pacman,&diamants[i],plateau,&_score[0],&nbDiamants);

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
    int nbDiamants, i, j, fin, gagne;
    t_diamant diamants[5];
    t_pacman pacman;
    t_ghost fantomes[4];

    srand(time(NULL));

    /// 1. Initialiser tableau
    nbDiamants = 5;
    fin = 0;
    gagne = 0;

    for(i=0; i<LIG; i++)
    {
        for(j=0; j<COL; j++)
        {
            plateau[i][j] = ' ';
        }
    }

    ///     1.1. Initialiser pacman
    initialiserPacman(&pacman,_params.vitesseInitale, plateau);

    ///     1.2. Initialiser les diamants
    for(i=0; i<5;i++)
        initialiserDiamant(&diamants[i], plateau);

    ///     1.3. Initialiser fantômes
    for(i=0;i<4;i++)
        initialiserGhost(&fantomes[i],_params.vitesseInitale, plateau);

    ///     1.4. Initialiser plateau
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
        switch(_params.vitesseInitale)
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
        for(i=0;i<4;i++)
            updateGhost(&fantomes[i],plateau,_params.bordure);

        ///     3.2. Mise à jour position Pacman selon la direction
        updatePacman(&pacman,plateau,_params.bordure);

        ///     3.3. Tester collision bordure (Pacman)
        ///         3.3.1. Si bordure activé, décrémenter nombre de vie de 1 et faire rebondir Pacman
        testBordurePacman(&pacman,_params.bordure);

        ///     3.4. Tester collision bordure (fantômes)
        for(i=0;i<4;i++)
            testBordureGhost(&fantomes[i], _params.bordure);

        ///     3.5. Tester collision fantôme
        for(i=0;i<4;i++)
            testPacmanGhost(&pacman,fantomes[i]);

        ///     3.6. Tester collision diamant
        for(i=0;i<5;i++)
            testPacmanDiamant(pacman,&diamants[i],plateau,&_score[1],&nbDiamants);

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
        for(i=0; i<5; i++)
        {
            plateau[diamants[i].posY][diamants[i].posX] = diamants[i].forme;
            affiche(plateau, diamants[i].posX, diamants[i].posY, _params.bordure);
        }

        ///         3.10.2. Afficher Pacman
        plateau[pacman.posY][pacman.posX] = pacman.forme;
        affiche(plateau, pacman.posX, pacman.posY, _params.bordure);

        ///         3.10.3. Afficher fantômes
        for(i=0; i<4; i++)
        {
            plateau[fantomes[i].posY][fantomes[i].posX]=fantomes[i].forme;
            affiche(plateau, fantomes[i].posX, fantomes[i].posY, _params.bordure);
        }

        ///         3.10.4. Afficher score
        gotoligcol(LIG+3,8);
        printf("%d",_score[0]+_score[1]);

        ///         3.10.5. Afficher vies
        gotoligcol(LIG+4,7);
        printf("%d",pacman.vies);
    }

    Sleep(2000);
    return gagne;
}

int tableau3(Parametres _params, int _score[NB_TAB])
{

    char   plateau[LIG][COL] = {"                                                  ",
                                "                                                  ",
                                "     #####                              #####     ",
                                "     #################     ##################     ",
                                "     #####                              #####     ",
                                "       #                                  #       ",
                                "       #                                  #       ",
                                "       #                                  #       ",
                                "                      #####                       ",
                                "                      #####                       ",
                                "                      #####                       ",
                                "                      #####                       ",
                                "       #                                  #       ",
                                "       #                                  #       ",
                                "       #                                  #       ",
                                "     #####                              #####     ",
                                "     #################     ##################     ",
                                "     #####                              #####     ",
                                "                                                  ",
                                "                                                  "
                               };
    int nbDiamants, i, fin, gagne;
    t_diamant diamants[5];
    t_pacman pacman;
    t_ghost fantomes[4];

    srand(time(NULL));

    /// 1. Initialiser tableau
    nbDiamants = 5;
    fin = 0;
    gagne = 0;

    ///     1.1. Initialiser pacman
    initialiserPacman(&pacman,_params.vitesseInitale, plateau);

    ///     1.2. Initialiser les diamants
    for(i=0;i<5;i++)
        initialiserDiamant(&diamants[i], plateau);

    ///     1.3. Initialiser fantômes
    for(i=0;i<4;i++)
        initialiserGhost(&fantomes[i],_params.vitesseInitale, plateau);

    ///     1.4. Initialiser plateau
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
    printf("Score : %d",_score[0]+_score[1]+_score[2]);

    gotoligcol(LIG+4,0);
    printf("Vies : %d",pacman.vies);

    /// 3. Boucle de jeu
    while(!fin)
    {
        switch(_params.vitesseInitale)
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

        ///     3.1. Mise à jour
        for(i=0;i<4;i++)
            updateGhost(&fantomes[i],plateau,_params.bordure);

        ///     3.2. Mise à jour position Pacman selon la direction
        updatePacman(&pacman,plateau,_params.bordure);

        ///     3.3. Tester collision bordure (Pacman)
        ///         3.3.1. Si bordure activé, décrémenter nombre de vie de 1 et faire rebondir Pacman
        testBordurePacman(&pacman,_params.bordure);

        ///     3.4. Tester collision bordure (fantômes)
        for(i=0;i<4;i++)
            testBordureGhost(&fantomes[i], _params.bordure);

        ///     3.5. Tester collision fantôme
        for(i=0;i<4;i++)
            testPacmanGhost(&pacman,fantomes[i]);

        ///     3.6. Tester collision diamant
        for(i=0;i<5;i++)
            testPacmanDiamant(pacman,&diamants[i],plateau,&_score[2],&nbDiamants);

        testPacmanMur(&pacman,plateau);

        for(i=0;i<4;i++)
            testGhostMur(&fantomes[i],plateau);

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
        for(i=0; i<5; i++)
        {
            plateau[diamants[i].posY][diamants[i].posX] = diamants[i].forme;
            affiche(plateau, diamants[i].posX, diamants[i].posY, _params.bordure);
        }

        ///         3.10.2. Afficher Pacman
        plateau[pacman.posY][pacman.posX] = pacman.forme;
        affiche(plateau, pacman.posX, pacman.posY, _params.bordure);

        ///         3.10.3. Afficher fantômes
        for(i=0; i<4; i++)
        {
            plateau[fantomes[i].posY][fantomes[i].posX]=fantomes[i].forme;
            affiche(plateau, fantomes[i].posX, fantomes[i].posY, _params.bordure);
        }

        ///         3.10.4. Afficher score
        gotoligcol(LIG+3,8);
        printf("%d",_score[0]+_score[1]+_score[2]);

        ///         3.10.5. Afficher vies
        gotoligcol(LIG+4,7);
        printf("%d",pacman.vies);
    }

    Sleep(2000);
    return gagne;
}

int tableau4(Parametres _params, int _score[NB_TAB])
{
    return 0;
}

