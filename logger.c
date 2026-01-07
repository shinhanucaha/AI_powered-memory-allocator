#include <stdio.h>
#include "logger.h"

void log_alloc(size_t size) {
    FILE* f = fopen("data/alloc_log.csv", "a");
    if (f) {
        fprintf(f, "ALLOC,%zu\n", size);
        fclose(f);
    }
}

void log_free(void) {
    FILE* f = fopen("data/alloc_log.csv", "a");
    if (f) {
        fprintf(f, "FREE\n");
        fclose(f);
    }
}
