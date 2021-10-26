// dis si un entier est pair ou impair

#include <stdio.h>
#include <stdlib.h>

int main(){
    int a = 0;

    printf("saisir un entier : ");
    scanf("%d", &a);

    if(a%2 == 0)
        printf("c'est un chiffre pair");
    
    else 
        printf("chiffre impair");
    
    return(0);
}