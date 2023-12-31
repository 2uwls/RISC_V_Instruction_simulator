#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disassembler.h"
#include "calculate.h"
#include "simulator.h"


//distinguish the type by comparing opcode
char* disassemble(int*arr)
{
    //opcode
    char* opcode=slice_array(arr,0, 7);

    //variable for disassemble result
    char* instruction=(char*)malloc(256);
    char* imm=(char*)malloc(256);
    char* result=(char*)malloc(256);

    if (strcmp(opcode,"0110011")==0)
    {
        result=disassemble_with_rType(arr,instruction,result);
    }
    else if (strcmp(opcode,"0010011")==0)
    {
        result=disassemble_with_iType(arr,instruction,result);
    }  
    else if(strcmp(opcode,"0000011")==0)
    {
        result=disassemble_with_iTypeLoad(arr,instruction,result);
    }
    else if(strcmp(opcode,"0100011")==0)
    {
        result=disassemble_with_sType(arr,instruction,result,imm);
    }
    else if(strcmp(opcode,"1100011")==0)
    {
        result=disassemble_with_sbType(arr,instruction,result,imm);
    }
    else if(strcmp(opcode,"0110111")==0)
    {
        result=disassemble_with_luiInst(arr,instruction,result,imm);
    }
    else if(strcmp(opcode,"0010111")==0)
    {
        result=disassemble_with_auipcInst(arr,instruction,result,imm);
    }
    else if(strcmp(opcode,"1101111")==0)
    {
        result=disassemble_with_jalInst(arr,instruction,result,imm);
    }
    else if(strcmp(opcode,"1100111")==0)
    {
        result=disassemble_with_jalrInst(arr,instruction,result);
    }
    else
    {
        result="unknown instruction";
    }

    // free(opcode);
    // free(instruction);
    // free(imm);

    return result;
}


char* disassemble_with_rType(int* arr, char* instruction, char* result)
{
    char* rd=convert_binary_to_decimal(slice_array(arr,7,12));
    char* rs1=convert_binary_to_decimal(slice_array(arr,15, 20));
    char* rs2=convert_binary_to_decimal(slice_array(arr,20, 25));
    char* funct3=slice_array(arr,12, 15);
    char* funct7=slice_array(arr,25, 32);

    if (strcmp(funct3,"000")==0)
    {
        if (strcmp(funct7,"0000000")==0)
        {
            instruction="add";
            simulate_add_instruction(rd, rs1, rs2);
        } 
        else if (strcmp(funct7,"0100000")==0)
        {
            instruction="sub";
            simulate_sub_instruction(rd, rs1, rs2);
        }
    }
    else if (strcmp(funct3,"100")==0)
    {
        instruction="xor";
        simulate_xor_instruction(rd, rs1, rs2);
    }   
    else if (strcmp(funct3,"110")==0)
    {
        instruction="or";
        simulate_or_instruction(rd, rs1, rs2);
    } 
    else if (strcmp(funct3,"111")==0)
    {
        instruction="and";
        simulate_and_instruction(rd, rs1, rs2);
    } 
    //shift operation
    else if (strcmp(funct3,"001")==0)
    {
        instruction="sll";
        simulate_sll_instruction(rd, rs1, rs2);
    }
        
    else if (strcmp(funct3,"010")==0)
    {
        instruction="slt";
        simulate_slt_instruction(rd, rs1, rs2);
    }
        
    else if (strcmp(funct3,"101")==0)
    {
        if (strcmp(funct7,"0000000")==0)
        {
            instruction="srl";
            simulate_srl_instruction(rd, rs1, rs2);
        }
        else if (strcmp(funct7,"0100000")==0)
        {
            instruction="sra";
            simulate_sra_instruction(rd, rs1, rs2);
        }
            
    }
    // rType order: ins rd, rs1, rs2
    sprintf(result,"%s x%s, x%s, x%s",instruction,rd, rs1, rs2);

    return result;
}


