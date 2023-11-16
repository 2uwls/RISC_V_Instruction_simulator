#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void simple_calculator(unsigned char* buffer, int* count, int* current_pc, int num_instructions) {
    int choice = 0;
    int operand1, operand2, result = 0;

    // Read a line of input
    if (fgets((char*)buffer, sizeof(buffer), stdin) == NULL) 
    {
        // Handle end of file or error
        exit(1);
    }

    // Parse the integer from the input line
    if (sscanf((char*)buffer, "%d", &choice) != 1) {
        // Invalid input, user pressed Enter without entering a number
        return;
    }

    if (choice == 1) 
    {
        printf("Enter operand 1: ");
        scanf("%d", &operand1);
        printf("Enter operand 2: ");
        scanf("%d", &operand2);
        result = operand1 + operand2;
        printf("Result: %d\n\n", result);
    } else if (choice == 2) 
    {
        printf("Enter operand 1: ");
        scanf("%d", &operand1);
        printf("Enter operand 2: ");
        scanf("%d", &operand2);
        result = operand1 - operand2;
        printf("Result: %d\n\n", result);
    } else if (choice == 3) 
    {
        exit(0);
    }

    (*count)++;
}