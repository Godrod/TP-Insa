#include <stdio.h>
#include "tache.h"

int main()
{
    int nb_fichier, nb;
    Liste liste_croissante = NULL, liste_decroissante = NULL;

    liste_croissante = lireTachesFichier("tachesDyn.txt", &nb_fichier, &inferieur);
    liste_decroissante = lireTachesFichier("tachesDyn.txt", &nb_fichier, &superieur);

    afficheListe(liste_croissante);
    afficheListe(liste_decroissante);

    freeListe(liste_croissante);
    freeListe(liste_decroissante);
    return 0;
}
