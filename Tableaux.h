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
void initialiserSnake(t_snake *_snake, int _vitesse, char _plateau[LIG][COL]);

void afficherPlateau(char _plateau[LIG][COL], int _bordure);
void afficherSnake(t_snake *_snake, char _plateau[LIG][COL], int bordure);

void updatePacman(t_pacman *_pacman, char _plateau[LIG][COL], int _bordure);
void updateGhost(t_ghost *_ghost, char _plateau[LIG][COL], int _bordure);
void updateSnake(t_snake *_snake, char _plateau[LIG][COL], int _bordure);

void deplacerGhost(t_ghost *_ghost);

int testBordurePacman(t_pacman *_pacman, int _bordure);
int testBordureGhost(t_ghost *_ghost, int _bordure);
int testPacmanGhost(t_pacman *_pacman, t_ghost *_ghost);
int testPacmanDiamant(t_pacman *_pacman, t_diamant *_diamant, char _plateau[LIG][COL]);
int testPacmanMur(t_pacman *_pacman, char _plateau[LIG][COL]);
int testGhostMur(t_ghost *_ghost, char _plateau[LIG][COL]);

int testBordureSnake(t_snake *_snake, int _bordure);
int testTeteSnakeGhost(t_snake *_snake, t_ghost *_ghost);
int testCorpsSnakeGhost(t_snake *_snake, t_ghost *_ghost, t_corps **_queueAcouper);
int testSnakeDiamant(t_snake *_snake, t_diamant *_diamant, char _plateau[LIG][COL]);
int testSnakeYukunkun(t_snake *_snake, t_diamant *_yukunkun, char _plateau[LIG][COL]);
int testSnakeMur(t_snake *_snake, char _plateau[LIG][COL]);

void ajouter_queue(t_snake *_snake);
void supprimer_queue(t_snake *_snake);


#endif // TABLEAUX_H_INCLUDED
