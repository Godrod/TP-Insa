//
// Created by cofleury on 28/09/2020.
//
#include <stdio.h>
#include "tache.h"

void saisieTache(Tache* t)
{
    printf("Saisissez un identifiant: ");
    scanf("%d \n", &t->no);
    printf("Saisissez la duree de la tache: ");
    scanf("%d \n", &t->duree);
    printf("Saisissez le nombre de taches précédentes : ");
    scanf("%d \n", &t->nbPred);
    printf("Saisissez le nom de la tache: ");
    scanf("%s \n", t->titre);
}

void afficheTache(Tache* t)
{
    printf("Nom de la tache: %s", t->titre);
    printf("Id: %d\n", t->no);
    printf("Duree: %d\n", t->duree);
    printf("Nombre de taches precedentes: %d\n", t->nbPred);
}