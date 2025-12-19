#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/mman.h>

#define HEAP_START 400
#define VAL_SIZE 8

uint64_t* HEAP_START = NULL;

void init_heap(){
    // mmap, it gets heap memory return from OS system call
    // NULL means make it start as close to the beginning of the heap as possible.
    unint64_t* heap = mmap(NULL, HEAP_SIZE, PORT_READ | PORT_WRITE, MAP_ANON | MAP_SHARED, -1, 0);

    HEAP_START = heap;

    *HEAP_START = HEAP_SIZE - VAL_SIZE;
}

void* my_malloc(size_t size){

}

int main(){
    init_heap();
 /*   int* a = malloc(40);
    int* b = malloc(10);
    */
}