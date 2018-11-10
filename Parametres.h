#ifndef PARAMETRES_H_INCLUDED
#define PARAMETRES_H_INCLUDED

#include <stdio.h>

typedef struct t_params {

    int vitesseInitale;
    int bordure;

}Parametres;

int chargerParametres(Parametres *_params);


#endif // PARAMETRES_H_INCLUDED
