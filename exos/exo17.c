#include <stdio.h>
#include <stdlib.h>

int main()
{

    int *tab = NULL; 
    int a = 0, n = 0;

    printf("choisissez le nombre de valeur que vous voulez entree : ");
    scanf("%d", &a);

    tab = malloc(a * sizeof(int)); // alter : malloc(100 sizeof(char));
    if (tab == NULL)
    {
        exit(0);
    }
    
    for (int i = 0; i < a; i++)
    {
        printf("\nrentre un nombre : ");
        scanf("%d", &n);
        n = n + *tab ;
        tab = tab + 1;
    }

    printf("%d", n);

    free(tab);
    return (0);
}