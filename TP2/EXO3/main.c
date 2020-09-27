#include <stdio.h>
#include <math.h>

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

double puissance(double x, int n)
{
    double p = x;
    int i;
    if(n >0)
    {
        for(i = 1; i < n; i++)
        {
            p*=x;
        }
        return p;
    } else if (n == 0)
    {
        return 1;
    } else
    {
        return 0;
    }
}

double terme(double x, int n)
{
    return puissance(x, n)/myfact(n);
}

double suiv(double x, int n)
{
    if(n == 0)
    {
        return 1;
    } else if(n == 1)
    {
        return x;
    } else
    {
        return (puissance(x, n-2)/myfact(n-2)) * (puissance(x, 2)/(n*(n-1)));
    }
}

double sinus2(double x, int n)
{
    double val_sin = 0;
    int i;
    int neg =0;
    for (i = 0; (2*i +1) <= n; i++)
    {
        if(neg == 1)
        {
            val_sin += -1 * suiv(x, 2*i +1);
        } else
        {
            val_sin += suiv(x, 2*i +1);
        }
        neg = !neg;
    }
    return val_sin;

}

double sinus(double x, int n)
{
    double val_sin = 0;
    int i;
    int neg =0;
    for (i = 0; (2*i +1) <= n; i++)
    {
        if(neg == 1)
        {
            val_sin += -1 * terme(x, 2*i +1);
        } else
        {
            val_sin += terme(x, 2*i +1);
        }
        neg = !neg;
    }
    return val_sin;
}

int main() {

    int i;
    for(i = 1; i<=41; i=i+2)
    {
        printf("Sinus de PI/2 au rang %d: %f\n", i,sinus(M_PI/2, i));
    }

    for(i = 1; i<=41; i=i+2)
    {
        printf("Sinus2 de PI/2 au rang %d: %f\n", i, sinus2(M_PI/2, i));
    }
    printf("Sin de PI/2: %f\n", sin(M_PI/2));
    return 0;
}
