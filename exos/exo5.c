// affiche le plus grand des trois entier

#include <stdio.h>
#include <stdlib.h>
 int main(){

     int a,b,c;

     a=8;
     b=4;
     c=3;

     if(a > b && a > b)
        printf("%d", a);
    else if(b > a && b > c)
        printf("%d", b);
    else
        printf("%d", c);

    return(0);
 }