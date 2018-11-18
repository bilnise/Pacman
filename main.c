#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "windows.h"
#include "time.h"

#include "Constantes.h"
#include "Entite.h"
#include "Tableaux.h"
#include "Parametres.h"
#include "utils.h"

void afficherTitre();
void credits();
void regles();
void reglerBordure(int *_bordure);
void reglerVitesse(int *_vitesseInitiale);
void afficherScores(int _scores[NB_TAB], int _partie);
int chargerSauvegarde(int _scores[NB_TAB], int *_tableauCourant, int *_partie);
void menu(Parametres *_params, int _scores[NB_TAB], int *_tableauCourant, int *_partie);
int enregistrerSauvegarde(int _tableau,int _score[NB_TAB], int _partie);
void jeu(Parametres *_params, int _scores[NB_TAB], int *_tableau, int *_partie);

void afficherTitre()
{
    printf("\xDB\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDB\n");
    printf("\xDB     _____                                      \xDB\n");
    printf("\xDB    |  __ \\                                     \xDB\n");
    printf("\xDB    | |__) |_ _  ___ _ __ ___   __ _ _ __       \xDB\n");
    printf("\xDB    |  ___/ _` |/ __| '_ ` _ \\ / _` | '_ \\      \xDB\n");
    printf("\xDB    | |  | (_| | (__| | | | | | (_| | | | |     \xDB\n");
    printf("\xDB    |_|   \\__,_|\\___|_| |_| |_|\\__,_|_| |_|     \xDB\n");
    printf("\xDB                                                \xDB\n");
    printf("\xDB\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDB\n");
}

void credits()
{
    printf("\xDB\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDF\xDB\n");
    printf("\xDB     _____                                      \xDB\n");
    printf("\xDB    |  __ \\                                     \xDB\n");
    printf("\xDB    | |__) |_ _  ___ _ __ ___   __ _ _ __       \xDB\n");
    printf("\xDB    |  ___/ _` |/ __| '_ ` _ \\ / _` | '_ \\      \xDB\n");
    printf("\xDB    | |  | (_| | (__| | | | | | (_| | | | |     \xDB\n");
    printf("\xDB    |_|   \\__,_|\\___|_| |_| |_|\\__,_|_| |_|     \xDB\n");
    printf("\xDB                                                \xDB\n");
    printf("\xDB    Par : Kevin SPIERO, Adrien DECHARRIERE et   \xDB\n");
    printf("\xDB          Celia BENMERAD                        \xDB\n");
    printf("\xDB                                                \xDB\n");
    printf("\xDB\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDC\xDB\n");
}

