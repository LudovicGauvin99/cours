#include <stdlib.h>
#include <stdio.h>

int max4(int, int, int, int);
int max2(int, int);

int main()
{
    int f = 0, a = 0, b = 0, c = 0, d = 0;

    printf("choisir le premier nombre : \n");
    scanf("%d", &a);
    printf("choisir le deuxieme nombre : \n");
    scanf("%d", &b);
    printf("choisir le troisieme nombre : \n");
    scanf("%d", &c);
    printf("choisir le quatrieme nombre : \n");
    scanf("%d", &d);

    f = max4(a, b, c, d);

    printf("le nombre le grand est %d", f);

    return (0);
}

int max4(int a, int b, int c, int d)
{
    int grand1 = 0, grand2 = 0, r = 0;

    grand1 = max2(a, b);
    grand2 = max2(c, d);

    return (max2(grand1, grand2));
}

int max2(int g1, int g2)
{
    int r = 0;

    if (g1 > g2)
    {
        r = g1;
        return (g1);
    }
    else
    {
        r = g2;
        return (g2);
    }
}