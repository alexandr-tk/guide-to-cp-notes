
#include<bits/stdc++.h>

using namespace std;


int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin>>n;

    vector<vector<char>> grid(n+1,vector<char>(n+1));
    vector<vector<pair<int,int>>> dp(n+1, vector<pair<int,int>>(n+1, {-1,-1}));
    vector<vector<int>> ranks(n+1, vector<int>(n+1));

    for(int i=1; i<=n;i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>grid[i][j];
        }
    }
    


    for(int i=1; i<=n;i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(i==1 && j==1) 
            {
                dp[i][j] = {-1,-1};
                ranks[i][j] = 0;
            }
            else if(i==1)
            {
                dp[i][j] = {i,j-1}; 
                ranks[i][j] = ranks[i][j-1] + to_string(grid[i][j]).compare("Z");
            }
            else if(j==1) 
            {
                dp[i][j] = dp[i-1][j] + grid[i][j];
            }
            else{
            if(dp[i-1][j].compare(dp[i][j-1])<0)
            {
                dp[i][j] = dp[i-1][j] + grid[i][j];
            }
            else{
                dp[i][j] = dp[i][j-1] + grid[i][j];
            }
            }
        }
    }

    cout<<dp[n][n];
    


}