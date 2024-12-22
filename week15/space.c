#include "space.h"
#include <stdio.h>
#include <string.h>

int my_add (my_int result, my_int input1, my_int input2){
    char carry = 0;
    for(int i = 0; i < MAX; i++){
        char input1_digit = input1[MAX-i-1] - '0';
        char input2_digit = input2[MAX-i-1] - '0';
        int sum = input1_digit + input2_digit + carry;

        if(sum > 9){
            result[MAX-i-1] = (sum % 10) + '0';
            carry = 1;
            if(i == 0){
                return 1;
            }
        }
        else{
            result[MAX-i-1] = sum + '0';
            carry = 0;
        }
    }
    return 0;
}

void my_number_print(my_int input){
    int start = 0;

    while(input[start] == '0' && start < MAX){
        start++;
    }

    if(start == MAX){
        printf("0");
        return;
    }

    for(int i=start ;i < MAX ; i++){
        printf("%c", input[i]);
    }
}

void trans_from_string(my_int input, char *str){
    for(int i = 0; i < MAX ; i++){
        input[i] = '0';
    }
    int len = strlen(str);
    for(int i = 0; i < len ; i++){
        input[MAX - len + i] = str[i];
    }
}