#include <stdio.h>
#include <stdlib.h>

// Define the structure for the number list
typedef struct num_list {
    int counts;    // The number of elements in the list
    int *p_list;   // Pointer to the array of integers
} tNumList;

// Function to swap two integer values
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to fill the list with user input values
tNumList *fill_list(tNumList *list, int userInputNumber) {
    list->counts = userInputNumber;

    // Allocate memory for the list to hold userInputNumber integers
    list->p_list = (int *)malloc((userInputNumber) * sizeof(int));
    for (int i = 0; i < userInputNumber; i++) {
        // Read each integer from user input
        scanf("%d", (list->p_list+i));
    }
    return list;
}

// Function to perform bubble sort on the list
void bubble_sort(tNumList *list) {
    int n = list->counts;
    int i, j, flag;

    // Outer loop for each pass of the bubble sort
    for (i = 0; i < (n - 1); i++) {
        flag = 0;
        // Inner loop to compare adjacent elements
        for (j = 0; j < n - i - 1; j++) {
            if (*(list->p_list + j) > *(list->p_list + j + 1)) {
                // Swap the elements if they are in the wrong order
                swap((list->p_list + j), (list->p_list + j + 1));
                flag = 1;
            }
        }
        // If no elements were swapped, the list is already sorted
        if (flag == 0) {
            break;
        }
    }
}

// Function to merge two sorted lists and print the merged result
void merge(tNumList *list1, tNumList *list2) {
    int totalLength = (list1->counts) + (list2->counts);
    int list1Length = list1->counts;
    int list2Length = list2->counts;
    int list1Index = 0;
    int list2Index = 0;

    // Merge the two lists by comparing elements
    while (list1Index < list1Length && list2Index < list2Length) {
        if (*(list1->p_list+list1Index) < *(list2->p_list+list2Index)) {
            printf("%2d ", *(list1->p_list+list1Index));
            list1Index++;
        } else {
            printf("%2d ", *(list2->p_list+list2Index));
            list2Index++;
        }
    }

    // Print remaining elements from list1 if any
    while (list1Index < list1Length) {
        printf("%2d ", *(list1->p_list+list1Index));
        list1Index++;
    }

    // Print remaining elements from list2 if any
    while (list2Index < list2Length) {
        printf("%2d ", *(list2->p_list+list2Index));
        list2Index++;
    }
}

// Function to print all elements in the list
void print_list(tNumList *list) {
    int userInputNumber = list->counts;
    for (int i = 0; i < userInputNumber; i++) {
        // Print each element
        printf("%2d ", *(list->p_list + i));
    }
    printf("\n");
}

// Main function
int main(void) {
    tNumList *list1, *list2;

    // Allocate memory for two lists
    list1 = (tNumList *)malloc(sizeof(tNumList));
    list2 = (tNumList *)malloc(sizeof(tNumList));

    int userInputNumber;

    // Get input for list1 from the user
    printf("Please enter how many numbers in list1: ");
    scanf("%d", &userInputNumber);
    printf("\tPlease input %d numbers: ", userInputNumber);
    fill_list(list1, userInputNumber);
    
    // Get input for list2 from the user
    printf("Please enter how many numbers in list2: ");
    scanf("%d", &userInputNumber);
    printf("\tPlease input %d numbers: ", userInputNumber);
    fill_list(list2, userInputNumber);

    // Sort and print list1
    bubble_sort(list1);
    printf("sorted list1: ");
    print_list(list1);

    // Sort and print list2
    bubble_sort(list2);
    printf("sorted list2: ");
    print_list(list2);

    // Merge and print the two sorted lists
    printf("merged list: ");
    merge(list1, list2);

    free(list1);
    free(list2);
}