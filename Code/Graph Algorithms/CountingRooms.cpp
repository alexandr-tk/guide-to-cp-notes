#include <bits/stdc++.h>
using namespace std;

int n,m;
vector<vector<char>> roomMap;
vector<vector<bool>> visited;


bool isValid(int i, int j)
{
    if(i<0 || j<0 || i>=n || j>=m || visited[i][j] || roomMap[i][j]!='.') return false;
    return true;
}

void dfs(int i, int j){
    if(visited[i][j]) return;
    visited[i][j] = true;
    if(isValid(i-1, j)) dfs(i-1,j);
    if(isValid(i+1, j)) dfs(i+1, j);
    if(isValid(i, j-1)) dfs(i, j-1);
    if(isValid(i, j+1)) dfs(i, j+1);
    return;
}


int main(){
    cin>>n>>m;
    int numOfRooms = 0;
    roomMap.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>roomMap[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(isValid(i,j))
            {
                dfs(i,j);
                numOfRooms++;
            }
        }
    }

    cout<<numOfRooms;
}
