#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int Inversions(char *str){
    int counter = 0;
    for(int i=0;i<strlen(str)-1;i++){
        for(int j=(i+1);j<strlen(str);j++){
            if((str[i]>str[j]))
                counter++;
        }
    }
    return counter;
}

int main(void){
    int size = 100;
    char *str = (char *)malloc(size * sizeof(char));
    scanf("%s",str);
    printf("%d\n",Inversions(str));
    return 0;
}