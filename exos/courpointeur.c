#include <stdio.h>
#include <stdlib.h>

void test(int *pa);
void test2(int a);

int main(){
    char ch[] = "aest";
    char *pch = ch;
    printf("pch = %s\n", pch);
    *pch = *pch + 1;
    printf("*pch = %c\n", *pch);
    pch = pch +1;
    printf("pch = %s\n", pch);
    *pch = *pch + 1;
    printf("*pch = %c\n", *pch);
    char *mot = pch;
    printf("mot = %s\n", mot);
    int a = 5;
    printf("a = %d\n", a);
    int *pa = &a;
    printf("*pa = %d &a = %d\n", *pa, &a);
    printf("pa = %d\n", pa);
    test(pa);
    test2(a);
    printf("*pa = %d a = %d\n", *pa, a);
    int b = *pa + 1;
    printf("b = %d a = %d\n", b, a);
    return(0);
}

void test(int *pa){
    *pa = *pa + 1;
}

void test2(int a){
    a = a + 1;
    printf("valeur de a dans la fonction test2 = %d\n", a);
}