#include<bits/stdc++.h>
using namespace std;





int main(){


    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    vector<bool> visited(n+1);
    vector<vector<int>> adjList(n+1);
    vector<int> closest(n+1);
    queue<int> mQueue;
    visited[1] = true;

    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }

    mQueue.push(1);

    while(mQueue.size()!=0)
    {
        int vertice = mQueue.front();
        mQueue.pop();
        if(vertice==n) break;
        for(int i=0; i<adjList[vertice].size(); i++)
        {
            if(!visited[adjList[vertice][i]]) 
            {
                mQueue.push(adjList[vertice][i]);
                visited[adjList[vertice][i]] = true;
                closest[adjList[vertice][i]] = vertice;
            }
        }
    }

    if(visited[n])
    {
        int curVert = n;
        vector<int> path;
        while(curVert!=1)
        {
            path.push_back(curVert);
            curVert = closest[curVert];
        }   
        path.push_back(1);
        reverse(path.begin(), path.end());
        cout<<path.size()<<endl;
        for(int i=0; i<path.size(); i++)
        {
            cout<<path[i]<<" ";
        }
    }
    else{
        cout<<"IMPOSSIBLE";
    }
}