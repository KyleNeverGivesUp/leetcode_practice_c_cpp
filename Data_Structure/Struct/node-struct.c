#include <stdio.h>
#include <stdlib.h> // 为了用 malloc

typedef struct Node{
    int data;
    struct Node* next;
} Node;

typedef struct linkedList{
    Node* head;
    Node* tail;
    int size;
}ll;

Node* createNode(int value){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void initialll(ll* list){
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}

void append(ll* list, int value){
    Node* n = malloc(sizeof(Node));
    n->data = value;
    n->next = NULL;
    
    if (list->head == NULL){
        list->head = n;
        list->tail = n;
    }else{
        list->tail->next = n;
        list->tail = n;
    }
    list->size++;
}

void freeList(ll* list){
    Node* curr = list->head;
    while (curr != NULL){
        Node* next = curr->next;
        free(curr);
        curr = next;
    }

    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
}


int main(){
    Node* myNode = createNode(42);
    printf("Node data: %d\n", myNode->data);
    ll l;
    initialll(&l);
    append(&l, 3);
    append(&l, 5);

    Node* curr = l.head;
    while(curr != NULL){
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("total size is: %d\n", l.size);
    freeList(&l);
    printf("total size is: %d\n", l.size);
    return 0;
}