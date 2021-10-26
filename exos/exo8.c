//

#include <stdlib.h>
#include <stdio.h>

int main(){
    
    int a,b,r,i;

    a = 120;
    b = 4;
    r = a - b;
    i = 0;

    printf("a =%d\n b=%d\n reste=%d\n quotient=%d \n",a,b,r,i); 

    while(b*i <= a && r >= b){
        i++;
        r = a-(b*i);  
        printf("a =%d\n b=%d\n reste=%d\n quotient=%d \n",a,b,r,i);     
    }


    return(0);
}