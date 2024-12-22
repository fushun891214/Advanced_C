#include "main.h"

int main(void){
    my_int input1, input2, result;
    char input_str[MAX + 1];

    printf("Please give a number less than 4: ");
    scanf("%s",input_str);
    trans_from_string(input1, input_str);

    printf("Please give another number less than 4: ");
    scanf("%s",input_str);
    trans_from_string(input2, input_str);

    int add_status = my_add(result, input1, input2);

    if(add_status){
        printf("Overflow!\n");
        return 0;
    }
    
    printf("The result is: ");
    my_number_print(result);

    return 0;
}