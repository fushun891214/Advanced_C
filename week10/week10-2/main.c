#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int increasing(char a,char b){
    return a > b;
}

int descending(char a,char b){
    return a < b;
}

void swap(char *a,char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(char *str,int (*compare)(char,char)){
    int len = strlen(str);
    int i,j,flag;
    for(i = 0; i < len-1;i++){
        flag = 0;
        for(j = 0;j < len-i-1;j++){
            if(compare(*(str+j),*(str+j+1))){
                swap((str+j),(str+j+1));
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}

char *readString(){
    char *str = NULL;
    char ch;
    int size = 0;

    while((ch = getchar()) != '\n'){
        char *temp = (char *)realloc(str,(size+2)*sizeof(char));
        if(temp == NULL){
            free(str);
            return NULL;
        }
        str = temp;
        *(str+size) = ch;
        size++;
    }

    if(str != NULL){
        *(str+size) = '\0';
    }

    return str;
}

int main(void){
    int input_mode;
    char *input_string;
    int (*compare)(char,char);

    while(1){
        printf("Please enter (0) increasing or (1) decreasing sort: ");
        scanf("%d",&input_mode);
        getchar();
        printf("\n");

        if(input_mode != 0 && input_mode !=1){
            break;
        }

        printf(" Please enter a string: ");
        input_string = readString();

        if(input_string == NULL){
            printf("Memory allocation failed!\n");
            return 1;
        }

        if(input_mode == 0){
            compare = increasing;
        }
        else{
            compare = descending;
        }

        bubble_sort(input_string,compare);

        printf("  Result: %s\n",input_string);

        free(input_string);
        input_string = NULL;
    }
    return 0;    
}