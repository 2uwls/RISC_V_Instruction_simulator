#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "calculate.h"
#include "registers.h"
#include "simulator.h"


// rType order: ins rd, rs1, rs2
void simulate_add_instruction(char *instruction, char *rd, char *rs1, char *rs2)
{
}

void simulate_sub_instruction(char *instruction, char *rd, char *rs1, char *rs2)
{
}

void simulate_xor_instruction(char *instruction, char *rd, char *rs1, char *rs2)
{
}

void simulate_or_instruction(char *instruction, char *rd, char *rs1, char *rs2)
{
}

void simulate_and_instruction(char *instruction, char *rd, char *rs1, char *rs2)
{
}
//shift operation
void simulate_sll_instruction(char *instruction, char *rd, char *rs1, char *rs2)
{
}

void simulate_slt_instruction(char *instruction, char *rd, char *rs1, char *rs2)
{
}

void simulate_srl_instruction(char *instruction, char *rd, char *rs1, char *rs2)
{
}

void simulate_sra_instruction(char *instruction, char *rd, char *rs1, char *rs2)
{
}
// iType order: ins rd, rs1, imm12
void simulate_slti_instruction(char *instruction, char *rd, char *rs1, char *imm12)
{
}
void simulate_addi_instruction(char *instruction, char *rd, char *rs1, char *imm12)
{
    int rd_num = atoi(rd);
    int rs1_num = atoi(rs1);
    // int imm_num = convert_decimal_to_hexadecimal(imm12);
    printf("%d\n",rd_num);
    printf("%d\n",rs1_num);
    // printf("%x\n", imm_num);
    // uint32_t result = get_register_value(rs1_num) + imm_num;
    // set_register_value(rd_num, result);
    print_registers();

}
void simulate_andi_instruction(char *instruction, char *rd, char *rs1, char *imm12)
{
}
void simulate_xori_instruction(char *instruction, char *rd, char *rs1, char *imm12)
{
}
void simulate_ori_instruction(char *instruction, char *rd, char *rs1, char *imm12)
{
}
//iType order: ins rd, rs1, imm5(shamt)
void simulate_slli_instruction(char *instruction, char *rd, char *rs1, char *imm5)
{
}

void simulate_srli_instruction(char *instruction, char *rd, char *rs1, char *imm12)
{
}

void simulate_srai_instruction(char *instruction, char *rd, char *rs1, char *imm12)
{
}
//iTyleLoad order: ins rd, imm12(rs1)
void simulate_lw_instruction(char *instruction, char *rd, char *imm, char *rs1)
{
}
//sType order: ins rs2, imm12(rs1)
void simulate_sw_instruction(char *instruction, char *rs2, char *imm12, char *rs1)
{
}
