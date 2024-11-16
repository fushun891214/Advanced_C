#include "list.h"

// Function to initialize the list (set counts to 0, head and tail to NULL)
void initial_list(tNumStorHead *list){
    list->counts = 0;                // Initialize the element count to 0
    list->head = NULL;               // Set the head pointer to NULL (empty list)
    list->tail = NULL;               // Set the tail pointer to NULL (empty list)
}

// Function to add a new node at a specific position
void add_Node(tNumStorHead *list, int input_value, int input_position, int input_before_or_after_position){
    tNumStorage *new_age;
    new_age = (tNumStorage *)malloc(sizeof(tNumStorage));  // Allocate memory for new node
    new_age->next = NULL;
    new_age->prev = NULL;
    new_age->number = input_value;

    if (list->counts == 0) { // Case 1: Add the first element to the list
        list->head = new_age;
        list->tail = new_age;
        new_age->next = NULL;
        new_age->prev = NULL;
    }
    else if (input_position == list->counts) { // Case 3: Add element at the tail
        if (input_before_or_after_position == 1) { // Before the tail
            new_age->prev = list->tail->prev;
            new_age->next = list->tail;
            new_age->prev->next = new_age;
            list->tail->prev = new_age;
        }
        else { // After the tail
            new_age->prev = list->tail;
            list->tail->next = new_age;
            list->tail = new_age;
        }
    }
    else if (input_position == 1) { // Case 2: Add element at the head
        if (input_before_or_after_position == 1) { // Before the head
            new_age->next = list->head;
            list->head = new_age;
            new_age->next->prev = new_age;
        }
        else { // After the head
            new_age->prev = list->head;
            new_age->next = list->head->next;
            list->head->next = new_age;
            new_age->next->prev = new_age;
        }
    }
    else { // Case 4: Add element at the middle of the list
        tNumStorage *current = list->head;

        // Traverse to the specified position
        for (int i = 1; i < input_position; i++) {
            current = current->next;
        }

        // Insert the new node at the specified position
        if (input_before_or_after_position == 1) { // Before the current position
            new_age->next = current;
            new_age->prev = current->prev;
            current->prev->next = new_age;
            current->prev = new_age;
        }
        else { // After the current position
            new_age->prev = current;
            new_age->next = current->next;
            current->next->prev = new_age;
            current->next = new_age;
        }
    }

    list->counts++;  // Increment the total element count
}

// Function to remove a node from a specific position
void remove_Node(tNumStorHead *list, int input_position){
    if (list->counts == 1) { // Case 1: Remove the only element in the list
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }
    else if (input_position == 1) { // Remove the head element
        list->head = list->head->next;
        free(list->head->prev);
        list->head->prev = NULL;
    }
    else if (input_position == list->counts) { // Remove the tail element
        list->tail = list->tail->prev;
        free(list->tail->next);
        list->tail->next = NULL;
    }
    else { // Remove an element from the middle of the list
        tNumStorage *current = list->head;
        for (int i = 1; i < input_position; i++) {
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
    }

    list->counts--;  // Decrement the total element count
}