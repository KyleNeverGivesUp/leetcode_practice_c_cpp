#include <stdio.h>
#include <stdint.h>
#include <sys/mman.h>
// #include <stdlib.h>

#define HEAP_SIZE 400
#define VAL_SIZE 8

uint64_t* HEAP_START = NULL;

void init_heap(){
    uint64_t* heap = mmap(NULL, HEAP_SIZE, PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANON ,-1, 0);
    HEAP_START = heap;
    *HEAP_START = HEAP_SIZE - VAL_SIZE;
}

void* my_malloc(size_t size){
    uint64_t* current = HEAP_START;
    // check if the current point is over the whole heap that we've got
    while (current < HEAP_START + (HEAP_SIZE / VAL_SIZE)){
        // define the cur_header_size
        uint64_t cur_header = *current;
        // Get the pure size without LSB 3 digits
        uint64_t cur_size = (cur_header / 2) * 2;
        // if cur block is bigger than the required size and it is available
        if ((cur_size >= size) && (cur_header % 2 == 0)){
            // align the required size
            uint64_t rounded = ((size + 7) / 8) * 8;
            // set the used indicator to the block
            *current = rounded + 1;
            // get the remaining size of our whole memory size
            size_t remaining = cur_size - (rounded + VAL_SIZE);
            // point to the next block
            uint64_t* remaining_ptr = current + (rounded / VAL_SIZE) + 1;
            // set the size of the next block
            *remaining_ptr = remaining;
            // return the address that the user can use directly
            return current + 1;
        }else{
            uint64_t* next = current + cur_size;
            current = next;
        }
    }
    return NULL;
}

void print_heap(){
    uint64_t* current = HEAP_START;
    while(current < HEAP_START + (HEAP_SIZE / VAL_SIZE)){
        uint64_t cur_header = *current;
        uint64_t cur_size = (cur_header / 2) * 2;
        printf("%p\t%llu\t%llu\n", current, cur_header % 2, cur_size);
        uint64_t* next = current + (cur_size / VAL_SIZE) + 1;
        current = next;
    }
    printf("\n\n");
}

void my_free(void* p){
    uint64_t* current = p;
    uint64_t* cur_header = current - 1;
    if (*cur_header % 2 == 1){
        *cur_header = *cur_header - 1;
    }
}

int main(){
    printf("god\n");
    init_heap();
    int* a = my_malloc(40);
    // printf("%llu %llu %llu\n", HEAP_START[0], HEAP_START[1], HEAP_START[6]);
    print_heap();
    int* b = my_malloc(10);
    print_heap();

    my_free(b);
    // printf("%llu %llu\n", HEAP_START[6], HEAP_START[9]);
    int* c = my_malloc(32);
    print_heap();
    
}