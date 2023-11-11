#include <stdint.h>

void initialize_registers();
uint32_t get_register_value(int reg_num);
void set_register_value(int reg_num, uint32_t value);
void print_registers();