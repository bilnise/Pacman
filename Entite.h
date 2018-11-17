#ifndef ENTITE_H_INCLUDED
#define ENTITE_H_INCLUDED

typedef struct pacman {
    int posX;
    int posY;
    int vies;
    char forme;
    int dirX;
    int dirY;
    int vitesse;
}t_pacman;

typedef struct ghost {
    int posX;
    int posY;
    char forme;
    int dirX;
    int dirY;
    int vitesse;
    int cibleX;
    int cibleY;
}t_ghost;

typedef struct diamant {
    int posX;
    int posY;
    char forme;
}t_diamant;

typedef struct corps {
    int posX;
    int posY;
    char forme;
    int dirX;
    int dirY;
    struct corps *suivant;
    struct corps *precedent;
}t_corps;

typedef struct snake {
    t_corps *ancre;
    int vies;
    int vitesse;
}t_snake;

#endif // ENTITE_H_INCLUDED
