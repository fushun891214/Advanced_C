#include "ui.h"

// Function to get user input and perform add or delete operations on the list
void get_input(tNumStorHead *list){
    int input_status = 0;
    int input_value = 0;
    int input_position = 0;
    int input_before_or_after_position = 0;

    while (1) {  
        printf("1. Add a number or 2. Delete a number: ");  
        scanf("%d", &input_status);
        
        if (input_status == 1) {  // Add a number
            printf(" Add a number: "); 
            scanf("%d", &input_value); 
            if (list->counts != 0) {
                printf("  Specify a target location: ");
                scanf("%d", &input_position);
                printf("  1. Before or 2. After the location %d: ", input_position);
                scanf("%d", &input_before_or_after_position);
            }
            add_Node(list, input_value, input_position, input_before_or_after_position);
            print_list(list);  // Print the list after insertion
        }
        else if (input_status == 2) { // Delete a number
            printf(" Specify a target location: ");
            scanf("%d", &input_position); 
            remove_Node(list, input_position);
            print_list(list);  // Print the list after deletion
        }
        else { // Invalid choice
            printf(" No such choice !\n");
        }
    }
}

// Function to print the entire list from head to tail and tail to head
void print_list(tNumStorHead *list){
    tNumStorage *node_ptr;

    printf("\n");
    printf("counts: %d \n", list->counts);  // Print the total element count
    node_ptr = list->head;
    printf(" From head --> ");

    // Print the list from head to tail
    while (node_ptr != NULL){
        printf("%d ", node_ptr->number);
        node_ptr = node_ptr->next;
    }

    node_ptr = list->tail;
    printf("\n From tail --> ");

    // Print the list from tail to head
    while (node_ptr != NULL){
        printf("%d ", node_ptr->number);
        node_ptr = node_ptr->prev;
    }

    printf("\n\n");
}