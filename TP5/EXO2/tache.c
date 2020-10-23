

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
    printf("\n\n");
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

Liste lireTachesFichier(char* nom_fichier, int* nbtaches, int (*trie)(Tache, Tache))
{
    FILE* f;
    char ligne[256] = {'\0'};
    int i = 0;
    int j, taille;
    char* mot = NULL;
    Liste l = NULL;

    if((f = fopen(nom_fichier, "r")) == NULL)
    {
        perror("Le fichier n'as pas pu etre ouvert");
        exit(EXIT_FAILURE);
    }

    *nbtaches = atoi(fgets(ligne, 256, f));

    while (fgets(ligne, 256, f) && i < *nbtaches)
    {
        char titre[256];
        Tache tache;
        tache.no = atoi(strtok(ligne, " "));
        tache.duree = atoi(strtok(NULL, " "));
        tache.nbPred = atoi(strtok(NULL, " "));

        memset(titre, 0, sizeof(titre));/* Initialise à 0 tout les octets de titre*/

        for (j = 0; j < tache.nbPred; j++)
        {
            tache.pred[j] = atoi(strtok(NULL, " "));
        }
        while ((mot = strtok(NULL, " ")) != NULL)
        {
            strcat(titre, mot);
            strcat(titre, " ");
        }

        taille = strlen(titre);
        titre[taille-2] = '\0';/* Supprime le retour a la ligne*/
        strcpy(tache.titre, titre);

        ajouttrie(&l, tache, trie);
        i++;
    }

    fclose(f);
    return l;
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
    fclose(f);
    return 1;
}

void ajoutdeb(Liste* l, Tache t)
{
    Element* e = malloc(sizeof(Element));
    if(e == NULL)
    {
        printf("Problème d'allocation mémoire");
        exit(0);
    }
    e->t = t;
    e->suivant = *l;
    *l = e;
}

void ajouttrield(Liste* l, Tache t)
{
    /*Si la liste est vide*/
    if (*l == NULL || t.no < (*l)->t.no)
        ajoutdeb(l, t);
    else
    {
        Liste preced = NULL;
        Liste debut = *l;
        char suivant_nul = 0;
        Element * e = malloc(sizeof(Element));

        /* On parcours la liste chainée jusqu'a arriver à l'élement pour lequel (*l)->t.no < t.no devient faux, si il existe.
         * Si on arrive en fin de liste et que l'on toujours pas rempli la condition de sortie de la boucle, alors l'élément doit
         * être rajouté juste après l'actuel dernier élement */
        while ((*l)->t.no < t.no)
        {
            /*Si l'élement suivant est nul, on n'avance plus dans la liste et on rajoute l'élément en fin de liste*/
            if((*l)->suivant == NULL)
            {
                suivant_nul = 1;
                break;
            }
            else
            {
                preced = *l;
                *l = (*l)->suivant;
            }

        }
        e->t = t;
        /*Ajout de l'élément en fin de liste*/
        if(suivant_nul == 1)
        {
            e->suivant = NULL;
            (*l)->suivant = e;
        }
        /*Ajout de l'élément entre preced et l'actuel (*l)->suivant*/
        else
        {
            preced->suivant = e;
            e->suivant = (*l)->suivant;
        }

        *l = debut; /*A la fin de la fonction, on revient au début de la liste chainée*/
    }
}

void ajouttrie(Liste* l, Tache t, int (*ptrfonc)(Tache, Tache))
{
    /*Si la liste est vide ou que la condition de trie est vrai dès le premier élement*/
    if (*l == NULL || (*ptrfonc)(t,(*l)->t))
        ajoutdeb(l, t);
    else
    {
        Liste preced = NULL;
        Liste debut = *l;
        char suivant_nul = 0;
        Element * e = malloc(sizeof(Element));

        /* On parcours la liste chainée jusqu'a arriver à l'élement pour lequel la condition de trie devient vrai, si il existe.
         * Si on arrive en fin de liste et que l'on toujours pas remplie la condition de sortie de la boucle, alors l'élément doit
         * être rajouté juste après l'actuel dernier élement */
        while (!(*ptrfonc)(t,(*l)->t))
        {
            /*Si l'élement suivant est nul, on n'avance plus dans la liste et on rajoute l'élément en fin de liste*/
            if((*l)->suivant == NULL)
            {
                suivant_nul = 1;
                break;
            }
            else
            {
                preced = *l;
                *l = (*l)->suivant;
            }

        }
        e->t = t;
        /*Ajout de l'élément en fin de liste*/
        if(suivant_nul == 1)
        {
            e->suivant = NULL;
            (*l)->suivant = e;
        }
            /*Ajout de l'élément entre preced et l'actuel (*l)->suivant*/
        else
        {
            preced->suivant = e;
            e->suivant = (*l)->suivant;
        }

        *l = debut; /*A la fin de la fonction, on revient au début de la liste chainée*/
    }
}

int inferieur(Tache t1, Tache t2)
{
    return (t1.no < t2.no) ? 1 : 0;
}

int superieur(Tache t1, Tache t2)
{
    return (t1.no > t2.no) ? 1 : 0;
}

void freeListe(Liste l)
{
    Liste tmp;
    while(l != NULL)
    {
        tmp = l;
        l = l->suivant;
        free(tmp);
    }
}
int nbelement(Liste l)
{
    Liste p_debut = l;
    int nb = 0;
    while (l->suivant != NULL)
    {
        l = l->suivant;
        nb++;
    }

    return nb + 1; //Sinon le dernier element de la liste n'est pas compté
}

void afficheListe(Liste l)
{
    Element *e = l;
    while (e != NULL)
    {
        afficheTache(&e->t);
        e = e->suivant;
    }
}


