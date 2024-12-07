#include <iostream>
using namespace std;
#include <queue>
#include <stack>

void printQ(queue<int>& q){
    std::cout << "q: ";
    for (; !q.empty(); q.pop())
        std::cout << q.front() << ' ';
    std::cout << '\n';
}

void make_palindrome(queue<int>& q){
    queue<int> tempQ;
    stack<int> tempStack;
    
    
    while(!q.empty()){
        
        tempQ.push(q.front());
        tempStack.push(q.front());
        q.pop();
    }
    while(!tempQ.empty()){
        q.push(tempQ.front());
        tempQ.pop();
    }
    while(!tempStack.empty()){
        q.push(tempStack.top());
        tempStack.pop();
    }
}


int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);

    
    make_palindrome(q);
    cout <<"new queue: "<<endl;
    printQ(q);

    return 0;
}