#include "main.h"
#include "queue.h"
#include "space.h"

int main(void)
{
    tQueue *queue;
    int operation, id, data_size;
    tQueueNode *target_node;
    
    init_space();
    queue = createQueue();

    while(1)
    {
        printf("\nRemaining memory space %d\n", remaining_space);
        printf("Which type you are going to operate?\n");
        printf("1. Add an item\n");
        printf("2. Remove an item with a specific Id\n");
        
        scanf("%d", &operation);
        
        if(operation == 1)
        {
            printf("  enter id: ");
            scanf("%d", &id);
            printf("  specify data type (units) you want: ");
            scanf("%d", &data_size);
            
            if(enqueue_node(queue, id, 0, data_size) == 0) {
                printf("    Cannot enter to the queue\n");
            }
            print_buffer_status();
        }
        else if(operation == 2)
        {
            printf("  Enter an ID to remove: ");
            scanf("%d", &id);
            target_node = find_target_node(queue, id);
            if(target_node == NULL) {
                printf("    Cannot find the target node\n");
            } else {
                dequeue_node(queue, target_node, target_node->data_type);
            }
            print_buffer_status();
        }
        else 
        {
            printf("    No such operation\n");   
        }
        print_queue(queue);
    }
}