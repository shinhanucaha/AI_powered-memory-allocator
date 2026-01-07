#include<stdio.h>

FILE *fl = fopen("logger.csv",'a') ;

fprintf(fl , logged_data) ;

fclose() ;

logged_data = =//(so i need logged data in string format )
what the kernal or os provides data in which form and what he command i need to get that data how i am going to make it a string data so that i can use it here 


































//logger.c file
#include <stdio.h>
#include "logger.h"

static FILE* log_file = NULL;

void init_logger(const char* filename) {
    log_file = fopen(filename, "w");
    if (log_file) {
        fprintf(log_file, "Action,Size,Pointer\n");
    }
}

void log_allocation(size_t size, void* ptr) {
    if (log_file) {
        fprintf(log_file, "ALLOC,%zu,%p\n", size, ptr);
    }
}

void log_free(void* ptr) {
    if (log_file) {
        fprintf(log_file, "FREE,0,%p\n", ptr);
    }
}

void close_logger() {
    if (log_file) {
        fclose(log_file);
    }
}
//logger.h file
#ifndef LOGGER_H
#define LOGGER_H

#include <stddef.h>

void init_logger(const char* filename);
void log_allocation(size_t size, void* ptr);
void log_free(void* ptr);
void close_logger();

#endif


//main file
#include "logger.h"

int main() {
    init_logger("data/alloc_log.csv");

    int* a = (int*)my_malloc(10 * sizeof(int));
    double* b = (double*)my_malloc(5 * sizeof(double));
    my_free(a);
    char* c = (char*)my_malloc(20);

    print_memory_blocks();

    close_logger();
    return 0;
}
