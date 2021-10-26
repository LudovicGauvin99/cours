// affiche la valeur de décimal, caractère et héxadécimal de a à z

#include <stdlib.h>
#include <stdio.h>

int main(){
    for(char a='a'; a<='z'; a++){
        
        printf("la valeur de a represente %d en décimal %c en caractere et %x en hexadecimal \n",a,a,a);

    }
    return(0);
}