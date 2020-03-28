// File: image.c

#include <stdio.h>
#include "image.h"

static uint16_t swap_endian(uint16_t x)
{
    return (x << 8) | (x >> 8);
}

static void read_image_file(FILE* file, uint16_t* memory)
{
    // Origin specifies where to place the image in memory
    uint16_t origin;
    fread(&origin, sizeof(origin), 1, file);
    // lc3 is big-endian, we're running a little endian computer
    origin = swap_endian(origin); 

    // Can only read 16bit chunks until memory[UINT16_MAX] 
    // and we start at memory[origin]
    uint16_t max_read = UINT16_MAX - origin;
    uint16_t* program = memory + origin;

    size_t read = fread(program, sizeof(uint16_t), max_read, file);

// TODO Check for endianness first
    for(; read-- > 0; ++program)
    {
        // Every 16bit instruction read needs to be reversed
        *program = swap_endian(*program);
    }
}

int read_image(const char* image, uint16_t* memory)
{
    FILE* file = fopen(image, "rb");

    if(!file) { return 0; }

    read_image_file(file, memory);
    fclose(file);
    return 1;
}