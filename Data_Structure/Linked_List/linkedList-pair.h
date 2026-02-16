#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class linkedList{
    private:
        struct Node{
            int data;
            Node* next;
            Node(int val);
        };

        Node* head;
        Node* tail;
        int size;

    public:
        linkedList();
        ~linkedList();
        void append(int value);
        void print();
};

#endif