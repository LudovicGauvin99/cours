#include <stdio.h>
#include <stdlib.h>

void exercice1()
{
    char a = '0';
    char b = '1';
    char c = '2';

    while (a <= '9')
    {
        while (b <= '9')
        {
            while (c <= '9')
            {
                if (a == '7' && b == '8' && c == '9')
                {
                    putchar(a);
                    putchar(b);
                    putchar(c);
                    putchar(',');
                    putchar('\n');

                    break;
                }
                putchar(a);
                putchar(b);
                putchar(c);
                putchar(',');
                putchar(' ');
                c++;
            }
            b++;
            c = b + 1;
        }
        a++;
        b = a;
    }
}

void exercice2()
{
    int nombre1 = 0, nombre2 = 1;

    while (nombre1 <= 99)
    {
        while (nombre2 <= 99)
        {
            if (nombre1 == 98 && nombre2 == 99)
            {
                printf("%02d %02d.", nombre1, nombre2);
                break;
            }
            else
            {
                printf("%02d %02d,", nombre1, nombre2);
                nombre2++;
            }
        }

        nombre1++;
        nombre2 = nombre1 + 1;
    }
}

void exercice3()
{

    int choix = 0;
    char tab[10] = "";

    while (choix <= 0 || choix > 10)
    {
        printf("choisir un nombre entre 1 et 10 :\n");
        scanf("%d", &choix);
    }

    test(tab, 0, choix);
}

void test(char *s, int i, int n)
{
    if (i == n)
    {
        puts(s);
    }
    else
    {
        for (int digit = i == 0 ? '0' : s[i - 1] + 1; digit <= '9'; digit++)
        // si digit = 0 alors digit = '0' sinon digit = s[i-1] + 1
        {
            s[i] = digit;
            test(s, i + 1, n);
        }
    }
}

void exercice4(char *chaine)
{
    for (int i = 0; chaine[i] != '\0'; i++)
    {
        putchar(chaine[i]);
        // putchar('\n');
    }
}

int exercice5(char *chaine){
    int i;

    for(i = 0; chaine[i] != '\0'; i++);

    i--;

    return(i);
}

void exercice6(int *a, int *b)
{
    int c;

    c = *a;
    *a = *b;
    *b = c;

    printf("a = %d et b = %d", *a, *b);
}

