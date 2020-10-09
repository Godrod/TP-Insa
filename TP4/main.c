#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "tache.h"

int main()
{
    Tache tab_taches[MAXTACHES];
    int nb;

    nb = lireTachesFichier("taches.txt", tab_taches);
    afficheTabTaches(tab_taches, nb);
    printf("\n\nDuree total: %d", sommeTotalDuree(tab_taches, nb));

    ecrireTachesFichier("tachesB.txt", tab_taches, nb);
    return 0;
}
