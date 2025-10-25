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
        printf("tmp->data is %d\n", tmp->data);
        tmp = tmp->next;
    }
}

void printf_reverse_list(dlist* dlist) {
    struct node* last = dlist->tail;
    while (last != NULL){
        printf("last->data=%d\n", last->data);  // 打印当前节点的数据
        last = last->prev;                      // 移动到前一个节点
    }
}

int main(){
    dlist* scores = malloc(sizeof(dlist));
    scores->head = NULL;  // 初始化头指针
    scores->tail = NULL;  // 初始化尾指针
    
    add_to_head(scores, 1);
    add_to_head(scores, 2);
    add_to_head(scores, 3);
    // print_list(scores);
    printf_reverse_list(scores);
    
    // Free the memroy of nodes.
    struct node* current = scores->head;
    while(current != NULL){
        struct node* next = current->next;
        free(current);
        current = next;
    }
    
    // Free the memory of linkedlist.
    free(scores);
    return 0;
}