#include <stdio.h>
#include <stdlib.h>

void func(int* x){
    printf("parameter x's address:%p\n ", x);
    printf("int x value is:%d\n", *x);
    *x = 999;
    printf("parameter x's address:%p\n ", x);
    printf("int x value is:%d\n", *x);
}


int main(){
    int p=123;
    printf("size of %d\t:\n", sizeof(p));
    printf("int p pointer:%p\n", &p);
    printf("int p value is:%d\n", p);
    int *p_array;
    double *d_array;
   // printf("pointer address is: %p, size is %lu\n", p_array, sizeof(p_array));
   // printf("pointer address is: %p\n ", &p_array);
    p_array = malloc(sizeof(int)* 50);
    d_array = malloc(sizeof(double)* 100);
    func(&p);
    printf("int p pointer:%p\n", &p);
    printf("int p value is:%d\n", p);
    return 0;
}
