#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "disassembler.h"
#include "calculate.h"
#include "registers.h"
#include "data_memory.h"
#include "simple_calculator.h"

int main(int argc, char* argv[])
{
    if (argc != 3 && argc != 4)
    {
    printf("Usage: %s <instruction_file> [<data_file>] <num_instructions>\n", argv[0]);
    return 1;
    }
    FILE *instruction_file;
    unsigned char buffer[4];
    int count = 0;
    int binary_arr[32];
    initialize_registers();
    initialize_data_memory();

    if ((instruction_file = fopen(argv[1],"rb")) == NULL)
    {
        perror("fopen");
        exit(1);
    }

    FILE *data_file = NULL;
    if (argc == 4)
    {
        if ((data_file = fopen(argv[2], "rb")) == NULL)
        {
            perror("fopen");
            exit(1);
        }
        load_data_memory_from_file(argv[2]);
        fclose(data_file);
    }
    int num_instructions = atoi(argv[argc - 1]);
    int current_pc = 0;

    while (fread(buffer, sizeof(buffer), 1, instruction_file) == 1 && count < num_instructions)
    {
        unsigned int value = buffer[3] << 24 | buffer[2] << 16 | buffer[1] << 8 | buffer[0];
        fill_binary_arr(value, binary_arr); 
       
        char* result = disassemble(binary_arr); 


        if (memchr(buffer, '\n', sizeof(buffer)) != NULL) {
            // Call the function to handle input
            simple_calculator(buffer, &count, &current_pc, num_instructions);
        }
        // if (memchr(buffer, '\n', sizeof(buffer)) != NULL) {
        //     int choice = 0;
        //     int operand1, operand2, result = 0;
        //      // Read a line of input
        //      if (fgets((char*)buffer, sizeof(buffer), stdin) == NULL) {
        //         // Handle end of file or error
        //         break;
        //     }

        //     // Parse the integer from the input line
        //     if (sscanf((char*)buffer, "%d", &choice) != 1) {
        //         // Invalid input, user pressed Enter without entering a number
        //         continue;
        //     }


        //     if (choice == 1)
        //     {
        //         printf("Enter operand 1: ");
        //         scanf("%d", &operand1);
        //         printf("Enter operand 2: ");
        //         scanf("%d", &operand2);
        //         result = operand1 + operand2;
        //         printf("Result: %d\n\n", result);
        //     }
        //     else if (choice == 2)
        //     {
        //         printf("Enter operand 1: ");
        //         scanf("%d", &operand1);
        //         printf("Enter operand 2: ");
        //         scanf("%d", &operand2);
        //         result = operand1 - operand2;
        //         printf("Result: %d\n\n", result);
        //     }
        //     else if (choice == 3)
        //     {
        //         break;
        //     }
            
        // }
    

        // printf("current pc : %d\n",current_pc);
        // printf("get_pc_value %d\n",get_program_counter());

        // Check if BNE was executed and update accordingly
        if (current_pc != get_program_counter()) {

            current_pc = get_program_counter();
            // Move back to the branch instruction and read the instruction
            fseek(instruction_file, current_pc-4, SEEK_SET);
            fread(buffer, sizeof(buffer), 1, instruction_file);
    
        } else {
            current_pc += 4;
            update_program_counter(4);
        }

        count++;

        if (feof(instruction_file)!=0) {
        printf("End of file reached.\n");
        break;
        }

    }
    print_registers();
    fclose(instruction_file);
    if (data_file != NULL)
    {
        fclose(data_file);
    }
    return 0;   
}