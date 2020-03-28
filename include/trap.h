// File: trap.h
// Author: Alexander DuPree
// Defines trap functions for the lc3 vm

#ifndef LC3_TRAP
#define LC3_TRAP

#include <stdint.h>

enum // Trap Codes
{
    TRAP_GETC   = 0x20, // Get char from keyboard, no echo
    TRAP_OUT    = 0x21, // Output a character
    TRAP_PUTS   = 0x22, // Output a word string
    TRAP_IN     = 0x23, // Get char from keyboard, echo to terminal
    TRAP_PUTSP  = 0x24, // Output a byte string
    TRAP_HALT   = 0x25  // Halt the program
};

extern void t_puts(uint16_t* c);
extern void t_getc(uint16_t* r0);
extern void t_out(uint16_t* c);
extern void t_in(uint16_t* r0);
extern void t_putsp(uint16_t* c);
extern void t_halt(uint16_t* r0);


#endif  // LC3_TRAP