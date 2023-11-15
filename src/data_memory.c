#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define DATA_MEMORY_SIZE 0x10000

uint8_t data_memory[DATA_MEMORY_SIZE];

void initialize_data_memory() {
    for (int i = 0; i < DATA_MEMORY_SIZE; i++) {
        data_memory[i] = 0xFF;
    }
}

int32_t load_data_from_memory(int32_t address) {
    int32_t result = 0;
    if (address >= 0x10000000 && address <= 0x1000FFFF) {
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
    int address = 0x10000000;
    int value;
    while (fread(&value, sizeof(int), 1, file) == 1) {
        for (int i = 0; i < 4; i++) {
            data_memory[address - 0x10000000 + i] = (value >> (i * 8)) & 0xFF;
        }
        address += 4;
    }
    fclose(file);
}

