// File: image.c

#include <stdio.h>
#include "image.h"

#define BIG_ENDIAN 0
#define LITTLE_ENDIAN 1
 
int byte_order() {
        short int word = 0x0001;
        char *b = (char *)&word;
        return (b[0] ? LITTLE_ENDIAN : BIG_ENDIAN);
}

static uint16_t swap_endian(uint16_t x)
{
    return (x << 8) | (x >> 8);
}

static void read_image_file(FILE* file, uint16_t* memory)
{
    // Origin specifies where to place the image in memory
    uint16_t origin;
    fread(&origin, sizeof(origin), 1, file);

    if(byte_order() == LITTLE_ENDIAN)
    {
        origin = swap_endian(origin); 
    }

    // Can only read 16bit chunks until memory[UINT16_MAX] 
    // and we start at memory[origin]
    uint16_t max_read = UINT16_MAX - origin;
    uint16_t* program = memory + origin;

    size_t read = fread(program, sizeof(uint16_t), max_read, file);

    if(byte_order() == LITTLE_ENDIAN)
    {
        for(; read-- > 0; ++program)
        {
            // Every 16bit instruction read needs to be reversed
            *program = swap_endian(*program);
        }
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