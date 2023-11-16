#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "calculate.h"
#include "registers.h"
#include "simulator.h"
#include "data_memory.h"


// rType order: ins rd, rs1, rs2
void simulate_add_instruction(char *rd, char *rs1, char *rs2)
{
    int rd_num = atoi(rd);
    int rs1_num = atoi(rs1);
    int rs2_num = atoi(rs2);
    int32_t result = get_register_value(rs1_num) + get_register_value(rs2_num);
    set_register_value(rd_num, result);
}

void simulate_sub_instruction(char *rd, char *rs1, char *rs2)
{
    int rd_num = atoi(rd);
    int rs1_num = atoi(rs1);
    int rs2_num = atoi(rs2);
    int32_t result = get_register_value(rs1_num) - get_register_value(rs2_num);
    set_register_value(rd_num, result);
}

void simulate_xor_instruction(char *rd, char *rs1, char *rs2)
{
    int rd_num = atoi(rd);
    int rs1_num = atoi(rs1);
    int rs2_num = atoi(rs2);
    int32_t result = get_register_value(rs1_num) ^ get_register_value(rs2_num);
    set_register_value(rd_num, result);
}

void simulate_or_instruction(char *rd, char *rs1, char *rs2)
{
    int rd_num = atoi(rd);
    int rs1_num = atoi(rs1);
    int rs2_num = atoi(rs2);
    int32_t result = get_register_value(rs1_num) | get_register_value(rs2_num);
    set_register_value(rd_num, result);
}

void simulate_and_instruction(char *rd, char *rs1, char *rs2)
{
    int rd_num = atoi(rd);
    int rs1_num = atoi(rs1);
    int rs2_num = atoi(rs2);
    int32_t result = get_register_value(rs1_num) & get_register_value(rs2_num);
    set_register_value(rd_num, result);
}
void simulate_sll_instruction(char *rd, char *rs1, char *rs2)
{
    int rd_num = atoi(rd);
    int rs1_num = atoi(rs1);
    int rs2_num = atoi(rs2);
    int32_t result = get_register_value(rs1_num) << get_register_value(rs2_num);
    set_register_value(rd_num, result);
}

void simulate_slt_instruction(char *rd, char *rs1, char *rs2)
{
    int rd_num = atoi(rd);
    int rs1_num = atoi(rs1);
    int rs2_num = atoi(rs2);
    int32_t result = (int32_t) get_register_value(rs1_num) < (int32_t) get_register_value(rs2_num) ? 1 : 0;
    set_register_value(rd_num, result);
}

void simulate_srl_instruction(char *rd, char *rs1, char *rs2)
{
    int rd_num = atoi(rd);
    int rs1_num = atoi(rs1);
    int rs2_num = atoi(rs2);
    int32_t result =  (uint32_t) get_register_value(rs1_num) >> get_register_value(rs2_num);
    set_register_value(rd_num, result);
}

void simulate_sra_instruction(char *rd, char *rs1, char *rs2)
{
    int rd_num = atoi(rd);
    int rs1_num = atoi(rs1);
    int rs2_num = atoi(rs2);
    int32_t result = (signed) get_register_value(rs1_num) >> get_register_value(rs2_num);
    set_register_value(rd_num, result);
}
// iType order: ins rd, rs1, imm12
void simulate_slti_instruction(char *rd, char *rs1, char *imm12)
{
    int rd_num = atoi(rd);
    int rs1_num = atoi(rs1);
    int imm_num = atoi(imm12);
    int32_t result = (int32_t) get_register_value(rs1_num) < imm_num ? 1 : 0;
    set_register_value(rd_num, result);
}
void simulate_addi_instruction(char *rd, char *rs1, char *imm12)
{
    int rd_num = atoi(rd);
    int rs1_num = atoi(rs1);
    int imm_num = atoi(imm12);
    int32_t result = get_register_value(rs1_num) + imm_num;
    set_register_value(rd_num, result);
}
void simulate_andi_instruction(char *rd, char *rs1, char *imm12)
{
    int rd_num = atoi(rd);
    int rs1_num = atoi(rs1);
    int imm_num = atoi(imm12);
    int32_t result = get_register_value(rs1_num) & imm_num;
    set_register_value(rd_num, result);
}
void simulate_xori_instruction(char *rd, char *rs1, char *imm12)
{
    int rd_num = atoi(rd);
    int rs1_num = atoi(rs1);
    int imm_num = atoi(imm12);
    int32_t result = get_register_value(rs1_num) ^ imm_num;
    set_register_value(rd_num, result);
}
void simulate_ori_instruction(char *rd, char *rs1, char *imm12)
{
    int rd_num = atoi(rd);
    int rs1_num = atoi(rs1);
    int imm_num = atoi(imm12);
    int32_t result = (int32_t) get_register_value(rs1_num) | imm_num;
    set_register_value(rd_num, result);
}
//iType order: ins rd, rs1, imm5(shamt)
void simulate_slli_instruction(char *rd, char *rs1, char *imm5)
{
    int rd_num = atoi(rd);
    int rs1_num = atoi(rs1);
    int imm_num = atoi(imm5);
    int32_t result = get_register_value(rs1_num) << imm_num;
    set_register_value(rd_num, result);
}

