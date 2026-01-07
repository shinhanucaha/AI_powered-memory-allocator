#include <stdio.h>
#include <stdlib.h>
#include "allocator.h"

typedef struct block {
    size_t size;
    int free;
    struct block* next;
} Block;

static Block* free_list = NULL;

#define BLOCK_SIZE sizeof(Block)

void* my_malloc(size_t size) {
    Block* curr = free_list;

    while (curr) {
        if (curr->free && curr->size >= size) {
            curr->free = 0;
            return (void*)(curr + 1);
        }
        curr = curr->next;
    }

    Block* new_block = (Block*)malloc(size + BLOCK_SIZE);
    if (!new_block) return NULL;

    new_block->size = size;
    new_block->free = 0;
    new_block->next = free_list;
    free_list = new_block;

    return (void*)(new_block + 1);
}

void my_free(void* ptr) {
    if (!ptr) return;
    Block* block = (Block*)ptr - 1;
    block->free = 1;
}

void print_memory_blocks(void) {
    Block* curr = free_list;
    printf("Memory Blocks:\n");
    while (curr) {
        printf("[Size: %zu | Free: %d]\n", curr->size, curr->free);
        curr = curr->next;
    }
}
