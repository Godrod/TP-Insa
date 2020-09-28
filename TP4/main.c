#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE* fichier;

    if ((fichier=fopen("taches.txt", "r")) == NULL)
    {
        perror("Le fichier n'as pas pu etre ouvert");
        return EXIT_FAILURE;
    }
    
    return 0;
}
