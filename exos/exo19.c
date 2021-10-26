#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctionExo.c"

void exercice1();
void exercice2();
void exercice3();
void test();
void exercice4();
int exercice5();
void exercice6();

int main()
{
    int nb1 = 0, nb2 = 0;

    printf("saisissez un premier nombre :");
    scanf("%d", &nb1);
    printf("\n saisissez le deuxieme nombre : ");
    scanf("%d", &nb2);

    exercice6(&nb1,&nb2);

    return (0);
}