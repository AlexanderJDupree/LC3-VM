// File: lc3.h

#ifndef LC3_VM
#define LC3_VM

#include <stdint.h>

/**********************************
* DEFINITIONS/GLOBAL 
**********************************/

enum // Registers
{
    R_R0 = 0,
    R_R1,
    R_R2, 
    R_R3,
    R_R4,
    R_R5,
    R_R6,
    R_R7,
    R_PC,   // Program Counter
    R_COND,
    R_COUNT
};

enum // Instruction Set
{
    OP_BR = 0,  // branch
    OP_ADD,     // add
    OP_LD,      // load
    OP_ST,      // store
    OP_JSR,     // jump to sub-routine
    OP_AND,     // bitwise and
    OP_LDR,     // load register
    OP_STR,     // store register
    OP_RTI,     // return from interrupt
    OP_NOT,     // bitwise not
    OP_LDI,     // load indirect
    OP_STI,     // store indirect
    OP_JMP,     // jump
    OP_RES,     // reserved
    OP_LEA,     // load effective address
    OP_TRAP,    // execute trap
    OP_COUNT
};

enum // Condition Flags
{
    FL_POS = 1 << 0, // P
    FL_ZRO = 1 << 1, // Z
    FL_NEG = 1 << 2, // N
};

enum // Memory Mapped Registers
{
    MR_KBSR = 0xFE00, // Keyboard Status
    MR_KBDR = 0xFE02 // Keyboard Data
};


#define PC_START 0x3000

#define REG_MASK 0x7
#define IMM5_MASK 0x1F
#define TRAP_MASK 0xFF
#define PC_OFFSET_MASK 0x1FF
#define LPC_OFFSET_MASK 0x7FF
#define SPC_OFFSET_MASK 0x3F

#define DR_SHIFT 9
#define SR_SHIFT 6
#define OP_SHIFT 12
#define FLG_SHIFT 5
#define JSR_SHIFT 11
#define BASE_REG_SHIFT 6

#endif // LC3_VM
