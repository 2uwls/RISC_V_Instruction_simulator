#include <stdio.h>
#include <stdint.h>


// Define the number of registers
#define NUM_REGISTERS 32

// Register file
int32_t registers[NUM_REGISTERS];
int program_counter = 0;

// Function to initialize registers
void initialize_registers() {
    for (int i = 0; i < NUM_REGISTERS; i++) {
        registers[i] = 0;
    }
}

// Function to get the value of a register
int32_t get_register_value(int reg_num) {
    if (reg_num >= 0 && reg_num < NUM_REGISTERS) {
        return registers[reg_num];
    }
}

// Function to set the value of a register
void set_register_value(int reg_num, int32_t value) {
    if (reg_num > 0 && reg_num < NUM_REGISTERS) {
        registers[reg_num] = value;
    } 
}

// Function to print the values of all registers
void print_registers() {
    for (int i = 0; i < NUM_REGISTERS; i++) {
        printf("x%d: 0x%08x\n", i, registers[i]);
    }
}

void update_program_counter(int offset) 
{
    program_counter += offset;
}

void set_program_counter(int pc)
{
    program_counter = pc;
}

// Function to get the current program counter value
int get_program_counter() {
    return program_counter;
}
