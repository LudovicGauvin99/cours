// ecris le plus petit et le plus grand des nombres choisis, la saisi s'arrete a 0 

#include <stdlib.h>
#include <stdio.h>

int main()
{

    int a = 0;
    
    printf("choisie un nombre (0 pour arreter) :");
    scanf("%d", &a);

    int b = a;
    int c = a;

    while (a != 0)
    {

        printf("choisie un nombre (0 pour arreter) :");
        scanf("%d", &a);

        if (a < c && a != 0)
            c = a;
        else if (a > b && a != 0)
            b = a;

    };
    if(a == 0)
        return(0);
    else 
        printf("nombre le plus petit : %d \n nombre le plus grand : %d", c, b);

    return (0);
}