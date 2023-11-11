CC=gcc
BUILD_DIR=build
SOURCE_DIR=src
TARGET=riscv-sim
OBJECTS=$(BUILD_DIR)/calculate.o $(BUILD_DIR)/disassembler.o $(BUILD_DIR)/registers.o $(BUILD_DIR)/simulator.o $(BUILD_DIR)/main.o
 
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^

$(BUILD_DIR)/calculate.o : $(SOURCE_DIR)/calculate.c
	$(CC) -c -o $@ $^

$(BUILD_DIR)/disassembler.o : $(SOURCE_DIR)/disassembler.c
	$(CC) -c -o $@ $^

$(BUILD_DIR)/registers.o : $(SOURCE_DIR)/registers.c
	$(CC) -c -o $@ $^

$(BUILD_DIR)/simulator.o : $(SOURCE_DIR)/simulator.c
	$(CC) -c -o $@ $^
	
$(BUILD_DIR)/main.o : $(SOURCE_DIR)/main.c
	$(CC) -c -o $@ $^

clean:
	rm $(OBJECTS) $(TARGET)