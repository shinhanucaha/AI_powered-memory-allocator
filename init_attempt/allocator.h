#ifndef ALLOCATOR_H
#define ALLOCATOR_H

#include <stddef.h>

// Allocate memory
void* my_malloc(size_t size);

// Free allocated memory
void my_free(void* ptr);

// Debug: print current memory blocks
void print_memory_blocks(void);

#endif
