#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    char tab1[50], tab2[50], echange[50];
    int a = 0, i = 0;

    printf("saisissez la premiere chaine de caractere :");
    scanf("%s", tab1);
    printf("\nsaisissez la deuxieme chaine de caractere :");
    scanf("%s", tab2);

    for (i = 0; i <= strlen(tab1); i++)
    {
        echange[i] = tab1[i];
    }
    echange[i + 1] = '\0';

    for (i = 0; i <= strlen(tab2); i++)
    {
        tab1[i] = tab2[i];
    }
    tab1[i + 1] = '\0';

    for (i = 0; i <= strlen(echange); i++)
    {
        tab2[i] = echange[i];
    }

    printf("%s", tab1);
    printf("\n%s", tab2);
}