#include<bits/stdc++.h>
using namespace std;

int main(){

    int n, w;
    cin>>n>>w;
    vector<int> weights(n);

    for(auto &x:weights) cin>>x;

    vector<pair<int,int>> dp((1<<n), {INT_MAX, 0});
    
    dp[0] = {0,0}; //{Rides needed, How much more weight we can have}


    for(int mask=0; mask<(1<<n); mask++)
    {
        for(int j=0; j<n; j++)
        {
            if((mask & (1<<j)) == 0)
            {
                int next = mask | (1<<j);
                int weight = weights[j];
                if(weight<=dp[mask].second)
                {
                    if(dp[next].first>dp[mask].first
                    ||
                    (dp[next].first==dp[mask].first 
                        && 
                    dp[next].second<dp[mask].second-weight)
                    )

                    {
                        dp[next] = {dp[mask].first, dp[mask].second - weight};
                    }
                }
                else{

                    if(dp[next].first>dp[mask].first + 1
                    ||
                    (dp[next].first==dp[mask].first +1
                        && 
                    dp[next].second<max(dp[mask].second,w-weight))
                    )

                    {
                        dp[next] = {dp[mask].first + 1, max(dp[mask].second,w-weight)};
                    }
                    
                }
            }
        }
    }

    cout<<dp[(1<<n)-1].first;
}