char* disassemble_with_iType(int* arr, char* instruction, char* result)
{
    char* rd=convert_binary_to_decimal(slice_array(arr,7, 12));
    char* funct3=slice_array(arr,12, 15);
    char* rs1=convert_binary_to_decimal(slice_array(arr,15, 20));
    char* imm;
    char* funct7;

    if (strcmp(funct3,"010")==0)
    {
        instruction="slti";
        imm=convert_binary_to_decimal_imm(slice_array(arr,20, 32));
        simulate_slti_instruction(rd, rs1, imm);
    }
    else if (strcmp(funct3,"000")==0)
    {
        instruction="addi";
        imm=convert_binary_to_decimal_imm(slice_array(arr,20, 32));
        simulate_addi_instruction(rd, rs1, imm);
    }
    else if (strcmp(funct3,"111")==0)
    {
        instruction="andi";
        imm=convert_binary_to_decimal_imm(slice_array(arr,20, 32));
        simulate_andi_instruction(rd, rs1, imm);
    }
    else if (strcmp(funct3,"100")==0)
    {
        instruction="xori";
        imm=convert_binary_to_decimal_imm(slice_array(arr,20, 32));
        simulate_xori_instruction(rd, rs1, imm);
    }
    else if (strcmp(funct3,"110")==0)
    {
        instruction="ori";
        imm=convert_binary_to_decimal_imm(slice_array(arr,20, 32));
        simulate_ori_instruction(rd, rs1, imm);
    }
    //having shamt
    if (strcmp(funct3,"001")==0)
    {
        imm=convert_binary_to_decimal(slice_array(arr,20, 25)); //imm==shamt
        funct7=slice_array(arr,25, 32);
        instruction="slli";
        simulate_slli_instruction(rd, rs1, imm);
    } 
    else if (strcmp(funct3,"101")==0)
    {
        imm=convert_binary_to_decimal(slice_array(arr,20, 25)); //imm==shamt
        funct7=slice_array(arr,25, 32);
        if (strcmp(funct7,"0000000")==0)
        {
            instruction="srli";
            simulate_srli_instruction(rd, rs1, imm);
        }  
        else if (strcmp(funct7,"0100000")==0)
        {
            instruction="srai";   
            simulate_srai_instruction(rd, rs1, imm);
        }
             
    }
    //iType order: ins rd, rs1, imm12
    //iType order: ins rd, rs1, imm5(shamt)
    sprintf(result,"%s x%s, x%s, %s",instruction,rd, rs1, imm);

    return result;
}


char* disassemble_with_iTypeLoad(int* arr, char* instruction, char* result)
{
    char* rd=convert_binary_to_decimal(slice_array(arr,7, 12));
    char* funct3=slice_array(arr,12, 15);
    char* rs1=convert_binary_to_decimal(slice_array(arr,15, 20));
    char* imm=convert_binary_to_decimal_imm(slice_array(arr,20, 32));

    if (strcmp(funct3,"010")==0)
    {
        instruction="lw";
        simulate_lw_instruction(rd, imm, rs1);
    }

    //iTyleLoad order: ins rd, imm12(rs1)
    sprintf(result,"%s x%s, %s(x%s)",instruction,rd, imm, rs1);

    return result;
}


char* disassemble_with_sType(int* arr, char* instruction, char* result, char* imm)
{
    char* immFirst=slice_array(arr,7, 12);
    char* funct3=slice_array(arr,12, 15);
    char* rs1=convert_binary_to_decimal(slice_array(arr,15, 20));
    char* rs2=convert_binary_to_decimal(slice_array(arr,20, 25));
    char* immSecond=slice_array(arr,25, 32);

    //combind immediate
    sprintf(imm, "%s%s",immSecond,immFirst);
    imm=convert_binary_to_decimal_imm(imm);

    if (strcmp(funct3,"010")==0)
    {
        instruction="sw";
        simulate_sw_instruction(rs2, imm, rs1);
    }

    //sType order: ins rs2, imm12(rs1)
    sprintf(result,"%s x%s, %s(x%s)",instruction, rs2, imm, rs1);

    return result;
}

