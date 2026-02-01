#include<bits/stdc++.h>
using namespace std;


vector<bool> visited;
vector<vector<int>> adjList;


void dfs(int vertice)
{
    if(visited[vertice]) return;
    visited[vertice] = true;

    for(int i=0; i<adjList[vertice].size(); i++)
    {
        dfs(adjList[vertice][i]);
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin>>n>>m;
    visited.resize(n +1,false);
    adjList.resize (n+1);
    vector<int> copmonentVertices;
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    for(int i=1; i<=n; i++)
    {
        if(!visited[i])
        {
            copmonentVertices.push_back(i);
            dfs(i);
        }
    }

    cout<<copmonentVertices.size()-1<<endl;
    for(int i=1; i<copmonentVertices.size(); i++)
    {
        cout<<copmonentVertices[0]<<" "<<copmonentVertices[i]<<endl;
    }

}