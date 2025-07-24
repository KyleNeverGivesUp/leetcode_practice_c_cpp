#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

int main(){
    struct node* head = calloc(1, sizeof(struct node));
    struct node* tail = NULL;
    head->data = 1;
    head->next = NULL;
    tail = head;

    struct node* new_node = calloc(1,sizeof(struct node));
    new_node->next = head;
    new_node->data = 2;

    printf("%d\n", new_node->data);
    struct node* tmp = new_node;
    while (tmp != NULL){
        printf("tmp->data = %d\n", tmp->data);
        tmp = tmp->next;
    }
}
