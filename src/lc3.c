// LC-3 Virtual Machine Emulator

#include <stdio.h>
#include <stdlib.h>

#include "lc3.h"
#include "trap.h"
#include "image.h"
#include "console.h"

// LC3 Registers
uint16_t reg[R_COUNT];
// 16 Bit memory address space
uint16_t memory[UINT16_MAX];

uint16_t RUNNING;

/**********************************
* UTILITY FUNCTIONS
**********************************/
void update_flags(uint16_t r)
{
    if(reg[r] == 0)
    {
        reg[R_COND] = FL_ZRO;
    }
    else if(reg[r] >> 15) // 1 in the most significant bit denotes negative
    {
        reg[R_COND] = FL_NEG;
    }
    else
    {
        reg[R_COND] = FL_POS;
    }
}

uint16_t sign_extend(uint16_t n, int bits)
{
    if((n >> (bits - 1)) & 1) {
        n |= (0xFFFF << bits);
    }
    return n;
}

void mem_write(uint16_t address, uint16_t val)
{
    memory[address] = val;
}

uint16_t mem_read(uint16_t address)
{
    if(address == MR_KBSR)
    {
        if(check_key())
        {
            memory[MR_KBSR] = (1 << 15);
            memory[MR_KBDR] = getchar();
        }
        else
        {
            memory[MR_KBSR] = 0;
        }
    }
    return memory[address];
}

/**********************************
* INSTRUCTION SET
**********************************/

void branch(uint16_t instr)
{
    // PCoffset 9
    uint16_t pc_offset = sign_extend(instr & PC_OFFSET_MASK, 9);
    uint16_t cond_flag = (instr >> 9) & 0x7;

    if(cond_flag & reg[R_COND])
    {
        reg[R_PC] += pc_offset;
    }
}

void add(uint16_t instr)
{
    // dest register
    uint16_t r0 = (instr >> DR_SHIFT) & REG_MASK;
    // First Operand, source register 1
    uint16_t r1 = (instr >> SR_SHIFT) & REG_MASK;

    uint16_t imm_flag = (instr >> FLG_SHIFT) & 0x1;

    // Second Operand, depends on immediate flag
    uint16_t rhs = (imm_flag) ? sign_extend(instr & IMM5_MASK, 5)
                              : reg[instr & REG_MASK];

    // Store Computation into r0
    reg[r0] = reg[r1] + rhs;

    update_flags(r0);
}

void load(uint16_t instr)
{
    // Dest Register
    uint16_t r0 = (instr >> DR_SHIFT) & REG_MASK;
    // PCoffset9
    uint16_t pc_offset = sign_extend(instr & PC_OFFSET_MASK, 9);

    reg[r0] = mem_read(reg[R_PC] + pc_offset);

    update_flags(r0);
}

void store(uint16_t instr)
{
    // Source Register
    uint16_t r0 = (instr >> DR_SHIFT) & REG_MASK;

    // PCoffset9
    uint16_t pc_offset = sign_extend(instr & PC_OFFSET_MASK, 9);

    mem_write(reg[R_PC] + pc_offset, reg[r0]);
}

void jump_subroutine(uint16_t instr)
{
    // Store Return address
    reg[R_R7] = reg[R_PC];

    if((instr >> JSR_SHIFT) & 0x1) // JSR
    {
        reg[R_PC] += sign_extend(instr & LPC_OFFSET_MASK, 11);
    }
    else // JSRR
    {
        uint16_t base_r = (instr >> BASE_REG_SHIFT) & REG_MASK;
        reg[R_PC] = reg[base_r];
    }
    return;
}

void bitwise_and(uint16_t instr)
{
    // dest register
    uint16_t r0 = (instr >> DR_SHIFT) & REG_MASK;
    // First Operand, source register 1
    uint16_t r1 = (instr >> SR_SHIFT) & REG_MASK;

    uint16_t imm_flag = (instr >> FLG_SHIFT) & 0x1;

    // Second Operand, depends on immediate flag
    uint16_t rhs = (imm_flag) ? sign_extend(instr & IMM5_MASK, 5)
                              : reg[instr & REG_MASK];

    // Store Computation into r0
    reg[r0] = reg[r1] & rhs;

    update_flags(r0);
}

void load_register(uint16_t instr)
{
    // Dest Register
    uint16_t r0 = (instr >> DR_SHIFT) & REG_MASK;
    uint16_t base_r = (instr >> BASE_REG_SHIFT) & REG_MASK;
    uint16_t pc_offset = sign_extend(instr & SPC_OFFSET_MASK, 6);

    reg[r0] = mem_read(reg[base_r] + pc_offset);
    update_flags(r0);
}

