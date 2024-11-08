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
    struct num_storage *tail; // Pointer to the head (first element) of the list
} tNumStorHead;

// Function to initialize the list (set counts to 0, head and tail to NULL)
void initial_list(tNumStorHead *list){
    list->counts = 0;        // Initialize the element count to 0
    list->head = NULL;       // Set the head pointer to NULL (empty list)
    list->tail = NULL;
}

// Function to print the entire list
void print_list(tNumStorHead *list){
    tNumStorage *node_ptr;

    printf("\n");
    printf("counts: %d \n", list->counts);
    node_ptr = list->head;
    printf(" Form head --> ");

    while (node_ptr != NULL){
        printf("%d ",node_ptr->number);
        node_ptr = node_ptr->next;
    }

    node_ptr = list->tail;
    printf("\n Form tail --> ");

    while ((node_ptr != NULL)){
        printf("%d ",node_ptr->number);
        node_ptr = node_ptr->prev;
    }

    printf("\n\n");
}

void add_Node(tNumStorHead *list, int input_value,int input_position,int input_before_or_after_position){
    tNumStorage *new_age;
    new_age = (tNumStorage *)malloc(sizeof(tNumStorage));
    new_age->next = NULL;
    new_age->prev = NULL;
    new_age->number = input_value;

    if(list->counts == 0){ //Case1:add first element
        list->head = new_age;
        list->tail = new_age;
        new_age->next = NULL;
        new_age->prev = NULL;
    }
    else if (input_position == list->counts){ //Case3:add element at tail
        if(input_before_or_after_position == 1){
            new_age->prev = list->tail->prev;
            new_age->next = list->tail;
            new_age->prev->next = new_age;
            list->tail->prev = new_age;
        }
        else{
            new_age->prev = list->tail;
            list->tail->next = new_age;
            list->tail = new_age;
        }
    }
    else if(input_position == 1){ //Case2:add element at head
        if(input_before_or_after_position == 1){
            new_age->next = list->head;
            list->head = new_age;
            new_age->next->prev = new_age;
        }
        else{
            new_age->prev = list->head;
            new_age->next = list->head->next;
            list->head->next = new_age;
            new_age->next->prev = new_age;
        }
    }
    else{ //Case4:add element at middle
        tNumStorage *current = list->head;

        for(int i=1;i<input_position;i++){
            current = current->next;
        }

        if(input_before_or_after_position == 1){
            new_age->next = current;
            new_age->prev = current->prev;
            current->prev->next = new_age;
            current->prev = new_age;
        }
        else{
            new_age->prev = current;
            new_age->next = current->next;
            current->next->prev = new_age;
            current->next = new_age;
        }
    }

    list->counts++;  
    print_list(list);  
}


void remove_Node(tNumStorHead *list,int input_position){
    if(list->counts == 1){ //Case1:remove last one
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
    }
    else if(input_position == 1){
        list->head = list->head->next;
        free(list->head->prev);
        list->head->prev = NULL;
    }
    else if(input_position == list->counts){
        list->tail = list->tail->prev;
        free(list->tail->next);
        list->tail->next = NULL;
    }
    else{
        tNumStorage *current = list->head;
        for(int i=1;i<input_position;i++){
            current = current->next;
        }
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
    }
    
    list->counts--;
    print_list(list);
}



// Function to get user input and insert it into the list
void get_input(tNumStorHead *list){
    int input_status = 0;
    int input_value = 0;
    int input_position = 0;
    int input_before_or_after_position = 0;

    while(1){  
        printf("1. Add a number or 2. Delete a number: ");  
        scanf("%d", &input_status);
        
        if(input_status == 1){  //Add a number
            printf(" Add a number: "); 
            scanf("%d", &input_value); 
            if(list->counts != 0){
                printf("  Specify a target location: ");
                scanf("%d", &input_position);
                printf("  1. Before or 2. After the location %d: ",input_position);
                scanf("%d", &input_before_or_after_position);
            }
            add_Node(list,input_value,input_position,input_before_or_after_position);
        }
        else if (input_status == 2){ //Delete a number
            printf(" Specify a target location: ");
            scanf("%d", &input_position); 
            remove_Node(list,input_position);
        }
        else{ //Exception case
            printf(" No such choose !\n");
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