#include <stdio.h>
#include <stdlib.h>
#include "tache.h"

int main()
{
    Tache* tab_taches;
    int nb;

    tab_taches = lireTachesFichier("tachesDyn.txt", &nb);
    afficheTabTaches(tab_taches, nb);
    printf("\n\nDuree total: %d", sommeTotalDuree(tab_taches, nb));

    ecrireTachesFichier("tachesB.txt", tab_taches, nb);
    free(tab_taches);
    return 0;
}
