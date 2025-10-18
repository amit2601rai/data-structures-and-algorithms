#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    long long mod = 998244353;
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<long long> > dp(n+1, vector<long long>(k+1, 0));
    dp[1][0] = m;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] = dp[i-1][j];
            if (j-1 >= 0) dp[i][j] += (dp[i-1][j-1] * (m-1));
            if (dp[i][j] >= mod) dp[i][j] %= mod;
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}