// determine tous les diviseurs d'un entier sauf le 1 

#include <stdio.h>
#include <stdlib.h>

int main(){

    int a=0,b=2;

    printf("choisie un nombre :");
    scanf("%d",&a);

    while(b <= a){

        if(a%b == 0)
            printf("divisible par : %d \n",b);

        b++;
    };

    return(0);
}