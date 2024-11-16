#include "ui.h"
#include "list.h"

int main(void){
    tNumStorHead *list;
    list = (tNumStorHead *)malloc(sizeof(tNumStorHead));
    initial_list(list);  // Initialize the list
    get_input(list);  // Start getting user input
    free(list);  // Free the memory allocated for the list
}