// échange deux entier saisis et les affiche avant et après 

#include <stdio.h>
#include <stdlib.h>

int main()
{

    int a = 5;
    int b = 3;
    int r = 0;

    printf("a = %d et b = %d\n", a,b);

    r = a;
    a = b;
    b = r;

    printf("a = %d et b = %d", a,b);

    return (0);
}