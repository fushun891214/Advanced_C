#ifndef __LIST_H__
#define __LIST_H__

#include<stdio.h>
#include<stdlib.h>

// Define a structure to store individual numbers in the list
typedef struct num_storage{
    int number;                      // The number to be stored
    struct num_storage *prev;        // Pointer to the previous node in the list
    struct num_storage *next;        // Pointer to the next node in the list
} tNumStorage;

// Define a structure to manage the list head, tail, and counts
typedef struct num_stor_head{
    int counts;                      // Total number of elements in the list
    struct num_storage *head;        // Pointer to the head (first element) of the list
    struct num_storage *tail;        // Pointer to the tail (last element) of the list
} tNumStorHead;

void initial_list(tNumStorHead *list);
void add_Node(tNumStorHead *list, int input_value, int input_position, int input_before_or_after_position);
void remove_Node(tNumStorHead *list, int input_position);

#endif