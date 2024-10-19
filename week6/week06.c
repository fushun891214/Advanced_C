#include<stdio.h>
#include<stdlib.h>

// Define a structure to store individual numbers in the list
typedef struct num_storage{
    int number;
    struct num_storage *next;
} tNumStorage;

// Define a structure to manage the list head, tail, and counts
typedef struct num_stor_head{
    int counts;                 // Total number of elements in the list
    struct num_storage *head;    // Pointer to the head (first element) of the list
    struct num_storage *tail;    // Pointer to the tail (last element) of the list
} tNumStorHead;

// Function to initialize the list (set counts to 0, head and tail to NULL)
void initial_list(tNumStorHead *list){
    list->counts = 0;
    list->head = NULL;
    list->tail = NULL;
}

// Function to insert a number into the sorted linked list
void sort_list(tNumStorHead *list, int input){
    tNumStorage *new_age;
    new_age = (tNumStorage *) malloc (sizeof(tNumStorage));  // Allocate memory for the new element
    new_age->number = input;  // Set the input number to the new element
    new_age->next = NULL;     // Initialize the next pointer as NULL

    // If the list is empty, the new element becomes both the head and the tail
    if(list->counts == 0){
        list->head = new_age;
        list->tail = new_age;
    }
    else{
        // If the new number is smaller than the head, insert it at the head
        if(new_age->number < list->head->number){
            new_age->next = list->head;
            list->head = new_age;
        }
        else{
            // Traverse the list to find the correct position for the new element
            tNumStorage *head = list->head;
            while (head != NULL){
                // If we are at the tail of the list
                if(head == list->tail){
                    // Insert before the tail if the new number is smaller
                    if(new_age->number < list->tail->number){
                        new_age->next = list->tail;
                        head->next = new_age;
                    }
                    else{
                        // Insert after the tail if the new number is larger
                        list->tail->next = new_age;
                        list->tail = new_age;
                    }
                    break;  // Exit the loop once the element is inserted
                }
                else{
                    // Insert the new element in the middle of the list
                    if(new_age->number < head->next->number){
                        new_age->next = head->next;
                        head->next = new_age;
                        break;  // Exit the loop once the element is inserted
                    }
                }
                head = head->next;  // Move to the next node
            }
        }
    }
    list->counts++;  // Increment the element count in the list
}

// Function to print the entire list
void print_list(tNumStorHead *list){
    tNumStorage *node_ptr = list->head;
    printf(" list->counts: %d\n", list->counts);  // Print the total count of elements
    printf(" The sorted list: ");
    while(node_ptr != NULL){
        printf("%d ", node_ptr->number);  // Print each number in the list
        node_ptr = node_ptr->next;  // Move to the next node
    }
    printf("\n\n");
}

// Function to get user input and insert it into the list
void get_input(tNumStorHead *list){
    int input = 0;
    while(input != -1){
        printf("%s", "Input a Number: ");  // Prompt user for input
        scanf("%d", &input);
        if(input == -1){  // Exit if input is -1
            break;
        }
        else{
            sort_list(list, input);  // Insert the input into the list
        }
        print_list(list);  // Print the updated list
    }
}

int main(void){
    tNumStorHead *list;
    list = (tNumStorHead *) malloc (sizeof(tNumStorHead));  // Allocate memory for the list
    initial_list(list);  // Initialize the list
    get_input(list);  // Start getting user input
}