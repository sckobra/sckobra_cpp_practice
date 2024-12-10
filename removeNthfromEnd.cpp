#include<iostream>
using namespace std;
#include <vector>

struct ListNode {
    int value;           
    ListNode* next; 
    ListNode(int val) : value(val), next(nullptr) {}     
};

ListNode* removeNthFromEnd(ListNode* head, int n){
    if (!head) return head;
    ListNode* p = head;
    int size = 0;
    while(p != nullptr){
        size++;
        p = p->next;
    }
    cout << "size: " <<size<<endl;

    int indexRemove = size - n;
    cout << "index remove: "<<indexRemove<<endl;
    p = head;
    if (indexRemove == 0){
        head = head->next;
        delete p;
        return head;
    }
    ListNode* p2 = head->next;
    int indexCount = 1;
    while(p2 != nullptr){
        cout << "entered"<<endl;
        if(indexCount == indexRemove){
            p->next = p2->next;
            delete p2;
            return head;
        }
        p = p->next;
        p2 = p2->next;
        indexCount++;
    }
    return head;

}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->value << ", ";
        current = current->next;
    }
    cout << endl; 
}

int main(){
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    printList(head);
    removeNthFromEnd(head, 2);
    printList(head);
    return 0;
}