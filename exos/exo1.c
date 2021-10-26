// saisir deux entier et fais le produit et l'affiche

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a = 0;
    int b = 0;
    int r = 0;

    scanf("%d", &a);
    scanf("%d", &b);

    r = a * b;

    printf("produit : %d", r);

    return (0);
}