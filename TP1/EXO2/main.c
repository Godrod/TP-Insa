#include <stdio.h>

double suite(double x, int n)
{
    double racine = x/2;
    int i;
    for(i =1; i< n; i++)
    {
        racine = (racine + x/racine)/2;
    }
    return racine;
}

double racine(double x, double precision)
{
    double racine = x/2, racine_precedente = 0;
    while ((racine - racine_precedente) > precision || -(racine - racine_precedente) > precision)
    {
        racine_precedente = racine;
        racine = (racine + x/racine)/2;
    }
    return racine;
}

int main() {

    /* La fonction suite converge assez rapidement vers la racine carré
     * Exemple: pour racine de 5, au bout de 6 itération, la fonction converge déjà a 10-6 près vers la racine carré de 5
     * */

    double x = 5, precision = 0.01;

    printf("Valeur de la fonction suite avec x = %lf et n = %d: %lf\n", 5.0, 6, suite(5.0, 6));
    printf("Valeur de la fonction suite avec x = %lf et n = %d: %lf\n", 5.0, 10, suite(5.0, 10));

    printf("Racine carre de x: %lf avec une precision de %lf: %lf\n", x, precision, racine(x, precision));
    return 0;
}
