#include <stdio.h>
#include <stdint.h>

uint8_t combine_num(uint8_t num1, uint8_t num2){
   return (num1 & 0xF) << 4 | (num2 & 0xF);
}

int main(int argc, char** argv){
    unsigned char num1 = argv[1][0];
    unsigned char num2 = argv[2][0];
    //printf("%s\n",argv[1]); 
    //printf("%s\n",*argv);
    //printf("%s\n",*(argv+1));
    printf("%d\n", combine_num(num1,num2));
    //printf("%p %p %p %p\n", argv, argv[0], argv[1], argv[2]);
    //printf("%p %p %p %p\n", &argv, &argv[0], &argv[1], &argv[3]);
    //printf("%p %d\n", *argv, **argv);

}
