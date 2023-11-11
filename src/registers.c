#include <stdio.h>
#include <stdint.h>



// Define the number of registers
#define NUM_REGISTERS 32

// Register file
uint32_t registers[NUM_REGISTERS];

// Function to initialize registers
void initialize_registers() {
    for (int i = 0; i < NUM_REGISTERS; i++) {
        registers[i] = 0;
    }
}

// Function to get the value of a register
uint32_t get_register_value(int reg_num) {
    if (reg_num >= 0 && reg_num < NUM_REGISTERS) {
        return registers[reg_num];
    }
}

// Function to set the value of a register
void set_register_value(int reg_num, uint32_t value) {
    if (reg_num >= 0 && reg_num < NUM_REGISTERS) {
        registers[reg_num] = value;
    } 
}

// Function to print the values of all registers
void print_registers() {
    for (int i = 0; i < NUM_REGISTERS; i++) {
        printf("x%d: 0x%08x\n", i, registers[i]);
    }
}