#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<long long> dp(1e6+1, 0);
    long long mod = 1e9 + 7;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    dp[4] = 8;
    dp[5] = 16;
    dp[6] = 32;
    for (int i = 7; i <= n; i++) {
        dp[i] += dp[i-1];
        dp[i] %= mod;
        dp[i] += dp[i-2];
        dp[i] %= mod;
        dp[i] += dp[i-3];
        dp[i] %= mod;
        dp[i] += dp[i-4];
        dp[i] %= mod;
        dp[i] += dp[i-5];
        dp[i] %= mod;
        dp[i] += dp[i-6];
        dp[i] %= mod;
    }
    cout << dp[n] << endl;
    return 0;
}