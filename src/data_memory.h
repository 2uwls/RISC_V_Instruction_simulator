void initialize_data_memory();
int32_t load_data_from_memory(int32_t address);
void store_data_to_memory(int32_t address, int32_t data);
void load_data_memory_from_file(const char *filename);

void initialize_word_data_memory();
uint32_t load_word_data_from_memory(int32_t address);
void store_word_data_to_memory(int32_t address, uint32_t data);
void load_word_data_memory_from_file(const char *filename);