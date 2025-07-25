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

void add_to_head(dlist* dlist, int data){
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = dlist->head;
    new_node->prev = NULL;

    if (dlist->head != NULL){
        
    }
    
    dlist->head = new_node;
}