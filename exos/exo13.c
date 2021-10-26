#include <stdlib.h>
#include <stdio.h>

int main()
{

    char tab[15];
    int j = 0, c = 0, a = 0, i = 0;

    printf("saisir un mot : ");
    scanf("%s", tab);

    for (i = 0; tab[i] != '\0'; i++)
    {
        j++;
    }
    a = j;
    j--;
    for (i = 0; i <= j; i++)
    {
        if (tab[i] == tab[j])
        {
            c++;
            j--;
        }
        else
        {
            printf("ce n'est pas un palindrome");
            return (0);
        }
    }

    if (c == i)
        printf("c'est un palindrome");

    return (0);
}