#include <iostream>
using namespace std;

 
struct Node{
    int data;
    Node* next;
};


Node* push_front(Node* h, int value){
  Node * myNodePointer = new Node;
  myNodePointer->data = value;
  myNodePointer->next = h;
  return myNodePointer;
}



int main(){
    Node* head = nullptr;
    head = push_front(head, 10);
    head = push_front(head, 20);
    head = push_front(head, 30);
    head = push_front(head, 40);
    //printList(head);
    return 0;
}