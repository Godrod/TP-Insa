#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int myfact(int n)
{
    int i, fact;
    fact = 1;
    for(i = 1; i <= n; i++)
    {
        fact*=i;
    }
    return fact;
}

int rang()
{
    int r =0;
    while (myfact(r) <= INT_MAX/(r+1))
    {
        r++;
    }
    return r;
}

/* Dépassement memoire car la valeur retounée peut etre plus grande que 2^31 -1*/
void display_fact()
{
    int i;

    for(i = 0; i<= 20; i++)
    {
        printf("Factorielle de %d: %d \n", i, myfact(i));
    }
}

int main() {
    display_fact();

    printf("Rang max: %d", rang());
    return 0;
}
