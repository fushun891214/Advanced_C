#include<stdio.h>

#define N 4
int main(void){
    int array[N] = {0};
    int *p;
    int i;

    p = array;

    array[0] = 1;
    p[0] = 2;
    *(p+1) = 3;

    p++;

    *(p+2) = 4;
    *(p+3) = 5;

    p = array;

    for(i=0;i<N;i++){
        printf("array[%d]: %d, *(p+%d): %d\n",i,array[i],i,*(p+i));
    }
}