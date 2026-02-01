#include <bits/stdc++.h>
using namespace std;


int n,m;
vector<vector<char>> roomMap;
vector<vector<char>> shortestCell;
vector<vector<bool>> visited;
vector<vector<int>> player_dist;
vector<vector<int>> monster_dist;
queue<pair<int,int>> mQueue;


bool isValid(int i, int j)
{
    if(i>=n || j>=m || i<0 || j<0 || roomMap[i][j]=='#' || visited[i][j]) return false;
    
    return true;
}

void bfs()
{   
    int i, j;
    while (mQueue.size()!=0)
    {
    pair<int,int> cell = mQueue.front();
    mQueue.pop();
    i = cell.first;
    j=cell.second;

    visited[i][j] = true;

        if(isValid(i+1, j)) 
        {
            mQueue.push({i+1, j});
            shortestCell[i+1][j] = 'D';
            visited[i+1][j]= true;
        }
        if(isValid(i, j+1)) 
        {
            mQueue.push({i, j+1});
            shortestCell[i][j+1] = 'R';
            visited[i][j+1]= true;
        }
        if(isValid(i-1, j))
        {
            mQueue.push({i-1, j});
            shortestCell[i-1][j] = 'U';
            visited[i-1][j]= true;
        } 
        if(isValid(i, j-1)) 
        {
            mQueue.push({i, j-1});
            shortestCell[i][j-1] = 'L';
            visited[i][j-1]= true;
        }
    }
}

string backtrack(int finalx, int finaly, int startx, int starty)
{
    string ans = "";
    int i = finalx, j = finaly;
    while(i!=startx || j!=starty)
    {
        ans+=shortestCell[i][j];
        if(shortestCell[i][j]=='D') i--;
        else if(shortestCell[i][j]=='R') j--;
        else if(shortestCell[i][j]=='U') i++;
        else if(shortestCell[i][j]=='L') j++;
    }

    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int startx, starty;
    cin>>n>>m;
    roomMap.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));
    shortestCell.resize(n, vector<char>(m));

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>roomMap[i][j];
            if(roomMap[i][j]=='A')
            {
                startx = i;
                starty = j;
            }
        }
    }
    mQueue.push({startx,starty});
    bfs();



    
    if(visited[finishx][finishy])
    {
        cout<<"YES\n";
        
        string path = backtrack(finishx, finishy, startx, starty);
        reverse(path.begin(), path.end());
        cout<<path.length()<<endl;
        cout<<path;
    }
    else{
        cout<<"NO";
    }
}
