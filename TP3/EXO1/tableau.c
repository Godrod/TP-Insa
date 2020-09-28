//
// Created by cofleury on 28/09/2020.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include "tableau.h"
void init_alea_tab(uint16_t *tab, uint8_t dim, uint16_t max)
{
    uint8_t i;
    srand(time(NULL));
    if (dim > 0)
    {
        for(i = 0; i < dim; i++)
        {
            tab[i] = rand() % max;
        }
    }
}

void histo(uint16_t *tab, uint16_t *tab_histo, uint8_t dim, uint16_t val_max)
{
    uint16_t i, j;
    for (i = 0; i < val_max; i++)
    {
        for (j = 0; j < dim; j++)
        {
            if(tab[j] == i)
                tab_histo[i]++;
        }
    }
}

void affiche_tab(uint16_t* tab, uint8_t dim)
{
    uint8_t i;

    for (i = 0; i < dim; i++)
    {
        printf("Valeur en l'indice %d: %d \n", i, tab[i]);
    }
}
void affiche_histo(uint16_t* histo, uint16_t max, uint8_t print_null)
{
    uint16_t i, j;
    for(i = 0; i < max; i++)
    {

        if (histo[i] == 0 && print_null == 0)
            continue;
        else
        {
            printf("%d:", i);
            for (j = 0; j < histo[i]; j++)
            {
                printf(" -");
            }
            printf("\n");
        }

    }
}

