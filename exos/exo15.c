#include <stdio.h>
#include <stdlib.h>

int somme(int, int);

int main()
{

    int f = 0, a = 0, b = 0;

    printf("choisir le premier chiffre : ");
    scanf("%d", &a);
    printf("\nchoisir le deuxieme chiffre : ");
    scanf("%d", &b);
    f = somme(a, b);
    printf("%d + %d = %d", a, b, f);
    return (0);
}

int somme(int a, int b)
{
    int r = 0;
    r = a + b;
    return (r);
}