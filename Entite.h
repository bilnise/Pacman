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

typedef struct data {
    int posX;
    int posY;
    char forme;
    int dirX;
    int dirY;
    int vitesse;
}t_data;

typedef struct corps {
    t_data infos;
    struct corps *suivant;
}t_corps;

#endif // ENTITE_H_INCLUDED
