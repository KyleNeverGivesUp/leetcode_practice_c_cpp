#ifndef slist_h
#define slist_h

#include <stdio.h>

struct node{
    int data;
    struct node* next;
};

struct singly_linked_list {
    struct node* head;
    struct node* tail;
};

typedef struct singly_linked_list slist;

void add_to_head(slist* slist, int data);
void print_list(slist* slist);

#endif // slist_h