#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>



int shortestPath(int u, int v, vector<list<int>>& adjList){

    queue<int> myQ;
    //vector<bool> visited(adjList.size(), false);
    int pathLength = 0;
    //visited[0] = true;
    myQ.push(u);

    while (!myQ.empty()){
        int front = myQ.front();
        myQ.pop();
        cout << "popped from q"<<endl;
        pathLength++;
        for (int i : adjList[front]){
            if(i == v){
                cout << "returned path length: " << pathLength<<endl;
                return pathLength;
            } else {
                cout << "incremented path length: " << pathLength<<endl;
                myQ.push(i);
                cout << i << " pushed to q"<<endl;
            }

        }
    }
    return pathLength;
}
int main(){
    vector<list<int>> adjList = {{1, 2, 3}, {3}, {3, 5}, {4}, {5}};
    int shortestPath1 = shortestPath(0, 3, adjList);
    cout << "shortest path 1: " << shortestPath1<<endl;
    int shortestPath2= shortestPath(0, 5, adjList);
    cout << "shortest path 2: " << shortestPath2<<endl;
    return 0;
}