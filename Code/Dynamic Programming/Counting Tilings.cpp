#include <bits/stdc++.h>
using namespace std;

static inline bool isValid(long long prev, long long cur, int n, bool isLast) {
    if ((prev & cur) != 0) return false;
    if (isLast && __builtin_popcountll(cur) != 0) return false;

    long long check = (prev | cur);

    int i = 0;
    while (i < n) {
        if (((check >> i) & 1LL) == 0) {
            if (i == n - 1 || (((check >> (i + 1)) & 1LL) != 0)) return false;
            i++; // skip the next one as a pair
        }
        i++;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    const long long MOD = 1000000007LL;

    cin >> n >> m;



    int S = 1u << n;


    vector<vector<int>> ok(S), okLast(S);
    for (int prev = 0; prev < S; ++prev) {
        for (int cur = 0; cur < S; ++cur) {
            if (isValid(prev, cur, n, false)) ok[prev].push_back(cur);
            if (isValid(prev, cur, n, true))  okLast[prev].push_back(cur);
        }
    }

    vector<vector<long long>> dp(m, vector<long long>(S, 0));


    if (m == 1) {

        for (int cur : okLast[0]) dp[0][cur] = 1;
    } else {
        for (int cur : ok[0]) dp[0][cur] = 1;
    }

    // Fill DP
    for (int i = 1; i < m; ++i) {
        const auto& trans = (i == m - 1 ? okLast : ok);
        for (int prev = 0; prev < S; ++prev) {
            long long ways = dp[i - 1][prev];
            if (ways == 0) continue;
            for (int cur : trans[prev]) {
                dp[i][cur] += ways;
                if (dp[i][cur] >= MOD) dp[i][cur] %= MOD; // keeps numbers bounded
            }
        }
        // ensure all entries modded (in case we skipped mod above sometimes)
        for (int cur = 0; cur < S; ++cur) dp[i][cur] %= MOD;
    }

    long long ans = 0;
    for (int mask = 0; mask < S; ++mask) {
        ans += dp[m - 1][mask];
        if (ans >= MOD) ans %= MOD;
    }
    cout << (ans % MOD);
    return 0;
}
