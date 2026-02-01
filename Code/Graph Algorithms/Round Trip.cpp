#include<bits/stdc++.h>
using namespace std;


vector<vector<int>> adjList;
vector<bool> visited;
vector<int> cameFrom;
int foundCycle=-1;


void bfs(int vertice, int parent)
{
    if(foundCycle!=-1) return;
    
    if(visited[vertice] && cameFrom[parent] != vertice)
    {
        foundCycle = vertice;
        cameFrom[vertice] = parent;
    }
    else if(visited[vertice]) return;

    visited[vertice] = true;
    for(size_t j=0; j<adjList[vertice].size(); j++)
    {


        if(!visited[adjList[vertice][j]] && cameFrom[vertice]!=adjList[vertice][j] )
        {
            cameFrom[adjList[vertice][j]] = vertice;
        }
        else if(visited[adjList[vertice][j]] && cameFrom[vertice]==adjList[vertice][j])
        {
            continue;
        }
        
        bfs(adjList[vertice][j], vertice);
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;


    cin>>n>>m;
    cameFrom.resize(n+1, -1);
    visited.resize(n+1, false);
    adjList.resize(n+1);

    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }



    for(int i=1; i<=n; i++)
    {
        if(foundCycle!=-1) break;
        if(!visited[i]) bfs(i, -1);
    }

    if(foundCycle==-1)
    {
        cout<<"IMPOSSIBLE";
    }
    else{
        vector<int> path;
        path.push_back(foundCycle);
        int curCity = cameFrom[foundCycle];
        while(curCity!=foundCycle)
        {
            path.push_back(curCity);
            curCity = cameFrom[curCity];
        }
        cout<<path.size()+1<<endl;
        for(int city: path)
        {
            cout<<city<<" ";
        }
        cout<<foundCycle;
    }
}