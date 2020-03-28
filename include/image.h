// File: image.h

#ifndef LC3_IMAGE
#define LC3_IMAGE

#include <stdint.h>

// Read lc3 binary into the memory pointed to by mem
int read_image(const char* img, uint16_t* mem);

#endif // LC3_IMAGE