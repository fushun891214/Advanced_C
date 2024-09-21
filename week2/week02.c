#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to swap two character pointers
void swap(char **a, char **b) {
    char *temp = *a;
    *a = *b;
    *b = temp;
}

// Function to swap the first and third rows of the matrix
void swapOddNumberRow(char **argv, int matrix_row_size) {
    // Swap the first row and the third row
    for (int i = 0; i < matrix_row_size; i++) {
        char **first_row = argv + i;  // Pointer to elements in the first row
        char **second_row = argv + (2 * matrix_row_size) + i; // Pointer to elements in the third row
        swap(first_row, second_row);
    }
}

// Function to swap elements in the first and third columns of the matrix
void swapOddNumberColumn(char **argv, int matrix_column_size) {
    // Swap the first column and the third column
    for (int i = 0; i < matrix_column_size; i++) {
        char **first_column = argv + (matrix_column_size * i);  // Pointer to elements in the first column
        char **second_column = (argv + 2) + (matrix_column_size * i); // Pointer to elements in the third column
        swap(first_column, second_column);
    }
}

int main(int argc, char *argv[]) {
    int argv_size = argc;
    int matrix_row_size = sqrt(argv_size - 2); // Calculate the number of rows in the matrix
    int matrix_column_size = sqrt(argv_size - 2); // Calculate the number of columns in the matrix

    // Output the original matrix
    printf("Original matrix:\n");
    for (int i = 2; i < argv_size; i++) {
        int argv_element = atoi(*(argv + i));
        if ((i - 2) % matrix_row_size == 0) {
            printf("\n");
        }
        printf("%4d", argv_element);
    }
    printf("\n");

    // Swap the first and third rows
    swapOddNumberRow((argv + 2), matrix_row_size);

    printf("\n");
    // Output the matrix after row swap
    printf("After swap row:\n");
    for (int i = 2; i < argv_size; i++) {
        int argv_element = atoi(*(argv + i));
        if ((i - 2) % matrix_row_size == 0) {
            printf("\n");
        }
        printf("%4d", argv_element);
    }
    printf("\n");

    // Swap the first and third columns
    swapOddNumberColumn((argv + 2), matrix_column_size);

    printf("\n");
    // Output the matrix after column swap
    printf("After swap column:\n");
    for (int i = 2; i < argv_size; i++) {
        int argv_element = atoi(*(argv + i));
        if ((i - 2) % matrix_row_size == 0) {
            printf("\n");
        }
        printf("%4d", argv_element);
    }
    printf("\n");

    return 0;
}