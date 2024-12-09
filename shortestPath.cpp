#include <iostream>
using namespace std;
#include <vector>
#include <list>
#include <queue>

#include <climits>

int shortestPath(int u, int v, vector<list<int>>& adjList){
    //if (u == v) return 0;

    queue<int> myQ;
    int n = adjList.size();
    //vector<bool> visited(adjList.size(), false);
    //visited[0] = true;
    vector<int> distance(n, INT_MAX);
    for (auto e : distance){
        cout << e <<endl;
    }
    cout <<endl;
    distance[u] = 0;
    myQ.push(u);
    int pathCount = 0;

    while (!myQ.empty()){
        int front = myQ.front();
        cout << "front: "<< front<< endl;
        myQ.pop();        
        for (int e : adjList[front]){
            if (distance[e] == INT_MAX){
                cout << "distance front: "<< distance[front]<<endl;
                distance[e] = distance[front] + 1;
                cout << "distance of neighbor: " << distance[e]<<endl;
                if(e == v){
                    return distance[e];
                }
                myQ.push(e);
            }
        } 
    }
    return -1;
}
int main(){
    vector<list<int>> adjList = {{2,3}, {0}, {1}, {4}, {0}};
    int result = shortestPath(0, 0, adjList);
    cout <<result<<endl;

    return 0;
}