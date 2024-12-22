#ifndef SPACE_H
#define SPACE_H

#define MAX 4
typedef char my_int[MAX];

int my_add (my_int result, my_int input1, my_int input2);
void my_number_print(my_int input);
void trans_from_string(my_int input, char *str);

#endif