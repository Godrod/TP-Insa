#include <stdio.h>
#include "login.h"

#define MAX_NOM 255

int main()
{
    char nom[MAX_NOM] = "";
    char prenom[MAX_NOM] = "";
    char id[MAX_ID+1] = "";

    printf("Entrer votre nom et prenom: ");
    scanf("%s %s", nom, prenom);
    printf("\nVous avez saisi: %s %s\n\n", nom, prenom);

    identifiant2(nom, prenom, id);

    printf("Identifiant: %s", id);
    return 0;
}
