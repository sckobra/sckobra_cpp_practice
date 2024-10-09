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

void printList(Node* head){
    Node* current = head;
    while (current){
        cout << "["<< current->data << "]";
        current = current->next;
        if(current) cout << "->";

    }
    cout <<endl;

}

Node* reverseList(Node* head){
    Node* prev = nullptr;
    Node* curr = head;
    Node* next;
    while (curr != nullptr){
        next = curr->next;
        curr->next = prev; //in the first iteration, this would make 40 node point to null
        prev = curr;
        curr = next;
    }
    return prev;
}


int main(){
    Node* head = nullptr;
    head = push_front(head, 10);
    head = push_front(head, 20);
    head = push_front(head, 30);
    head = push_front(head, 40);
    //printList(head);
    printList(reverseList(head));
    
    return 0;
}