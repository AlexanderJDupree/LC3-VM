// File: trap.c

#include <stdio.h>
#include "trap.h"

void t_puts(uint16_t* c)
{
    while(c && *c)
    {
        putc((char)*c, stdout);
        ++c;
    }
    fflush(stdout);
}

void t_getc(uint16_t* r0)
{
    *r0 = (uint16_t)getchar();
}

void t_out(uint16_t* c)
{
    putc((char)*c, stdout);
    fflush(stdout);
}

void t_in(uint16_t* r0)
{
    t_getc(r0);
    t_out(r0);
}

void t_putsp(uint16_t* c)
{

    /* one char per byte (two bytes per word)
       here we need to swap back to
       big endian format */

    while (*c)
    {
        char char1 = (*c) & 0xFF;
        putc(char1, stdout);
        char char2 = (*c) >> 8;

        if (char2) 
            putc(char2, stdout);
        ++c;
    }
    fflush(stdout);
}

void t_halt(uint16_t* flag)
{
    puts("\nlc3: HALT\n");
    *flag = 0;
}
