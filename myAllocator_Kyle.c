#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <sys/mman.h>

#define HEAP_SIZE 400
#define VAL_SIZE 8

uint64_t* HEAP_START = NULL;

void init_heap(){
    uint64_t* heap = mmap(NULL, HEAP_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    HEAP_START = heap;
    *HEAP_START = HEAP_SIZE - VAL_SIZE;
}

void* malloc(size_t size){
    uint64_t* current = HEAP_START;
    while (current < (HEAP_START + (HEAP_SIZE / VAL_SIZE))){
        uint64_t cur_header = *current;
        uint64_t cur_size = (cur_header / 2) * 2;
        if ((cur_header % 2 == 0) && (size <= cur_size)){
            size_t rounded = ((size + 7) / 8) * 8;
            *current = rounded + 1;

            size_t remaining = cur_size - (rounded + VAL_SIZE);
            uint64_t* remaining_ptr = current + (rounded / VAL_SIZE) + 1;
            *remaining_ptr = remaining;
            return current + 1;
        }
        else {
            uint64_t* next = current + (cur_size / VAL_SIZE) + 1;
            current = next;
        }
    }
    return NULL;
}

int main(){
    init_heap();
    int* a = malloc(40);
    printf("%llu %llu\n", HEAP_START[0], HEAP_START[1]);
    return 0;
}