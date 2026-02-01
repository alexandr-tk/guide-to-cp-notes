#include<bits/stdc++.h>
using namespace std;





int main(){


    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n,m;
    cin>>n>>m;
    vector<bool> visited(n+1);
    vector<vector<int>> adjList(n+1);
    vector<int> teams(n+1);
    queue<int> mQueue;


    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        adjList[a].push_back(b);
        adjList[b].push_back(a);
    }


    for(int r=1; r<=n; r++)
    {
        if(visited[r]) continue;
        mQueue.push(r);
        visited[r] = true;
        teams[r] = 1;

        while(mQueue.size()!=0)
        {
            int vertice = mQueue.front();
            mQueue.pop();
            for(int i=0; i<adjList[vertice].size(); i++)
            {
                if(!visited[adjList[vertice][i]]) 
                {
                    mQueue.push(adjList[vertice][i]);
                    visited[adjList[vertice][i]] = true;
                    teams[adjList[vertice][i]] = teams[vertice]%2+1;
                }
            }
        }
    }

    for(int i=1; i<=n; i++)
    {
        int team = teams[i];
        for(int j=0; j<adjList[i].size(); j++)
        {
            if(team == teams[adjList[i][j]])
            {
                cout<<"IMPOSSIBLE";
                return 0;
            }
        }
    }


   for(int i=1; i<=n; i++)
   {
    cout<<teams[i]<<" ";
   }
}