void regles()
{
    char touche;

    system("cls");
    system("mode con lines=30 cols=50");
    afficherTitre();
    printf("                  Regles du jeu :\n\n");
    printf("\tLe PACMAN est un jeu classique dans\n\tlequel un personnage se deplace\n\tdans un espace plus ou moins\n\tcomplexe pour manger des diamants.\n\tIl peut aller dans 4 directions a\n\tl'aide du clavier et doit eviter de\n\tse faire attraper par des fantomes\n\tqui sillonnent l'espace de jeu.\n\n");
    printf("\tLe but du jeu de base est de\n\treussir a manger les diamants presents\n\tsur 4 tableaux de difficulte\n\tcroissante. Les obstacles qui\n\tbarrent la route du PACMAN sont\n\tnombreux et certains sont meme mortels.\n\tHeureusement le PACMAN dispose de 5\n\tvies pour mener a bien sa mission.\n\n");
    printf("Appuyer sur q pour revenir au menu");

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
    printf("           Activer/Desactiver bordure :\n\n\n\n\n\n\n");
    printf("Appuyer sur q pour revenir au menu\n");
    printf("Appuyer sur Entrer pour modifier la valeur");



    do
    {
        gotoligcol(12,0);
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
    printf("\t\tRegler vitesse :\n\n\n\n\n\n\n");
    printf("Appuyer sur q pour revenir au menu\n");
    printf("Appuyer sur Entrer pour modifier la valeur");

    do
    {
        gotoligcol(12,0);
        printf("Vitesse initiale : %d\n", *_vitesseInitiale);

        touche = getch();
        if(touche == '\r')
            *_vitesseInitiale = 1+(*_vitesseInitiale)%3;

    }
    while(touche != 'q');
}

void afficherScores(int _scores[NB_TAB], int _partie)
{
    int i;
    char touche;

    system("cls");
    afficherTitre();
    printf("Partie : %d            Scores :\n\n", _partie);

    for(i=0; i<NB_TAB; i++)
    {
        printf("\t\t  Tableau %d : %d\n", i+1, _scores[i]);
    }

    printf("\nAppuyer sur q pour revenir au menu\n");

    do
    {
        touche = getch();
    }
    while(touche != 'q');
}

int chargerSauvegarde(int _scores[NB_TAB], int *_tableauCourant, int *_partie)
{
    FILE* fichier;
    fichier = fopen("save.txt", "r");

    if(fichier)
    {
        int i;
        fscanf(fichier, "%d %d", _tableauCourant, _partie);
        for(i=0; i<NB_TAB; i++)
        {
            fscanf(fichier, "%d", &_scores[i]);
        }
        fclose(fichier);
    }
    else
    {
        return 0;
    }

    return 1;
}

void menu(Parametres *_params, int _scores[NB_TAB], int *_tableauCourant, int *_partie)
{
    char touche;
    int i;
    int save;

    save=1;

    while(1)
    {
        color(15,0);
        system("cls");
        system("mode con lines=18 cols=50");
        ///3.1 Afficher les choix possibles
        afficherTitre();
        printf("\n");
        printf("                1. Regles du jeu\n");
        printf("                2. Regler vitesse initiale\n");
        printf("                3. Activer/Desactiver bordure\n");
        printf("                4. Nouvelle partie\n");
        printf("                5. Reprendre\n");
        printf("                6. Afficher les scores\n");
        printf("                7. Quitter\n");

        /// Enregistrer dès que l'on revient au menu après avoir lancer une partie
        if(!save)
        {
            if(!enregistrerSauvegarde(*_tableauCourant, _scores, *_partie))
                printf("Impossible de sauvegarder");
            else
            {
                printf("Sauvegarde reussi !");
                save = 1; // Sauvegarde réalisée
            }
        }

        /// 3.2. Attente du choix de l'utilisateur
        touche = getch();

        /// Lancer la procédure correspondant au choix
        switch(touche)
        {
        case '&':
        case '1':
            regles();
            break;

        case -126: // é
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
            *_partie = 1;

            for(i=0; i<NB_TAB; i++)
            {
                _scores[i] = 0;
            }

            jeu(_params, _scores,_tableauCourant, _partie);
            save = 0;
            break;

        case '(':
        case '5':
            jeu(_params,_scores,_tableauCourant, _partie);
            save = 0;
            break;

        case '-':
        case '6':
            afficherScores(_scores, *_partie);
            break;

        case -118: // è
        case '7':
            return;
        }

    }

}

int enregistrerSauvegarde(int _tableau,int _score[NB_TAB],int _partie)
{
    int i;
    FILE* fichier;

    fichier = fopen("save.txt", "w");

    if(fichier)
    {
        fprintf(fichier, "%d %d\n", _tableau, _partie);

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

void jeu(Parametres *_params, int _scores[NB_TAB], int *_tableau, int *_partie)
{
    switch(*_tableau)
    {
    case 1:
        if(tableau1(_params,_scores,*_partie*NB_INITIAL_DIAMANTS))
            *_tableau = 2;
        else
            _scores[0] = 0;
        break;

    case 2:
        if(tableau2(_params,_scores,*_partie*NB_INITIAL_DIAMANTS))
            *_tableau = 3;
        else
            _scores[1] = 0;
        break;

    case 3:
        if(tableau3(_params,_scores,*_partie*NB_INITIAL_DIAMANTS))
            *_tableau = 4;
        else
            _scores[2] = 0;
        break;

    case 4:
        if(tableau4(_params,_scores,*_partie*NB_INITIAL_DIAMANTS))
        {
            *_tableau = 1;
            (*_partie)++;
        }
        else
            _scores[3] = 0;
        break;
    }
}

int main()
{
    /// Déclaration des variables
    Parametres params;
    int scores[NB_TAB];
    int tableauCourant;
    int partie;
    int i;

    srand(time(NULL));

    system("mode con lines=18 cols=50");
    color(15,0);
    /// 1. Afficher crédits
    credits();
    Sleep(2000);

    /// 2. Initialiser paramètres par défaut
    params.vitesseInitale = 2;
    params.bordure = 1;

    /// 3. Initialiser scores et tableau courant
    for(i=0; i<NB_TAB; i++)
    {
        scores[i] = 0;
    }

    tableauCourant = 1;

    /// 4.Initialiser numéro partie
    partie = 1;

    /// 5. Charger sauvegarde
    if(!chargerSauvegarde(scores, &tableauCourant, &partie))
        printf("Impossible de charger la sauvegarde");
    else
        printf("Chargement de la sauvegarde reussi !");

    Sleep(1000);

    /// 6. Lancer menu
    menu(&params, scores, &tableauCourant, &partie);

    return 0;
}
