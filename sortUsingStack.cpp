#include <iostream>
using namespace std;
#include <stack>


stack<int> sortUsingStack(stack<int>& s){
    stack<int> newStack;
    int totalSize = 1;
    bool firstIteration = true;
    int sizeNewStack = 0;
    //int max = s.top();
    //s.pop();
    int max;
    while (sizeNewStack != totalSize) {
        if (!s.empty()) {max = s.top();}
        s.pop();
        cout << "max at begining of loop: "<<max<<endl;
        while (!s.empty()){
            if(firstIteration) totalSize ++;    
            if (s.top() > max){
                newStack.push(max);
                max = s.top();
                cout << "new max: "<<max<<endl;
                s.pop();
            } else {
                newStack.push(s.top());
                s.pop();
            }
        }
        firstIteration = false;
        int numberTimesAddBack = (totalSize - 1) - sizeNewStack;
        cout << "number times to add back: " << numberTimesAddBack <<endl;
        for (int i = 0; i < numberTimesAddBack; i++) {
            s.push(newStack.top());
            newStack.pop();
        }
        newStack.push(max);
        sizeNewStack++;
    }
    cout <<"size new stack: " << sizeNewStack <<endl;
    cout <<"total size of stack: " << totalSize <<endl;
    return newStack;
}

int main(){

    stack<int> stack1;
    stack1.push(5);
    stack1.push(6);
    stack1.push(1);
    
    
    stack<int> newStack1 = sortUsingStack(stack1);

    cout << "original stack: "<<endl;
    while (!stack1.empty()) {
        std::cout << stack1.top() << std::endl; 
        stack1.pop();                          
    }
    cout <<endl;

    cout << "new stack: "<<endl;
    while (!newStack1.empty()) {
        std::cout << newStack1.top() << std::endl; 
        newStack1.pop();                          
    }
    return 0;
}