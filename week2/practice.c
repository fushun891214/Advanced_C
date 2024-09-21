#include<stdio.h>

int main(void){
    int a = 4;
    int *p;

    p = &a;
    printf("%p %p %p %p\n",&a,&p,&(*p),p);

    return 0;
}