#ifndef TABLEAUX_H_INCLUDED
#define TABLEAUX_H_INCLUDED

#include "windows.h"
#include "time.h"
#include "conio.h"

#include "Entite.h"
#include "Parametres.h"
#include "Constantes.h"
#include "utils.h"
#include "Jeu.h"


int tableau1(Parametres _params, int _score[NB_TAB]);
int tableau2(Parametres _params, int _score[NB_TAB]);
int tableau3(Parametres _params, int _score[NB_TAB]);
int tableau4(Parametres _params, int _score[NB_TAB]);

void initialiserDiamant(t_diamant *_diamant, char _plateau[LIG][COL]);
void initialiserPacman(t_pacman *_pacman, int _vitesse, char _plateau[LIG][COL]);
void initialiserGhost(t_ghost *_ghost, int _vitesse, char _plateau[LIG][COL]);

void afficherPlateau(char _plateau[LIG][COL], int _bordure);

void updatePacman(t_pacman *_pacman, char _plateau[LIG][COL], int _bordure);
void updateGhost(t_ghost *_ghost, char _plateau[LIG][COL], int _bordure);

int testBordurePacman(t_pacman * _pacman, int _bordure);
int testBordureGhost(t_ghost *_ghost, int _bordure);
int testPacmanGhost(t_pacman *pacman, t_ghost _ghost);
int testPacmanDiamant(t_pacman _pacman, t_diamant *_diamant, char _plateau[LIG][COL], int *_score, int *_nbDiamants);
int testPacmanMur(t_pacman *_pacman, char _plateau[LIG][COL]);
int testGhostMur(t_ghost *_ghost, char _plateau[LIG][COL]);


#endif // TABLEAUX_H_INCLUDED
