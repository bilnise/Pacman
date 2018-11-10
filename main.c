#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "windows.h"
#include "time.h"

#include "Jeu.h"
#include "Parametres.h"
#include "Constantes.h"
#include "utils.h"

void afficherTitre();
void credits();
void regles();
void reglerBordure(int *_bordure);
void reglerVitesse(int *_vitesseInitiale);
void afficherScores(int _scores[NB_TAB]);
int chargerSauvegarde(int _scores[NB_TAB], int *_tableauCourant);
void menu(Parametres *_params, int _scores[NB_TAB], int *_tableauCourant);
int enregistrerSauvegarde(int _tableau,int _score[NB_TAB]);

int main()
{
    /// D�claration des variables
    Parametres params;
    int scores[NB_TAB];
    int tableauCourant;
    int i;

    system("mode con lines=18 cols=50");
    /// 1. Afficher cr�dits
    credits();
    Sleep(2000);

    /// 2. Initialiser param�tres par d�faut
    params.vitesseInitale = 1;
    params.bordure = 1;

    /// 3. Initialiser scores et tableau courant
    for(i=0; i<NB_TAB; i++)
    {
        scores[i] = 0;
    }

    tableauCourant = 1;

    /// 4. Charger sauvegarde
    if(!chargerSauvegarde(scores, &tableauCourant))
        printf("Impossible de charger la sauvegarde");
    else
        printf("Chargement de la sauvegarde reussi !");
    Sleep(1000);

    /// 5. Lancer menu
    menu(&params, scores, &tableauCourant);

    /// 6. Sauvegarder
    if(!enregistrerSauvegarde(tableauCourant, scores))
        printf("Impossible de sauvegarder");
    else
        printf("Sauvegarde reussi !");
    Sleep(1000);

    return 0;
}

void afficherTitre()
{
    printf("##################################################\n");
    printf("#     _____                                      #\n");
    printf("#    |  __ \\                                     #\n");
    printf("#    | |__) |_ _  ___ _ __ ___   __ _ _ __       #\n");
    printf("#    |  ___/ _` |/ __| '_ ` _ \\ / _` | '_ \\      #\n");
    printf("#    | |  | (_| | (__| | | | | | (_| | | | |     #\n");
    printf("#    |_|   \\__,_|\\___|_| |_| |_|\\__,_|_| |_|     #\n");
    printf("#                                                #\n");
    printf("##################################################\n");
}

void credits()
{
    printf("##################################################\n");
    printf("#     _____                                      #\n");
    printf("#    |  __ \\                                     #\n");
    printf("#    | |__) |_ _  ___ _ __ ___   __ _ _ __       #\n");
    printf("#    |  ___/ _` |/ __| '_ ` _ \\ / _` | '_ \\      #\n");
    printf("#    | |  | (_| | (__| | | | | | (_| | | | |     #\n");
    printf("#    |_|   \\__,_|\\___|_| |_| |_|\\__,_|_| |_|     #\n");
    printf("#                                                #\n");
    printf("#    Par : Kevin SPIERO, Adrien DECHARRIERE et   #\n");
    printf("#          Celia BENMERAD                        #\n");
    printf("#                                                #\n");
    printf("##################################################\n");
}

void regles()
{
    char touche;

    system("cls");
    afficherTitre();
    printf("                  Regles du jeu :\n");
    printf("Tableau 1 : \n");

    do
    {
        touche = getch();
    }
    while(touche != 'q');
}

void regler_bordure(int *_bordure)
{
    char touche;

    system("cls");
    afficherTitre();
    printf("           Activer/Desactiver bordure :\n");

    do
    {
        gotoligcol(11,0);
        if(*_bordure)
            printf("Bordure : OUI\n");
        else
            printf("Bordure : NON\n");

        touche = getch();

        if(touche == '\r')
            *_bordure = 1-*_bordure;

    }
    while(touche != 'q');
}

void regler_vitesse(int *_vitesseInitiale)
{
    char touche;

    system("cls");
    afficherTitre();
    printf("         Regler vitesse :\n");

    do
    {
        gotoligcol(11,0);
        printf("Vitesse initiale : %d\n", *_vitesseInitiale);

        touche = getch();
        if(touche == 'p')
            *_vitesseInitiale = 1+(*_vitesseInitiale)%3;

    }
    while(touche != 'q');
}

void afficherScores(int _scores[NB_TAB])
{
    int i;
    char touche;

    system("cls");
    afficherTitre();
    printf("                  Scores :\n");
    printf("\n");

    for(i=0; i<NB_TAB; i++)
    {
        printf("Tableau %d : %d\n", i+1, _scores[i]);
    }

    do
    {
        touche = getch();
    }
    while(touche != 'q');
}

int chargerSauvegarde(int scores[NB_TAB], int *tableauCourant)
{
    FILE* fichier;
    fichier = fopen("save.txt", "r");

    if(fichier)
    {
        int i;
        fscanf(fichier, "%d", tableauCourant);
        for(i=0; i<NB_TAB; i++)
        {
            fscanf(fichier, "%d", &scores[i]);
        }
        fclose(fichier);
    }
    else
    {
        return 0;
    }

    return 1;
}

void menu(Parametres *_params, int _scores[NB_TAB], int *_tableauCourant)
{
    char touche;
    int i;

    while(1)
    {
        system("cls");
        system("mode con lines=18 cols=50");
        ///3.1 Afficher les choix possibles
        afficherTitre();
        printf("                1. Regles du jeu\n");
        printf("                2. Regler vitesse initiale\n");
        printf("                3. Activer/Desactiver bordure\n");
        printf("                4. Nouvelle partie\n");
        printf("                5. Reprendre\n");
        printf("                6. Afficher les scores\n");
        printf("                7. Quitter\n");

        /// 3.2. Attente du choix de l'utilisateur
        touche = getch();

        /// Lancer la proc�dure correspondant au choix
        switch(touche)
        {
        case '&':
        case '1':
            regles();
            break;

        case -126: // �
        case '2':
            regler_vitesse(&_params->vitesseInitale);
            break;

        case '"':
        case '3':
            regler_bordure(&_params->bordure);
            break;

        case '\'':
        case '4':
            *_tableauCourant = 1;

            for(i=0; i<NB_TAB; i++)
            {
                _scores[i] = 0;
            }

            jeu(*_params, _scores,_tableauCourant);
            break;

        case '(':
        case '5':
            jeu(*_params,_scores,_tableauCourant);
            break;

        case '-':
        case '6':
            afficherScores(_scores);
            break;

        case -118: // �
        case '7':
            return;
        }
    }

}

int enregistrerSauvegarde(int _tableau,int _score[NB_TAB])
{
    int i;
    FILE* fichier;

    fichier = fopen("save.txt", "w");

    if(fichier)
    {
        fprintf(fichier, "%d\n", _tableau);

        for(i=0; i<NB_TAB; i++)
        {
            fprintf(fichier, "%d\n", _score[i]);
        }

        fclose(fichier);

        return 1;
    }
    else
    {
        return 0;
    }
}