#include "Parametres.h"

int chargerParametres(Parametres *_params)
{
    FILE *pFichier;

    pFichier = fopen("setup.ini", "r");

    if(pFichier)
    {
        int var;
        fclose(pFichier);
    }
    else
    {
        printf("Erreur lecture fichier param�tres");
        return 0;
    }

    return 1;
}
