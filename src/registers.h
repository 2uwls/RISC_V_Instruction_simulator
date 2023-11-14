#include <stdint.h>

void initialize_registers();
int get_register_value(int reg_num);
void set_register_value(int reg_num, int32_t value);
void print_registers();
void update_program_counter(int offset);
void set_program_counter(int pc);
int get_program_counter();