char* disassemble_with_sbType(int* arr, char* instruction, char* result,char* imm)
{
    char* immThird=slice_array(arr,7, 8);
    char* immFirst=slice_array(arr,8, 12);
    char* funct3=slice_array(arr,12, 15);
    char* rs1=convert_binary_to_decimal(slice_array(arr,15, 20));
    char* rs2=convert_binary_to_decimal(slice_array(arr,20, 25));
    char* immSecond=slice_array(arr,25, 31);
    char* immLast=slice_array(arr,31, 32);

    //combind immediate, index[0]==0
    // sprintf(imm, "%s%s%s%s%s",immLast,immSecond,immFirst,immThird,"0");
    sprintf(imm, "%s%s%s%s%s",immLast,immThird,immSecond,immFirst,"0");
    imm=convert_binary_to_decimal_imm(imm);

    if (strcmp(funct3,"000")==0)
    {
        instruction="beq";
        simulate_beq_instruction(rs1, rs2, imm);
    }
        
    else if (strcmp(funct3,"001")==0)
    {
        instruction="bne";
        simulate_bne_instruction(rs1, rs2, imm);
    }
    else if (strcmp(funct3,"100")==0)
    {
        instruction="blt";
        simulate_blt_instruction(rs1, rs2, imm);
    }
        
    else if (strcmp(funct3,"101")==0)
    {
        instruction="bge";
        simulate_bge_instruction(rs1, rs2, imm);
    }
     
    //sbType order: ins rs1, rs2, imm13
    sprintf(result,"%s x%s, x%s, %s",instruction,rs1, rs2, imm);
    
    return result;
}

char* disassemble_with_luiInst(int* arr, char* instruction, char* result, char* imm)
{
    instruction="lui";
    char* rd=convert_binary_to_decimal(slice_array(arr,7, 12));
    imm=slice_array(arr,12, 32);

    sprintf(imm, "%s%s",imm,"000000000000");
    imm=convert_binary_to_decimal_imm(imm);
    simulate_lui_instruction(rd, imm);

    //luiIns order: ins rd, imm20
    sprintf(result,"%s x%s, %s",instruction,rd, imm);

    return result;
}

char* disassemble_with_auipcInst(int* arr, char* instruction, char* result, char* imm)
{
    instruction="auipc";
    char* rd=convert_binary_to_decimal(slice_array(arr,7, 12));
    imm=slice_array(arr,12, 32);

    sprintf(imm, "%s%s",imm, "000000000000");
    imm=convert_binary_to_decimal_imm(imm);
    simulate_auipc_instruction(rd, imm);

    //auipcIns order: ins rd, imm20
    sprintf(result,"%s x%s, %s",instruction,rd, imm);

    return result;
}

char* disassemble_with_jalInst(int* arr, char* instruction, char* result, char* imm)
{
    instruction="jal";
    char* rd=convert_binary_to_decimal(slice_array(arr,7, 12));
    char* immThird=slice_array(arr,12, 20);
    char* immSecond=slice_array(arr,20, 21);
    char* immFirst=slice_array(arr,21, 31);
    char* immLast=slice_array(arr,31, 32);

    //combine immediate
    sprintf(imm, "%s%s%s%s%s",immLast,immThird,immSecond,immFirst,"0");
    imm=convert_binary_to_decimal_imm(imm); 
    simulate_jal_instruction(rd, imm);

    //jalIns order: ins rd, imm21
    sprintf(result,"%s x%s, %s",instruction, rd, imm);

    return result;
}

char* disassemble_with_jalrInst(int* arr, char* instruction, char* result)
{
    instruction="jalr";
    char* rd=convert_binary_to_decimal(slice_array(arr,7, 12));
    char* funct3=slice_array(arr,12, 15);
    char* rs1=convert_binary_to_decimal(slice_array(arr,15, 20));
    char* imm=convert_binary_to_decimal_imm(slice_array(arr,20, 32));
    simulate_jalr_instruction(rd, imm, rs1);

    //jalrIns order: ins, rd, rs1, imm12
    sprintf(result, "%s x%s, %s(x%s)",instruction,rd,imm,rs1);

    return result;
}
