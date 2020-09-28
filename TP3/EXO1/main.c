#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include "tableau.h"

int main()
{
    uint16_t tab_int[DIM_TAB] = {0};
    uint16_t tab_histo[VAL_MAX] = {0};

    init_alea_tab(tab_int, DIM_TAB, VAL_MAX);
    affiche_tab(tab_int, DIM_TAB);
    histo(tab_int, tab_histo, DIM_TAB, VAL_MAX);
    affiche_histo(tab_histo, VAL_MAX, 0);
    return 0;
}
