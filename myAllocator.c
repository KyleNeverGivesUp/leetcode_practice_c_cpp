#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/mman.h>
#include <unistd.h>

#define HEAP_SIZE 400
#define VAL_SIZE 8

uint64_t* HEAP_START = NULL;

void init_heap(){
    // mmap, it gets heap memory return from OS system call
    // NULL means make it start as close to the beginning of the heap as possible.
    uint64_t* heap = mmap(NULL, HEAP_SIZE, PROT_READ | PROT_WRITE, MAP_ANON | MAP_SHARED, -1, 0);

    HEAP_START = heap;

    *HEAP_START = HEAP_SIZE - VAL_SIZE;
}

void* my_malloc(size_t size){
    uint64_t* current = HEAP_START;
    while(current < (HEAP_START + (HEAP_SIZE / VAL_SIZE))){
        uint64_t cur_header = *current;
        uint64_t cur_size = (cur_header / 2) * 2;  // calc the actual size
        // want to know the size and is it free
        if((cur_header % 2 == 0) && (size <= cur_size)){  //check if free
            // split up the block into the malloc'd part and the free part
            // Round up size to next multiple 8
            size_t rounded = ((size + 7) / 8) * 8;
            *current = rounded + 1;  // sets the "busy" bit

            size_t remaining = cur_size - (rounded + VAL_SIZE); // VAL_SIZE is room for new block header
            uint64_t* remaining_ptr = current + (rounded / VAL_SIZE) + 1;  // 1 is for the header
            *remaining_ptr = remaining;
            return current + 1;
        }
        else{
            uint64_t* next = current + (cur_size / VAL_SIZE) + 1;
            current = next;
        }
    }
    return NULL;
}

int main(){
    init_heap();
    // printf("%llu\n", *HEAP_START);
    // ((size + 7) / 8) * 8;
    int* a = my_malloc(40);
    // int* b = malloc(10);
    printf("%llu %llu %llu\n", HEAP_START[0], HEAP_START[1], HEAP_START[6]);
    // printf("%d\n", getpagesize());
    
    
    
    return 0;
}