#include <iostream>
using namespace std;
#include <vector>
#include <queue>

bool treasureFound(vector<vector<char>> map, pair<int, int> start)
{
    queue<pair<int, int>> myQ;
    vector<vector<bool>> visited(map.size(), vector<bool>(map[0].size(), false));

    myQ.push(start);
    visited[start.first][start.second] = true;
    while (!myQ.empty())
    {
        cout << "entered "<<endl;
        pair<int, int> curr = myQ.front();
        myQ.pop();

        vector<char> neib;
        cout << "curr first: "<< curr.first<<endl;
        cout <<"curr second: "<<curr.second<<endl;
        if (curr.first - 1 > -1)
        {
            neib.push_back(map[curr.first - 1][curr.second]);
            if (!visited[curr.first - 1][curr.second]){
                myQ.push({curr.first - 1, curr.second});
                visited[curr.first - 1][curr.second] = true;
            }
            cout << "top neighbor pushed "<<endl; // Top neighbor
        }
        if (curr.first + 1 < map.size())
        {
            neib.push_back(map[curr.first + 1][curr.second]); // Bottom neighbor
            if (!visited[curr.first + 1][curr.second]){
                myQ.push({curr.first + 1, curr.second});
                visited[curr.first + 1][curr.second] = true;
            }
            cout << "bottom neighbor pushed "<<endl;
        }
        if (curr.second - 1 > -1)
        {
            neib.push_back(map[curr.first][curr.second - 1]); // Left neighbor
            if (!visited[curr.first][curr.second - 1]){
                myQ.push({curr.first, curr.second - 1});
                visited[curr.first][curr.second - 1] = true;
            }
            cout << "left neighbor pushed "<<endl;
        }
        if (curr.second + 1 < map[0].size())
        {
            neib.push_back(map[curr.first][curr.second + 1]); // Right neighbor
            if (!visited[curr.first][curr.second + 1]){
                myQ.push({curr.first, curr.second + 1});
                visited[curr.first][curr.second + 1] = true;
            }
            cout << "right neighbor pushed "<<endl;
        }
        
        for (char& c : neib){
            if (c == 'X'){return true;}
        }
    }

    return true;
}
int main()
{
    vector<vector<char>> map = {
        {'P', 'S', 'S', 'S', 'S', 'W'},
        {'S', 'S', 'O', 'O', 'S', 'W'},
        {'W', 'O', 'S', 'S', 'S', 'W'},
        {'W', 'S', 'S', 'S', 'S', 'W'},
        {'W', 'X', 'O', 'O', 'W', 'W'}};

    treasureFound(map, {0, 1});

    return 0;
}