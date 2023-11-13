#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "calculate.h"
#include "registers.h"
#include "simulator.h"


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
//shift operation
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
    int32_t result = get_register_value(rs1_num) >> get_register_value(rs2_num);
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
    printf("%d",result);
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
    int32_t result = get_register_value(rs1_num) >> imm_num;
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
}
//sType order: ins rs2, imm12(rs1)
void simulate_sw_instruction(char *rs2, char *imm12, char *rs1)
{
}
//sbType order: ins rs1, rs2, imm13
void simulate_beq_instruction(char *rs1, char *rs2, char *imm13)
{
    

}

void simulate_bne_instruction(char *rs1, char *rs2, char *imm13)
{
    int rs1_num = atoi(rs1);
    int rs2_num = atoi(rs2);
    int imm_num = atoi(imm13);

    if (get_register_value(rs1_num) != get_register_value(rs2_num)) {
        // Branch taken: update the program counter
        update_program_counter(imm_num);
    } else {
        // Branch not taken: continue to the next instruction
        update_program_counter(4);  // Assuming each instruction is 4 bytes
    }

}

void simulate_blt_instruction(char *rs1, char *rs2, char *imm13)
{
}

void simulate_bge_instruction(char *rs1, char *rs2, char *imm13)
{
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
}

void simulate_jal_instruction(char *rd, char *imm21)
{
}

void simulate_jalr_instruction(char *rd, char *rs1, char *rs2)
{
}
