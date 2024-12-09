#include<iostream>
using namespace std;
#include <vector>

struct ListNode {
    int value;           
    ListNode* next; 
    ListNode(int val) : value(val), next(nullptr) {}     

};

ListNode* removeNthFromEnd(ListNode* head, int n){
    ListNode* p = head;
    vector<int> intVec;
    while(p->next != nullptr){
        //intVec.push_back(p->value);
        if (p->next != nullptr) {p = p->next;}
    }
    cout<< "p is now: "<<p->value<<endl;
    cout <<"amount of elements: " << intVec.size()<<endl;

    cout<<endl;
    return p;

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
    return 0;
}