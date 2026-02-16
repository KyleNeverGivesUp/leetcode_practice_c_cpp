#include <iostream>
using namespace std;

class linkedList{
    private:
        struct Node{
            int data;
            Node* next;
            Node(int val): data(val), next(nullptr) {}
        };

        Node* head;
        Node* tail;
        int size;

    public:
        linkedList():head(nullptr), tail(nullptr), size(0){}
        ~linkedList(){
            Node* curr = head;
            while (curr != nullptr){
                Node* nextNode = curr->next;
                delete curr;
                curr = nextNode;
            }
            cout << "memory is clear" << endl;
        }

        void append(int value){
            Node* newNode = new Node(value);
            if (head == nullptr){
                head = tail = newNode;
            }else{
                tail->next = newNode;
                tail = newNode;
            }
            size += 1;
        }

        void print(){
            Node* curr = head;
            while (curr != nullptr){
                cout << curr->data << endl;
                curr = curr->next;
            }
            cout << "NULL (size: " << size << ")" << endl;
        }
};

int main(){
    linkedList l;
    l.append(5);
    l.append(6);
    l.append(1);

    l.print();
    return 0;
}