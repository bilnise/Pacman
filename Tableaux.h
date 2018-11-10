#ifndef TABLEAUX_H_INCLUDED
#define TABLEAUX_H_INCLUDED

#include "Entite.h"
#include "Parametres.h"
#include "Constantes.h"
#include "utils.h"


int tableau1(Parametres _params, int _score[NB_TAB]);
int tableau2(Parametres _params, int _score[NB_TAB]);
int tableau3(Parametres _params, int _score[NB_TAB]);
int tableau4(Parametres _params, int _score[NB_TAB]);

void initialiserDiamants(t_diamant _diamants[5], int _tab_positions[][2], int _nb_elements);
void initialiserPacman(t_pacman *_pacman, int _vitesse, int _tab_positions[][2]);
void initialiserGhosts(t_ghost _ghosts[4], int _vitesse, int _tab_positions[][2], int _nb_elements);

void afficherPlateau(char _plateau[LIG][COL], int _bordure);

void updatePacman(t_pacman *_pacman, char _plateau[LIG][COL], int _bordure);
void updateGhosts(t_ghost _ghosts[4], char _plateau[LIG][COL], int _bordure);
void testBordurePacman(t_pacman * _pacman, int _bordure);
void testBordureGhosts(t_ghost _ghosts[4], int _bordure);
void testPacmanGhosts(t_pacman *pacman, t_ghost _ghosts[4]);
void testPacmanDiamants(t_pacman _pacman, t_diamant _diamants[4], char _plateau[LIG][COL], int *_score, int *_nbDiamants);
void testPacmanMur(t_pacman *_pacman, char _plateau[LIG][COL]);
void testGhostsMur(t_ghost _ghosts[4], char _plateau[LIG][COL]);


#endif // TABLEAUX_H_INCLUDED
