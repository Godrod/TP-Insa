//
// Created by cofleury on 28/09/2020.
//

#ifndef EXO1_TABLEAU_H
#define EXO1_TABLEAU_H

#define DIM_TAB 5
#define VAL_MAX 20

void init_alea_tab(uint16_t *tab, uint8_t dim, uint16_t max);
void affiche_tab(uint16_t* tab, uint8_t dim);
void histo(uint16_t *tab, uint16_t *tab_histo, uint8_t dim, uint16_t val_max);
void affiche_histo(uint16_t* histo, uint16_t max, uint8_t print_null);

#endif //EXO1_TABLEAU_H
