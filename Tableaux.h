#ifndef TABLEAUX_H_INCLUDED
#define TABLEAUX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "windows.h"
#include "time.h"
#include "math.h"

#include "Constantes.h"
#include "Entite.h"
#include "Tableaux.h"
#include "Parametres.h"
#include "utils.h"

int tableau1(Parametres *_params, int _score[NB_TAB], int _totalDiamants);
int tableau2(Parametres *_params, int _score[NB_TAB], int _totalDiamants);
int tableau3(Parametres *_params, int _score[NB_TAB], int _totalDiamants);
int tableau4(Parametres *_params, int _score[NB_TAB], int _totalDiamants);

void initialiserDiamant(t_diamant *_diamant, char _plateau[LIG][COL]);
void initialiserPacman(t_pacman *_pacman, int _vitesse, char _plateau[LIG][COL]);
void initialiserGhost(t_ghost *_ghost, int _vitesse, char _plateau[LIG][COL]);
void initialiserSnake(t_snake *_snake, int _vitesse, char _plateau[LIG][COL]);

void afficherPlateau(char _plateau[LIG][COL], int _bordure);
void afficherSnake(t_snake *_snake, char _plateau[LIG][COL], int bordure);
void effacerSnake(t_snake *_snake, char plateau[LIG][COL]);

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
int testCorpsTeteSnake(t_snake *_snake);
int testSnakeDiamant(t_snake *_snake, t_diamant *_diamant, char _plateau[LIG][COL]);
int testSnakeYukunkun(t_snake *_snake, t_diamant *_yukunkun, char _plateau[LIG][COL]);
int testSnakeMur(t_snake *_snake, char _plateau[LIG][COL]);

void ajouter_queue(t_snake *_snake);
void supprimer_queue(t_snake *_snake, t_corps *queueAcouper);
void supprimerSnake(t_snake *_snake);

void deplacerGhostIA(t_ghost *_ghost, char _plateau[LIG][COL]); // Non fonctionnelle (Boucle sans fin)
void genererSuccesseurs(t_noeud *_noeud, char _plateau[LIG][COL], t_noeud *successeurs[4]);


#endif // TABLEAUX_H_INCLUDED
