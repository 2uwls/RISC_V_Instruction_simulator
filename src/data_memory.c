#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


// Size of data memory (64KB)
#define DATA_MEMORY_SIZE 0x10000

// Data memory array
uint8_t data_memory[DATA_MEMORY_SIZE];

// Function to initialize data memory
void initialize_data_memory() {
    // Set the entire data memory to 0xFF
    for (int i = 0; i < DATA_MEMORY_SIZE; i++) {
        data_memory[i] = 0xFF;
    }
}

int32_t load_data_from_memory(int32_t address) {
    int32_t result = 0;

    // Check if the address is within the data memory range
    if (address >= 0x10000000 && address <= 0x1000FFFF) {
        // Load 4 bytes from data memory
        for (int i = 0; i < 4; i++) {
            result |= (data_memory[address - 0x10000000 + i] << (i * 8));
        }
    }

    return result;
}
void store_data_to_memory(int32_t address, int32_t data) {
    // Check if the address is within the data memory range
    if (address >= 0x10000000 && address <= 0x1000FFFF) {
        // Store 4 bytes into data memory
        for (int i = 0; i < 4; i++) {
            data_memory[address - 0x10000000 + i] = (data >> (i * 8)) & 0xFF;
        }
    }
}


void load_data_memory_from_file(const char *filename) {
    FILE *file = fopen(filename, "rb");
    // Read data from the file and store it in data memory starting from 0x10000000
    int address = 0x10000000;
    int value;
    while (fread(&value, sizeof(int), 1, file) == 1) {
        // Store the value in data memory
        for (int i = 0; i < 4; i++) {
            data_memory[address - 0x10000000 + i] = (value >> (i * 8)) & 0xFF;
        }
        // Move to the next 4-byte address in data memory
        address += 4;
    }

    fclose(file);
}

