#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main(int argc, char *argv[])
{
    int a = 1;
    int b = 2;
    int c = 3;
    int *p1,*p2;

    p1 = &a;
    p2 = &c;
    *p1 = (*p2)++;
    printf("%d\n", *p1);
    p1 = p2;
    p2 = &b;
    *p1 -= *p2;
    printf("p1 =%d , p2 = %d\n", *p1, *p2);
    ++*p2;
    printf("p2 = %d\n", *p2);
    *p1*=*p2;
    printf("p1 =%d , p2 = %d\n", *p1, *p2);
    a = ++*p2**p1;
    printf("a = %d, p1 =%d , p2 = %d\n", a, *p1, *p2);
    p1 = &a;
    *p2 = *p1 /= *p2;
    printf("p1 =%d , p2 = %d\n", *p1, *p2);


 
    return 0;
}