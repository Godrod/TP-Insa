//
// Created by cofleury on 28/09/2020.
//

#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <ctype.h>
#include "login.h"

void identifiant(char* nom, char* prenom, char* id)
{
    char lettre_prenom[2] = {0};
    char nom_id[MAX_ID-1] = {0};
    uint8_t i = 0;

    lettre_prenom[0] = prenom[0];
    while((i < MAX_ID-1) && i <= strlen(nom))
    {
        nom_id[i] = nom[i];
        i++;
    }
    strcat(id, lettre_prenom);
    strcat(id, nom_id);
}

void identifiant2(char* nom, char* prenom, char* id)
{
    char lettre_prenom[2] = {0};
    char nom_id[MAX_ID-1] = {0};
    uint8_t i = 0;

    lettre_prenom[0] = tolower(prenom[0]);
    while((i < MAX_ID-1) && i <= strlen(nom))
    {
        nom_id[i] = tolower(nom[i]);
        i++;
    }
    strcat(id, lettre_prenom);
    strcat(id, nom_id);
}