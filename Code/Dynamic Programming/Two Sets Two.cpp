#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    const int MOD = (1e9+7)*2;
    cin>>n;
    int sumN = 0;
    for(int i=1; i<=n; i++) sumN += i;


    if(sumN%2!=0) {
        cout<<0;
        return 0;
    }

    vector<vector<long long>> dp(501, vector<long long>(sumN/2+1, 0));

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sumN/2; j++)
        {
            if(i==j) dp[i][j]++;
            dp[i][j] += dp[i-1][j];
            if(j-i>0) dp[i][j] += dp[i-1][j-i];
            dp[i][j]%=MOD;
        }
    }

    cout<<(dp[n][sumN/2]/2)<<endl;
}