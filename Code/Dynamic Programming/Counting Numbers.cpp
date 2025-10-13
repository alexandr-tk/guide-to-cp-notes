#include<bits/stdc++.h>
using namespace std;




vector<vector<vector<vector<long long>>>> dp(20, vector<vector<vector<long long>>>(2, vector<vector<long long>>(2, vector<long long>(11,-1))));




long long rec(string lim, int pos, int smaller, int started, int prev)
{
    if(started==0) prev = 10;
    if(dp[pos][smaller][started][prev]!=-1)
    {
        return dp[pos][smaller][started][prev];
    }

    int sz = lim.size();
    long long ans = 0;
    if(pos==sz) 
    {
        if(!started) return 0;
        return 1;
    }

    if(smaller)
    {

        for(int i=0; i<=9;i++)
        {   

            if(!started || i!=prev) {
                ans += rec(lim, pos+1, smaller, (started || i!=0), i);
            }
        }
    }
    else
    {
        for(int i=0; i<=lim[pos]-'0';i++)
        {
            if(!started || i!=prev) {
                ans += rec(lim, pos+1, i<lim[pos]-'0', (started || i!=0), i);
            }
        }
        
    }

    dp[pos][smaller][started][prev] = ans;
    return ans;
}

int main(){

  long long a,b;

  cin>>a>>b;
  
  if(a==0)
  {

    cout<<rec(to_string(b), 0, false, false, 10) + 1;
    
  }
  
  else{
    long long calc_b = rec(to_string(b), 0, false, false, 10);
    
    for(int i=0; i<20; i++)
    {
        for(int j=0; j<2; j++)
        {
            for(int k=0; k<2; k++)
            {
                for(int l=0; l<11; l++)
                {
                    dp[i][j][k][l] = -1;
                }
            }
        }
    }
    long long calc_a = rec(to_string(a-1), 0, false, false, 10);
    cout<< calc_b - calc_a;
  }
  
}