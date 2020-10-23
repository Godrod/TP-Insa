/*!
 * \file tache.h
 * \brief Module de definition des taches
 *
 * \author  ...
 * \date ...
 *
 */

#ifndef TACHE_H_INC
#define TACHE_H_INC

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LGMAX 64 /* longueur maximum du titre*/
#define NMAXPRED 16  /* nombre maximum de predecesseur*/
#define MAXTACHES 64 /* Nombre maximales de taches dans le tableau */

/*!
 * \struct Tache
 * Type representant une tache
 */
typedef struct{
  int no; /*le nom de la tache*/
  int duree; /* la duree de la tache*/
  int nbPred;     /* le nombre effectif de predecesseur de la tache*/
  int pred[NMAXPRED];  /*le tableau des predecesseurs*/
  char titre[LGMAX];   /*le titre de la tache*/
}Tache;


typedef struct struct_element{
    Tache t;
    struct struct_element *suivant;
}Element;

typedef Element* Liste;


/****** PROTOTYPES ******/
void saisieTache(Tache* t);
void afficheTache(Tache* t);
Liste lireTachesFichier(char* nom_fichier, int* nbtaches, int (*trie)(Tache, Tache));
void afficheTabTaches(Tache* tab_t, int nb_taches);
int sommeTotalDuree(Tache* tab, int nb_taches);
int ecrireTachesFichier(char* nom_fichier, Tache* tab, int nb_taches);
void ajoutdeb(Liste* l, Tache t);
void freeListe(Liste l);
int nbelement(Liste l);
void afficheListe(Liste l);
void ajouttrield(Liste* l, Tache t);
void ajouttrie(Liste* l, Tache t, int(*ptrfonc)(Tache, Tache));
int inferieur(Tache t1, Tache t2);
int superieur(Tache t1, Tache t2);
#endif
