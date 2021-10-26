#include <stdlib.h>
#include <stdio.h>

int main()
{
    int a = 0, b = 0, c = 0;

    printf("choisissez le premier nombre : \n");
    scanf("%d", &a);
    printf("choisissez le deuxieme nombre : \n");
    scanf("%d", &b);

    while (c == 0)
    {
        if (a < 0 || b < 0)
        {
            printf("nombre negatif non autorise recommencer\n");
            printf("choisissez le premier nombre : \n");
            scanf("%d", &a);
            printf("choisissez le deuxieme nombre : \n");
            scanf("%d", &b);
        }

        else
        {
            if (a < b)
            {
                int c = a;
                a = b;
                b = c;
            }

            while (b != 0)
            {
                if (b % 2 == 0)
                {
                    a = a + a;
                    b = b / 2;
                }
                else if (b % 2 != 0)
                {
                    b--;
                    c = c + a;
                }

                printf("%d + %d + %d\n", a, b, c);
            }
        }
    }
    printf("%d", c);

    return (0);
}