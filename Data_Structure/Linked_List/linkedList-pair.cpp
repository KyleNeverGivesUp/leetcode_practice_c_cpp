#include "linkedList-pair.h"
using namespace std;

linkedList::Node::Node(int val): data(val), next(nullptr){}

linkedList::linkedList(): head(nullptr), tail(nullptr), size(0){}

linkedList::~linkedList(){
    Node* curr = head;
    while (curr != nullptr){
        Node* nextNode = curr.next;
        delete curr;
        curr = nextNode;
    }
    cout << "memory is clear" << endl;
}

void linkedList::append(int value){
    
}