void store_register(uint16_t instr)
{
    // Source Register
    uint16_t r0 = (instr >> DR_SHIFT) & REG_MASK;
    uint16_t base_r = (instr >> BASE_REG_SHIFT) & REG_MASK;
    uint16_t offset = sign_extend(instr & SPC_OFFSET_MASK, 6);

    mem_write(reg[base_r] + offset, reg[r0]);
}

void rti(uint16_t instr)
{
    abort();
}

void res(uint16_t instr)
{
    abort();
}

void bitwise_not(uint16_t instr)
{
    uint16_t r0 = (instr >> DR_SHIFT) & REG_MASK;
    uint16_t r1 = (instr >> SR_SHIFT) & REG_MASK;

    reg[r0] = ~reg[r1];
    update_flags(r0);
}

void load_indirect(uint16_t instr)
{
    // Dest Register
    uint16_t r0 = (instr >> DR_SHIFT) & REG_MASK;
    // PCoffset 9
    uint16_t pc_offset = sign_extend(instr & PC_OFFSET_MASK, 9);

    reg[r0] = mem_read(mem_read(reg[R_PC] + pc_offset));
    update_flags(r0);
}

void store_indirect(uint16_t instr)
{
    // Source Register
    uint16_t r0 = (instr >> DR_SHIFT) & REG_MASK;
    // PCoffset 9
    uint16_t pc_offset = sign_extend(instr & PC_OFFSET_MASK, 9);

    mem_write(mem_read(reg[R_PC] + pc_offset), reg[r0]);
}

void jump(uint16_t instr)
{
    uint16_t base_r = (instr >> BASE_REG_SHIFT) & REG_MASK;

    reg[R_PC] = reg[base_r];
}

void load_effective_address(uint16_t instr)
{
    uint16_t r0 = (instr >> DR_SHIFT) & REG_MASK;
    uint16_t pc_offset = sign_extend(instr & PC_OFFSET_MASK, 9);

    reg[r0] = reg[R_PC] + pc_offset;
    update_flags(r0);
}

void trap(uint16_t instr)
{
    // Execute trap instruction
    switch (instr & TRAP_MASK)
    {
    case TRAP_GETC :
        t_getc(reg + R_R0);
        break;
    case TRAP_OUT : 
        t_out(reg + R_R0);
        break;
    case TRAP_PUTS : 
        t_puts(memory + reg[R_R0]);
        break;
    case TRAP_IN : 
        t_in(reg + R_R0);
        break;
    case TRAP_PUTSP :
        t_putsp(memory + reg[R_R0]);
        break;
    case TRAP_HALT :
        t_halt(&RUNNING);
        break;
    default:
        printf("lc3-FATAL: Bad Trap");
        break;
    }
}

// Instruction set jump table
static void(*ops[])(uint16_t) = {
    [OP_BR]     branch,
    [OP_ADD]    add,
    [OP_LD]     load,
    [OP_ST]     store,
    [OP_JSR]    jump_subroutine,
    [OP_AND]    bitwise_and,
    [OP_LDR]    load_register,
    [OP_STR]    store_register,
    [OP_RTI]    rti,
    [OP_NOT]    bitwise_not,
    [OP_LDI]    load_indirect,
    [OP_STI]    store_indirect,
    [OP_JMP]    jump,
    [OP_RES]    res,
    [OP_LEA]    load_effective_address,
    [OP_TRAP]   trap
};

void help()
{
    printf("usage: lc3 [image-file1] ...\n");
}

int main(int argc, const char* argv[])
{
    // Load Arguments
    if(argc < 2)
    {
        help();
        exit(2);
    }

    for (int i = 1; i < argc; ++i)
    {
        if(!read_image(argv[i], memory))
        {
            printf("lc3-FATAL: failed to load image: %s\n", argv[i]);
            exit(1);
        }
    }

    // Setup
    console_setup();

    // Set PC to start, 0x3000 is the default
    reg[R_PC] = PC_START;

    RUNNING = 1;
    while(RUNNING)
    {
        // Fetch instruction, and increment PC
        uint16_t instruction = mem_read(reg[R_PC]++);
        uint16_t op_code = instruction >> OP_SHIFT;

        // Execute instruction
        if(op_code < OP_COUNT)
        {
            ops[op_code](instruction);
        }
        else
        {
            printf("lc3-FATAL: Bad opcode: %d", op_code);
            exit(2);
        }
    }

    // Shutdown
    console_teardown();
}