#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct singly_linked_list {
    struct node* head;
    struct node* tail;
};

typedef struct singly_linked_list slist;

void add_to_head(slist* slist, struct node* new_node) {
    if (slist->head == NULL){
        slist->head = new_node;
        slist->tail = new_node;
    }
    else {
        new_node->next = slist->head;
        slist->head = new_node;
    }
}

void print_list(slist* slist) {
    struct node* tmp = slist->head;
    while (tmp != NULL) {
        printf("tmp->data = %d\n", tmp->data);
        tmp = tmp->next;
    }
}

int main(){
    slist* scores = malloc(sizeof(slist));  // 为 scores 分配内存
    scores->head = NULL;
    scores->tail = NULL;

    struct node* new_node1 = malloc(sizeof(struct node));
    struct node* new_node2 = malloc(sizeof(struct node));
    struct node* new_node3 = malloc(sizeof(struct node));
    new_node1->data = 1;
    new_node2->data = 2;
    new_node3->data = 3;
    add_to_head(scores, new_node1);
    add_to_head(scores, new_node2);
    add_to_head(scores, new_node3);
    print_list(scores);
    
    return 0;
}