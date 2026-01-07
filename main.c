#include <stdio.h>
#include "allocator.h"
#include "logger.h"

int main() {
    my_malloc(32);  log_alloc(32);
    my_malloc(64);  log_alloc(64);
    my_malloc(128); log_alloc(128);
    my_free(NULL);  log_free();

    my_malloc(64);  log_alloc(64);
    my_malloc(32);  log_alloc(32);

    print_memory_blocks();
    return 0;
}
