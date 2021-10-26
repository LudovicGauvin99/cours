#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    char *tab = (char *)malloc(100);
    char *occurence;
    char *lettre = malloc(1 * sizeof(char));

    printf("rentrer une chaine de caractere : ");
    scanf("%s", tab);
    printf("\nentrer une lettre :");
    scanf("%s", lettre);

    occurence = strchr(tab, *lettre);
    printf("%s\n", occurence);

    free(tab);
    free(lettre);
    return (0);
}