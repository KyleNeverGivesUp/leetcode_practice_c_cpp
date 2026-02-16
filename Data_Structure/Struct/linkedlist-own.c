#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* next;
}Node;

typedef struct{
    Node* head;
    Node* tail;
    int size;
}linkedList;

linkedList* initialList(){
    linkedList* l = malloc(sizeof(linkedList));
    l->head=NULL;
    l->tail=NULL;
    l->size=0;
    return l;
}

void append(linkedList* l, int value){
    Node* new = malloc(sizeof(Node));
    new->data = value;
    new->next = NULL;
    if (l->head == NULL){
        l->head = new;
        l->tail = new;
    }else{
        l->tail->next = new;
        l->tail = new;
    }
    l->size += 1;
}

void printl(linkedList* l){
    Node* curr = l->head;
    
    while (curr != NULL){
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main(){
    // initial linkedlist
    linkedList* l = initialList();
    append(l, 5);
    append(l, 6);
    append(l, 1);
    // int n = sizeof(l);
    printl(l);
}

