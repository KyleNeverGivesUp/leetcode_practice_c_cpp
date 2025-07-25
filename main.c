#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

int main(){
    // 栈分配方式
    slist scores = {NULL, NULL};  // 直接初始化，不需要 malloc
    
    add_to_head(&scores, 1);      // 传递地址
    add_to_head(&scores, 2);
    add_to_head(&scores, 3);
    print_list(&scores);          // 传递地址
    
    // 不需要 free()，函数结束时自动销毁
    return 0;
}