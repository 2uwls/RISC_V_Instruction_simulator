#include <stdio.h>
#include <stdint.h>

#define NUM_REGISTERS 32

int32_t registers[NUM_REGISTERS];
int program_counter = 0;

void initialize_registers() 
{
    for (int i = 0; i < NUM_REGISTERS; i++) 
        registers[i] = 0;
}

int32_t get_register_value(int reg_num) 
{
    if (reg_num >= 0 && reg_num < NUM_REGISTERS) 
    {
        int32_t register_num = registers[reg_num];
        return register_num;
    }
    return 0;
}

void set_register_value(int reg_num, int32_t value) 
{
    if (reg_num > 0 && reg_num < NUM_REGISTERS) 
        registers[reg_num] = value;
}

void print_registers() 
{
    for (int i = 0; i < NUM_REGISTERS; i++)
        printf("x%d: 0x%08x\n", i, registers[i]);
}

void update_program_counter(int offset) 
{
    program_counter += offset;
}

void set_program_counter(int pc)
{
    program_counter = pc;
}

int get_program_counter() 
{
    return program_counter;
}
