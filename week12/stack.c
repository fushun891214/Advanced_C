#include "stack.h"

tStack *create_stack(void)
{
    tStack *stack = (tStack *)malloc(sizeof(tStack));
    stack->head = NULL;
    stack->count = 0;
    return stack;
}

void handle_push_operation(tStack *stack_ptr)
{
    tNode *new_node = (tNode *)malloc(sizeof(tNode));
	new_node->data_ptr = NULL;
    new_node->next = NULL;
    
    if(stack_ptr->count == N){
	    printf ("[Error]  handlePushOperation(): space full \n\n");
        free(new_node);
        return;
    }

    printf("  handlePushOperation(): enter score value: ");
    int score;
    scanf("%d", &score);

    get_score_space(&new_node->data_ptr);
    new_node->data_ptr->score = score;

    if(stack_ptr->head == NULL){
        stack_ptr->head = new_node;
    }
    else{
        tNode *current_node = stack_ptr->head;
        while(current_node->next != NULL){
            current_node = current_node->next;
        }
        current_node->next = new_node;
    }

    stack_ptr->count++;
}

void handle_pop_operation(tStack *stack_ptr)
{
    if(stack_ptr->count == 0){
        printf ("  [Error]  handlePopOperation(): nothing in stack \n\n");
        return;
    }

    tNode *current_node = stack_ptr->head;

    while(current_node->next != NULL){
        current_node = current_node->next;
    }

    printf("  handlePopOperation(): poped value: %d\n", current_node->data_ptr->score);
    return_score_space(current_node->data_ptr->loc);

    if(stack_ptr->count == 1){
        free(stack_ptr->head);
        stack_ptr->head = NULL;
    }
    else{
        current_node = stack_ptr->head;
        while(current_node->next->next != NULL){
            current_node = current_node->next;
        }
        free(current_node->next);
        current_node->next = NULL;
    }
    stack_ptr->count --;
}

void print_stack_content(tStack *stack_ptr)
{
    if(stack_ptr->count == 0){
        printf("   printStackContent(): stack items -> ");
        return;
    }

    int items[N][2];
    int count = 0;

    tNode *current = stack_ptr->head;
    while(current != NULL){
        items[count][0] = current->data_ptr->score;
        items[count][1] = current->data_ptr->loc;
        count++;
        current = current->next;
    }

    printf("   printStackContent(): stack items -> ");
    for(int i=count-1;i>=0;i--){
        printf("%d(%d) ",items[i][0],items[i][1]);
    }
    
}

