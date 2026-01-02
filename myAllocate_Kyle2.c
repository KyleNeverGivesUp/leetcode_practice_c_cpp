#include <stdio.h>
#include <sys/mman.h>
#include <stdint.h>

#define HEAP_SIZE 400
#define VAL_SIZE 8

uint64_t* HEAP_START = NULL;

void init_heap(){
    uint64_t* heap = mmap(NULL, HEAP_SIZE, PROT_WRITE | PROT_READ, MAP_SHARED | MAP_ANON, -1, 0);
    HEAP_START = heap;
    *HEAP_START = HEAP_SIZE - VAL_SIZE;
}

void* my_malloc(size_t size){
    uint64_t* current = HEAP_START;
    while(current < HEAP_START + ( HEAP_SIZE / VAL_SIZE)){
        uint64_t curr_header = *current;
        uint64_t curr_size = (curr_header / 2) * 2;
        if ((curr_header %2 == 0) && (curr_size > size)){
            size_t rounded = ((size + 7 ) / 8) * 8;
            *current = rounded + 1;
            uint64_t remaining = curr_size - (rounded + VAL_SIZE);
            uint64_t* remaining_ptr = current + (rounded / VAL_SIZE) + 1;
            *remaining_ptr = remaining;
            return current+1;
        }else{
            uint64_t* next = current + (curr_size / VAL_SIZE) + 1;
            current = next;
        }
    }
    return NULL;
}

void my_free(void* p){
    uint64_t* current = p;
    uint64_t* curr_header = current - 1;
    if (*curr_header %2 == 1){
        *curr_header = * curr_header - 1;
    }
}

void print_heap(){
    uint64_t* current = HEAP_START;
    while(current < HEAP_START + (HEAP_SIZE / VAL_SIZE)){
        uint64_t curr_header = *current;
        uint64_t curr_size = (curr_header / 2) * 2;
        printf("%p %llu %llu\n", current, curr_header % 2, curr_size);
        uint64_t* next = current + (curr_size / VAL_SIZE) + 1;
        current = next;
    }
    printf("\n\n");
}

int main(){
    init_heap();
    uint64_t* m1 = my_malloc(40);
    // printf("%llu %llu %llu\n", HEAP_START[0], HEAP_START[1], HEAP_START[6]);
    print_heap();
    uint64_t* m2 = my_malloc(10);
    print_heap();
    // my_free(m2);
    // uint64_t* m3 = my_malloc(32);
    // print_heap();
    // printf("%llu %llu %llu\n", HEAP_START[0], HEAP_START[1], HEAP_START[6]);
}