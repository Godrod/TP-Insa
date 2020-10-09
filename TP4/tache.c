//
// Created by cofleury on 28/09/2020.
//
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include "tache.h"

void saisieTache(Tache* t)
{
    uint8_t i = 0;
    printf("\nSaisissez le nom de la tache: ");
    scanf("%s", t->titre);
    printf("\nSaisissez son identifiant: ");
    scanf("%d", &t->no);
    printf("\nSaisissez la duree de la tache: ");
    scanf("%d", &t->duree);
    printf("\nSaisissez le nombre de taches precedentes : ");
    scanf("%d", &t->nbPred);
    for (i = 0; i < t->nbPred; i++)
    {
        printf("\nSaisissez l'identifiant de la tache %d: ", i+1);
        scanf("%d", &t->pred[i]);
    }
}

void afficheTache(Tache* t)
{
    int i;
    printf("Nom de la tache: %s\n", t->titre);
    printf("Id: %d\n", t->no);
    printf("Duree: %d\n", t->duree);
    printf("Nombre de taches precedentes: %d\n", t->nbPred);
    printf("Taches precedentes:");
    for (i = 0; i < t->nbPred; i++)
    {
        printf(" %d", t->pred[i]);
    }
    printf("\n");
}

void afficheTabTaches(Tache* tab_t, int nb_taches)
{
    int i, j;
    for (i = 0; i < nb_taches; i++)
    {
        printf("Tache %d\n", tab_t[i].no);
        printf("\t- Titre: %s\n", tab_t[i].titre);
        printf("\t- Duree: %d minutes\n", tab_t[i].duree);
        printf("\t- Nombre de taches precedentes: %d\n", tab_t[i].nbPred);
        printf("\t- Taches precedentes: ", tab_t[i].titre);
        for (j = 0; j < tab_t[i].nbPred; j++)
        {
            printf("%d ", tab_t[i].pred[j]);
        }
        printf("\n\n");
    }
}

int sommeTotalDuree(Tache* tab, int nb_taches)
{
    int total = 0;
    int i;
    for(i = 0; i < nb_taches; i++)
    {
        total += tab[i].duree;
    }
    return total;
}

int lireTachesFichier(char* nom_fichier, Tache tab[])
{
    FILE* f;
    char ligne[256] = {'\0'};
    int i = 0;
    int j, taille;
    char* mot = NULL;

    if((f = fopen(nom_fichier, "r")) == NULL)
    {
        perror("Le fichier n'as pas pu etre ouvert");
        exit(EXIT_FAILURE);
    }

    while (fgets(ligne, 256, f))
    {
        char titre[256];
        tab[i].no = atoi(strtok(ligne, " "));
        tab[i].duree = atoi(strtok(NULL, " "));
        tab[i].nbPred = atoi(strtok(NULL, " "));

        for (j = 0; j < tab[i].nbPred; j++)
        {
            tab[i].pred[j] = atoi(strtok(NULL, " "));
        }
        while ((mot = strtok(NULL, " ")) != NULL)
        {
            strcat(titre, mot);
            strcat(titre, " ");
        }

        taille = strlen(titre);
        titre[taille-2] = '\0';// Supprime le retour a la ligne
        strcpy(tab[i].titre, titre);
        memset(titre, 0, sizeof(titre));// Reinitialise à 0 tout les bits de titre
        i++;
    }

    fclose(f);
    return i;
}

int ecrireTachesFichier(char* nom_fichier, Tache* tab, int nb_taches)
{
    FILE* f;
    int i, j;

    if((f = fopen(nom_fichier, "w+")) == NULL)
    {
        printf("Le fichier %s n'as pas pu etre ouvert", nom_fichier);
        return 0;
    }

    for (i = 0; i < nb_taches; i++)
    {
        fprintf(f, "%d %d %d", tab[i].no, tab[i].duree, tab[i].nbPred);
        for (j = 0; j < tab[i].nbPred; j++)
        {
            fprintf(f, " %d", tab[i].pred[j]);
        }
        fprintf(f, " %s\n", tab[i].titre);
    }
}
