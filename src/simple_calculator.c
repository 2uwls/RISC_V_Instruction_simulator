#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void simple_calculator(unsigned char* buffer, int* count, int* current_pc, int num_instructions) {
    int choice = 0;
    int operand1, operand2, result = 0;

    if (fgets((char*)buffer, sizeof(buffer), stdin) == NULL) 
    {
        exit(1);
    }

    if (sscanf((char*)buffer, "%d", &choice) != 1) {
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