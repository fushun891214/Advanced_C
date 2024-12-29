#include "queue.h"
#include "space.h"

tQueue* createQueue(void){    
    tQueue *queue;
    queue=(tQueue *) malloc (sizeof(tQueue));

    if (queue){
        queue->front=NULL;
        queue->rear=NULL;  
        queue->count=0;
    }

    return queue;
}

int enqueue_node(tQueue *queue, int id, int score, int data_type)
{
    tQueueNode *queue_node;
    void *newptr = NULL;
    int mem_location;

    queue_node = (tQueueNode *)malloc(sizeof(tQueueNode));
    if (!queue_node) {
        printf("    Queue node allocation failed!\n");
        return 0;
    }

    our_malloc(data_type, &newptr, &mem_location);
    if (newptr == NULL) {
        printf("    Enqueue Failed !!! \n");
        free(queue_node);
        return 0;
    }

    queue_node->type = data_type;
    queue_node->content = newptr;

    if (data_type == TYPE_SMALL) {
        tQueueSmall *small = (tQueueSmall *)newptr;
        small->id = id;
        small->score = score;
        small->location = mem_location;
    } else {
        tQueueLarge *large = (tQueueLarge *)newptr;
        large->id = id;
        large->location = mem_location;
        // 初始化 score 陣列
        for (int i = 0; i < 8; i++) {
            large->score[i] = score;
        }
    }

    queue_node->next = NULL;
    queue_node->prev = NULL;

    if (queue->count == 0) {
        queue->front = queue_node;
        queue->rear = queue_node;
    } else {
        queue_node->prev = queue->rear;
        queue->rear->next = queue_node;
        queue->rear = queue_node;
    }

    queue->count++;
    return 1;
}

void dequeue_node(tQueue *queue, tQueueNode *target, int data_type)
{
    if (queue->count == 1) {
        queue->front = NULL;
        queue->rear = NULL;
    } else if (target == queue->front) {
        queue->front = target->next;
        queue->front->prev = NULL;
    } else if (target == queue->rear) {
        queue->rear = target->prev;
        queue->rear->next = NULL;
    } else {
        target->prev->next = target->next;
        target->next->prev = target->prev;
    }

    // 釋放記憶體
    int mem_location;
    if (data_type == TYPE_SMALL) {
        tQueueSmall *small = (tQueueSmall *)target->content;
        mem_location = small->location;
    } else {
        tQueueLarge *large = (tQueueLarge *)target->content;
        mem_location = large->location;
    }
    
    our_free(data_type, mem_location);
    free(target);          // 釋放節點記憶體
    
    queue->count--;
}

tQueueNode *find_target_node(tQueue *queue, int id, int data_type)
{
    tQueueNode *target = queue->front;
    
    while (target != NULL) {
        if (target->type == data_type) {
            if (data_type == TYPE_SMALL) {
                tQueueSmall *small = (tQueueSmall *)target->content;
                if (small->id == id) {
                    return target;
                }
            } else {
                tQueueLarge *large = (tQueueLarge *)target->content;
                if (large->id == id) {
                    return target;
                }
            }
        }
        target = target->next;
    }
    return NULL;
}


void print_queue (tQueue *queue)
{
    tQueueNode *target = queue->front;
    
    printf("      type mixed queue: ");
    while (target != NULL) {
        if (target->type == TYPE_SMALL) {
            tQueueSmall *small = (tQueueSmall *)target->content;
            printf("%d,%d(%d,%d) ", small->id, small->score,target->type,small->location);
        } else {
            tQueueLarge *large = (tQueueLarge *)target->content;
            printf("%d,%d(%d,%d) ", large->id, large->score[0],target->type,large->location);
        }
        target = target->next;
    }
    printf("\n");
}