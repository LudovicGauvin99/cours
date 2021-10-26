#include <stdio.h>
#include <stdlib.h>

int main(){

    int a=0,b=0,x=0;

    printf("tapez le premier chiffre :\n");
    scanf("%d", &a);
    printf("tapez le deuxieme chiffre :\n");
    scanf("%d", &b);

    if(a < b){
        int c = a;
        a = b ;
        b = c;
    }

    while( a >= b){

        a = a - b;
        x++;
    }
    printf("le quotient est : %d et le reste est : %d", a, x);

    return(0);
}