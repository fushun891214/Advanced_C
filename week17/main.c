#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum{
    HOME,
    CELLULAR
} PhoneType;

typedef enum{
    CHT,
    FET,
    TWN
} Operator;

typedef struct user_node{
    char name[10];
    PhoneType type;
    union{
        struct{
            char areaCode[4];
            char number[8];
        } home;
        struct{
            Operator operator;
            char number[10];
        } cellular;
    }phone;
} UserNode;

typedef struct LinkListNode{
    struct LinkListNode *next;
    UserNode data;
} LinkListNode;

LinkListNode *createNode(void);
void addUser(LinkListNode **head);
void printList(LinkListNode *head);

int main(){
    LinkListNode *head = NULL;
    char choice;

    do{
        printf("Add new user? (y/n): ");
        scanf(" %c", &choice);
        if(choice == 'y'){
            addUser(&head);
            printList(head);
        }
    }while(choice == 'y');

    return 0;
}

LinkListNode *createNode(void){
    LinkListNode *newNode = (LinkListNode *)malloc(sizeof(LinkListNode));
    if(!newNode){
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->next = NULL;
    return newNode;
}

void addUser(LinkListNode **head){
    LinkListNode *newNode = createNode();

    printf("Enter name: ");
    scanf("%s", newNode->data.name);

    printf("Phone type (0: home, 1: cellular): ");
    scanf("%d", (int *)&newNode->data.type);

    if(newNode->data.type == HOME){
        printf("Area code: ");
        scanf("%s", newNode->data.phone.home.areaCode);
        printf("Number: ");
        scanf("%s", newNode->data.phone.home.number);
    }
    else{
        printf("Operator (0: CHT, 1: FET, 2: TWN): ");
        scanf("%d", (int *)&newNode->data.phone.cellular.operator);
        printf("Number: ");
        scanf("%s", newNode->data.phone.cellular.number);
    }

    newNode->next = *head;
    *head = newNode;
}

void printList(LinkListNode* head) {
    printf("\n=== User List ===\n");
    while(head) {
        printf("Name: %s\n", head->data.name);
        if(head->data.type == HOME) {
            printf("Home: (%s)%s\n", 
                head->data.phone.home.areaCode,
                head->data.phone.home.number);
        } else {
            const char* ops[] = {"CHT", "FET", "TWN"};
            printf("Cell(%s): %s\n",
                ops[head->data.phone.cellular.operator],
                head->data.phone.cellular.number);
        }
        printf("---------------\n");
        head = head->next;
    }
}