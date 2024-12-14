#include <iostream>
using namespace std;

 
struct ListNode {
    int val;           
    ListNode* next; 
    ListNode(int val) : val(val), next(nullptr) {}     
};

ListNode* mergeSortedListsRecursive(ListNode* list1, ListNode* list2){
    if (!list1) {return list2;}
    else if (!list2) {return list1;}

    if(list1->val < list2->val){
        list1->next = mergeSortedListsRecursive(list1->next, list2);
        return list1;
    }
    else {
        list2->next = mergeSortedListsRecursive(list1, list2->next);
        return list2;
    }
}

ListNode* mergeSortedLists(ListNode* list1, ListNode* list2){
    if (!list1) {return list2;}
    else if (!list2) {return list1;}

    ListNode* n1 = list1;
    ListNode* n2 = list2;
    ListNode *head, *tail;

    n1->val < n2->val ? (head = n1, n1 = n1->next):(head = n2, n2 = n2->next);
    tail = head;  

    while(n1 && n2){
        cout << "n2:" << n2->val<<endl;
        if(n1->val < n2->val){
            tail->next = n1;
            n1 = n1->next;
        }
        else {
            tail->next = n2;
            n2 = n2->next;
        }
        tail = tail->next;
    }

    while (n1) {
        tail->next = n1;
        n1 = n1->next;
        tail = tail->next;
    }

    while(n2) {
        tail->next = n2;
        n2 = n2->next;
        tail = tail->next;
    }
    return head;
}

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        cout << current->val << ", ";
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

    ListNode* head3 = new ListNode(-9);
    head3->next = new ListNode(3);

    ListNode* head4 = new ListNode(5);
    head4->next = new ListNode(7);


    printList(head);
    printList(head2);

    ListNode* newHead = mergeSortedListsRecursive(head, head2);
    printList(newHead);

    // ListNode* newHead = mergeSortedLists(head3, head4);
    // printList(newHead);
    return 0;
}