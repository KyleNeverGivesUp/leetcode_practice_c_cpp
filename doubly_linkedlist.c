#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct doubly_linked_list{
    struct node* head;
    struct node* tail;
};

typedef struct doubly_linked_list dlist;

void add_to_head(dlist* list, int data){
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = list->head;
    new_node->prev = NULL;

    if (list->head != NULL){
        list->head->prev = new_node;
    }

    list->head = new_node;

    if (list->tail == NULL){
        list->tail = new_node;
    }
}

void print_list(dlist* dlist){
    struct node* tmp = dlist->head;
    while (tmp != NULL){
        printf("tmp->data is %d\n", tmp->data);  // 添加 \n
        tmp = tmp->next;
    }
}

void get_prev_node() {
    // 你的函数实现
}

int main(){
    dlist* scores = malloc(sizeof(dlist));
    scores->head = NULL;  // 初始化头指针
    scores->tail = NULL;  // 初始化尾指针
    
    add_to_head(scores, 1);
    add_to_head(scores, 2);
    add_to_head(scores, 3);
    print_list(scores);
    
    // 先释放所有节点
    struct node* current = scores->head;
    while(current != NULL){
        struct node* next = current->next;
        free(current);
        current = next;
    }
    
    // 最后释放链表结构
    free(scores);
    return 0;
}