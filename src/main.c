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
    }
    int num_instructions = atoi(argv[argc - 1]);
    int current_pc = 0;

    while (fread(buffer, sizeof(buffer), 1, instruction_file) == 1 && count < num_instructions)
    {
        unsigned int value = buffer[3] << 24 | buffer[2] << 16 | buffer[1] << 8 | buffer[0];
        fill_binary_arr(value, binary_arr); 
        char* result = disassemble(binary_arr); 
        if (memchr(buffer, '\n', sizeof(buffer)) != NULL) {
            simple_calculator(buffer, &count, &current_pc, num_instructions);
        }
        
        if (current_pc != get_program_counter()) {
            current_pc = get_program_counter();

            fseek(instruction_file, current_pc-4, SEEK_SET);
            fread(buffer, sizeof(buffer), 1, instruction_file);
        } else {
            current_pc += 4;
            update_program_counter(4);
        }

        count++;
        if (feof(instruction_file)!=0) 
        {
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