void simulate_srli_instruction(char *rd, char *rs1, char *imm5)
{
    int rd_num = atoi(rd);
    int rs1_num = atoi(rs1);
    int imm_num = atoi(imm5);
    uint32_t result = (uint32_t) get_register_value(rs1_num) >> imm_num;
    set_register_value(rd_num, result);
}

void simulate_srai_instruction(char *rd, char *rs1, char *imm5)
{
    int rd_num = atoi(rd);
    int rs1_num = atoi(rs1);
    int imm_num = atoi(imm5);
    int32_t result = (signed) get_register_value(rs1_num) >> imm_num;
    set_register_value(rd_num, result);
}
//iTyleLoad order: ins rd, imm12(rs1)
void simulate_lw_instruction(char *rd, char *imm, char *rs1)
{
    int rd_num = atoi(rd);
    int offset = atoi(imm);
    int rs1_num = atoi(rs1);
    int32_t address = get_register_value(rs1_num) + offset;
    int32_t data = load_data_from_memory(address);
    set_register_value(rd_num, data);

    if (get_register_value(rs1_num)>=0x20000000)
    {
        int word_num = 0;
        scanf("%d",&word_num);
        int32_t word_address = get_register_value(rs1_num) + offset;
        int32_t word_data = load_word_data_from_memory(word_address);
        set_register_value(rd_num, word_num);
        // set_register_value(rd_num, word_data);
    }
}
//sType order: ins rs2, imm12(rs1)
void simulate_sw_instruction(char *rs2, char *imm12, char *rs1)
{
    int rs2_num = atoi(rs2);
    int offset = atoi(imm12);
    int rs1_num = atoi(rs1);
    int32_t address = get_register_value(rs1_num) + offset;
    int32_t data = get_register_value(rs2_num);
    store_data_to_memory(address, data);

    if (get_register_value(rs1_num)>=0x20000000)
    {
        int32_t word_address = get_register_value(rs1_num) + offset;
        int32_t word_data = get_register_value(rs2_num);
        store_word_data_to_memory(word_address, word_data);
        printf("%c",word_data);
    }
        
}
//sbType order: ins rs1, rs2, imm13
void simulate_beq_instruction(char *rs1, char *rs2, char *imm13)
{
    int rs1_num = atoi(rs1);
    int rs2_num = atoi(rs2);
    int imm_num = atoi(imm13);

    if (get_register_value(rs1_num) == get_register_value(rs2_num)) 
    {
        update_program_counter(imm_num);
    } else 
    {
        update_program_counter(4);
    }
    

}

void simulate_bne_instruction(char *rs1, char *rs2, char *imm13)
{
    int rs1_num = atoi(rs1);
    int rs2_num = atoi(rs2);
    int imm_num = atoi(imm13);

    if (get_register_value(rs1_num) != get_register_value(rs2_num)) 
    {
        update_program_counter(imm_num);
    } else 
    {
        update_program_counter(4);
    }
}

void simulate_blt_instruction(char *rs1, char *rs2, char *imm13)
{
    int rs1_num = atoi(rs1);
    int rs2_num = atoi(rs2);
    int imm_num = atoi(imm13);

    if (get_register_value(rs1_num) < get_register_value(rs2_num)) 
    {
        update_program_counter(imm_num);
    } else 
    {
        update_program_counter(4);  
    }
}

void simulate_bge_instruction(char *rs1, char *rs2, char *imm13)
{
    int rs1_num = atoi(rs1);
    int rs2_num = atoi(rs2);
    int imm_num = atoi(imm13);

    if (get_register_value(rs1_num) >= get_register_value(rs2_num)) 
    {
        update_program_counter(imm_num);
    } else 
    {
        update_program_counter(4); 
    }
}
//luiIns order: ins rd, imm20
void simulate_lui_instruction(char *rd, char *imm20)
{
    int rd_num = atoi(rd);
    int imm_num = atoi(imm20);
    set_register_value(rd_num, imm_num);
}

void simulate_auipc_instruction(char *rd, char *imm20)
{
    int rd_num = atoi(rd);
    int imm_num = atoi(imm20);
    int32_t result = get_program_counter() + imm_num;
    set_register_value(rd_num, result);
}

void simulate_jal_instruction(char *rd, char *imm21)
{
    int rd_num = atoi(rd);
    int imm_num = atoi(imm21);
    set_register_value(rd_num, get_program_counter()+4);
    update_program_counter(imm_num);
}

void simulate_jalr_instruction(char *rd, char *imm12, char* rs1)
{
    int rd_num = atoi(rd);
    int imm_num = atoi(imm12);
    int rs1_num = atoi(rs1);
    int32_t target_address = (get_register_value(rs1_num)) + imm_num & ~1;
    set_register_value(rd_num, get_program_counter() + 4);
    set_program_counter(target_address);
}
