#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

    char tab1[50], tab2[50], echange[50];
    
    printf("saisissez la premiere chaine de caractere :");
    scanf("%s", tab1);
    printf("\nsaisissez la deuxieme chaine de caractere :");
    scanf("%s", tab2);

    strcpy(echange, tab2);
    strcpy( tab2 , tab1);
    strcpy( tab1, echange);

    printf("%s", tab1);
    printf("\n%s", tab2);
}