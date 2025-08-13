#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct singlylinkedlist{
    sturct node* head;
    sturct node* next;
};

typedef struct  singlylinkedlist slist;

int main(){

    slist score;
    score.head = malloc(sizeof(struct node));
    score.head->data = 3;

    // struct node* head = NULL;
    // struct node* tail = NULL;
    // head = malloc(sizeof(struct node));
    // head->data = 3;
    // head->next = NULL;
    // tail = head;
    // // printf("%d", head->data);

    // struct node* newnode;
    // newnode = malloc(sizeof(struct node));
    // newnode->data = 5;
    // newnode->next = head;
    // head = newnode;

    // struct node* tmp = head;
    // while(tmp != NULL){
    //     printf("%d\n",tmp->data);
    //     tmp = tmp->next;
    // }    
    
    return 0;
}

