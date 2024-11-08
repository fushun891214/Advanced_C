#include<stdio.h>
#include<stdlib.h>

// Define a structure to store individual numbers in the list
typedef struct num_storage{
    int number;                        // The number to be stored
    struct num_storage *prev;      // Pointer to the previous node in the list
    struct num_storage *next;          // Pointer to the next node in the list
} tNumStorage;

// Define a structure to manage the list head, tail, and counts
typedef struct num_stor_head{
    int counts;               // Total number of elements in the list
    struct num_storage *head; // Pointer to the head (first element) of the list
    struct num_storage *tail; // Pointer to the tail (last element) of the list
} tNumStorHead;

// Function to initialize the list (set counts to 0, head and tail to NULL)
void initial_list(tNumStorHead *list){
    list->counts = 0;        // Initialize the element count to 0
    list->head = NULL;       // Set the head pointer to NULL (empty list)
    list->tail = NULL;       // Set the tail pointer to NULL (empty list)
}

// Function to print the entire list
void print_list(tNumStorHead *list){
    tNumStorage *node_ptr = list->head; // Start from the head of the list
    printf(" list->counts: %d\n", list->counts);  // Print the total count of elements
    printf(" The sorted list: ");
    while(node_ptr != NULL){        // Traverse the list and print each element
        printf("%d ", node_ptr->number);  // Print each number in the list
        node_ptr = node_ptr->next;  // Move to the next node
    }
    printf("\n\n");
}

// Function to insert a number into the sorted linked list
void sort_list(tNumStorHead *list, int input){
    if(list->counts < 0){           // Ensure the counts is non-negative
        list->counts = 0;
    }

    // Allocate memory for the new element (node)
    tNumStorage *new_age;
    new_age = (tNumStorage *) malloc (sizeof(tNumStorage));  // Allocate memory for the new element
    new_age->number = input;  // Set the input number to the new element
    new_age->next = NULL;     // Initialize the next pointer as NULL
    new_age->prev = NULL; // Initialize the previous pointer as NULL

    // If the list is empty, the new element becomes both the head and the tail
    if(list->counts == 0){
        list->head = new_age;
        list->tail = new_age;
    }
    else if(new_age->number < list->head->number){
        // If the new element is smaller than the head element, insert it at the front
        new_age->next = list->head;
        list->head->prev = new_age;
        list->head = new_age;
    }
    else{
        // Traverse the list to find the correct position for the new element
        tNumStorage *current = list->head;
        while (current != NULL){
            // If we are at the tail of the list
            if(current == list->tail){
                // Insert before the tail if the new number is smaller
                if(new_age->number < current->number){
                    new_age->next = current;
                    new_age->prev = current->prev;
                    current->prev->next = new_age;
                    current->prev = new_age;
                }
                else{
                    // Insert after the tail if the new number is larger
                    current->next = new_age;
                    new_age->prev = current;
                    list->tail = new_age;
                }
                break;  // Exit the loop once the element is inserted
            }
            else{
                // Insert the new element in the middle of the list
                if(new_age->number < current->next->number){
                    new_age->next = current->next;
                    new_age->prev = current;
                    current->next = new_age;
                    new_age->next->prev = new_age;
                    break;  // Exit the loop once the element is inserted
                }
            }
            current = current->next;  // Move to the next node
        }
    }
    list->counts++;  // Increment the element count in the list
    print_list(list);  // Print the updated list
}

// Function to delete the last element (tail) from the list
void delete_last(tNumStorHead *list){
    if(list->head == list->tail){    // If there is only one element in the list
        list->counts --;             // Decrease the count
        free(list->head);            // Free the memory for the only element
        list->head = NULL;           // Set head to NULL
        list->tail = NULL;           // Set tail to NULL
    }
    else{
        list->tail = list->tail->prev; // Move the tail to the previous element
        free(list->tail->next);            // Free the memory for the old tail
        list->tail->next = NULL;           // Set the new tail's next pointer to NULL
        list->counts--;                    // Decrease the element count
    }
    print_list(list);  // Print the updated list
}

// Function to print an error message when there is nothing to delete
void print_error_message(){
    printf(" There is nothing to delete\n\n");
}

// Function to get user input and insert it into the list
void get_input(tNumStorHead *list){
    int input = 0;
    while(input != -1){  // Continue until the user inputs -1
        printf("%s", "Input a Number: (-1 to exit, -2 to delete last): ");  // Prompt user for input
        scanf("%d", &input);  // Read input
        if(input == -1){  // Exit if input is -1
            break;
        }
        else if (input == -2){  // Delete the last element if input is -2
            if(list->counts == 0){  // Check if the list is empty
                print_error_message();  // Print error message
            }
            else{
                delete_last(list);  // Call delete_last to remove the last element
            }
        }
        else{
            sort_list(list, input);  // Insert the input into the list
        }
    }
}

int main(void){
    tNumStorHead *list;
    list = (tNumStorHead *) malloc (sizeof(tNumStorHead));  // Allocate memory for the list
    initial_list(list);  // Initialize the list
    get_input(list);  // Start getting user input
    free(list);  // Free the memory allocated for the list
}