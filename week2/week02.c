#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main(int argc,char *argv[]){
    int *array;
    int array_size = argc;
    int matrix_sqrt = sqrt(array_size-2);

    for(int i=2;i<array_size;i++){
        if(i % matrix_sqrt == 1){
            printf("%4d\n",atoi(*(argv + i)));
        }
        else{
            printf("%4d",atoi(*(argv + i)));
        }
    }
    printf("%d\n",matrix_sqrt);
    array_size -= 2;
    printf("%d\n",array_size);

    return 0;
}