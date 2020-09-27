#include <math.h>
#include <stdio.h>


float norme(float a, float b)
{
    return sqrt(a*a + b*b);
}

int main()
{
    float x, y;
    printf("Entrer deux coordonnées (x et y): ");
    scanf("%f %f", &x, &y);

    printf("La norme de ce vecteur est: %f", norme(x,y));
    return 0;
}
