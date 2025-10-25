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

int main(){
    slist scores;
    scores.head = malloc(sizeof(struct node));
    scores.head->data = 1;
    scores.head->next = NULL;
    scores.tail = scores.head;

    // create a new node and insert into at head
    struct node* new_node = malloc(sizeof(struct node));
    new_node->data =2;
    new_node->next = scores.head;
    scores.head = new_node;

    struct node* tmp = scores.head;
    while (tmp != NULL){
        printf("tmp->data = %d\n", tmp->data);
        tmp = tmp->next;
    }
}

