#include <iostream>
using namespace std;
#include <vector>
#include <queue>

bool dfs(vector<vector<char>>& map, pair<int, int> curr, vector<vector<bool>>& visited){
    if (curr.first < 0 || curr.second < 0 || curr.first >= map.size() || curr.second >= map[0].size() ||
        map[curr.first][curr.second] == 'W' || map[curr.first][curr.second] == 'O' || map[curr.first][curr.second]){
        return false;
    }

    if(map[curr.first][curr.second] = 'X'){
        return true;
    }
    visited[curr.first][curr.second] = true;
    cout << "current pair: "<< curr.first <<", "<< curr.second <<endl;
    bool found = dfs(map, {curr.first - 1, curr.second}, visited) ||
    dfs(map, {curr.first + 1, curr.second}, visited) ||
    dfs(map, {curr.first, curr.second - 1}, visited) ||
    dfs(map, {curr.first, curr.second + 1}, visited);
    return found;
       
}
bool treasureFound(vector<vector<char>> map, pair<int, int> start)
{
    vector<vector<bool>> visited(map.size(), vector<bool>(map[0].size(), false));
    return dfs(map, start, visited);
}

int main()
{
    vector<vector<char>> map = {
        {'P', 'S', 'S', 'S', 'S', 'W'},
        {'S', 'S', 'O', 'O', 'S', 'W'},
        {'W', 'O', 'S', 'S', 'S', 'W'},
        {'W', 'S', 'S', 'S', 'S', 'W'},
        {'W', 'X', 'O', 'O', 'W', 'W'}};

    cout << treasureFound(map, {0, 0});
 
    return 0;
}