#include <stdio.h>
#include <stdlib.h>

int main()
{

    int tableau[50];
    int n = 0, b = 0,j = 0;

    printf("\ncombien de valeur voulez-vous (max 50) ? : ");
    scanf("%d", &b);

    while (b < 0 || b > 50)
    {
        printf("\ncombien de valeur voulez-vous (max 50) ? : ");
        scanf("%d", &b);
    }

    for (int i = 0; i < b; i++)
    {
        printf("\nrentrer un nombre : ");
        scanf("%d", &n);
        tableau[i] = n;
    }

    printf("tableau :");
    for (int i = 0; i < b; i++)
    {
        printf("|%d|", tableau[i]);
    }

    for (int i = 0; i < b; i++)
    {
        while (tableau[i] != 0 && i < b )
        {
            tableau[j] = tableau[i];
            j++;
            i++;
        }

    }
    printf("\ntableau :");

    for (int i = 0;  i < j ; i++)
    {
        printf("|%d|", tableau[i]);
    }
    return (0);
}