// rType order: ins rd, rs1, rs2
void simulate_add_instruction(char* instruction, char* rd, char* rs1, char* rs2);
void simulate_sub_instruction(char* instruction, char* rd, char* rs1, char* rs2);
void simulate_xor_instruction(char* instruction, char* rd, char* rs1, char* rs2);
void simulate_or_instruction(char* instruction, char* rd, char* rs1, char* rs2);
void simulate_and_instruction(char* instruction, char* rd, char* rs1, char* rs2);
//shift operation
void simulate_sll_instruction(char* instruction, char* rd, char* rs1, char* rs2);
void simulate_slt_instruction(char* instruction, char* rd, char* rs1, char* rs2);
void simulate_srl_instruction(char* instruction, char* rd, char* rs1, char* rs2);
void simulate_sra_instruction(char* instruction, char* rd, char* rs1, char* rs2);

//iType order: ins rd, rs1, imm12
void simulate_slti_instruction(char* instruction, char* rd, char* rs1, char* imm12);
void simulate_addi_instruction(char* instruction, char* rd, char* rs1, char* imm12);
void simulate_andi_instruction(char* instruction, char* rd, char* rs1, char* imm12);
void simulate_xori_instruction(char* instruction, char* rd, char* rs1, char* imm12);
void simulate_ori_instruction(char* instruction, char* rd, char* rs1, char* imm12);
//iType order: ins rd, rs1, imm5(shamt)
void simulate_slli_instruction(char* instruction, char* rd, char* rs1, char* imm5);
void simulate_srli_instruction(char* instruction, char* rd, char* rs1, char* imm12);
void simulate_srai_instruction(char* instruction, char* rd, char* rs1, char* imm12);

//iTyleLoad order: ins rd, imm12(rs1)
void simulate_lw_instruction(char* instruction, char* rd, char* imm, char* rs1);

//sType order: ins rs2, imm12(rs1)
void simulate_sw_instruction(char* instruction, char* rs2, char* imm12, char* rs1);

//sbType order: ins rs1, rs2, imm13
void simulate_beq_instruction(char* instruction, char* rs1, char* rs2, char* imm13);
void simulate_bne_instruction(char* instruction, char* rs1, char* rs2, char* imm13);
void simulate_blt_instruction(char* instruction, char* rs1, char* rs2, char* imm13);
void simulate_bge_instruction(char* instruction, char* rs1, char* rs2, char* imm13);

//luiIns order: ins rd, imm20
void simulate_lui_instruction(char* instruction, char* rd, char* imm20);

//auipcIns order: ins rd, imm20
void simulate_auipc_instruction(char* insturction, char* rd, char* imm20);

//jalIns order: ins rd, imm21
void simulate_jal_instruction(char* insturction, char* rd, char* imm21);

//jalrIns order: ins, rd, rs1, imm12
void simulate_jalr_instruction(char* instruction, char* rd, char* rs1, char* rs2);
