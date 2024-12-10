#include <iostream>
using namespace std;

 
struct ListNode {
    int value;           
    ListNode* next; 
    ListNode(int val) : value(val), next(nullptr) {}     
};

ListNode* mergeSortedLists(ListNode* head1, ListNode* head2){
    if(!head1) return head1;
    if(!head2) return head2;
    ListNode* newHead = nullptr; 
    ListNode* newTail = nullptr; 
    
    
    ListNode* n1 = head1;
    ListNode* n2 = head2;
    if (n1->value <= n2->value) {
        newHead = newTail = n1;
        n1 = n1->next;
    } else {
        newHead = newTail = n2;
        n2 = n2->next;
    }

    while(n1 != nullptr && n2 != nullptr){
        if (n1->value <= n2->value){
            newTail->next = n1;
            newTail = n1;
            n1 = n1->next;
        } else {
            newTail->next = n2;
            newTail = n2;
            n2 = n2->next;
        }
        
    }
    return newHead;
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
    ListNode* head = new ListNode(5);
    head->next = new ListNode(10);
    head->next->next = new ListNode(15);
    //5, 10, 15, 
    //2, 3, 20, 
    ListNode* head2 = new ListNode(2);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(20);

    printList(head);
    printList(head2);

    ListNode* newHead = mergeSortedLists(head, head2);
    printList(newHead);
    
    return 0;
}