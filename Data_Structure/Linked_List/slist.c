#include <stdio.h>
#include <stdlib.h>
#include "slist.h"

void add_to_head(slist* slist, int data) {
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data = data;
    new_node->next = NULL;
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