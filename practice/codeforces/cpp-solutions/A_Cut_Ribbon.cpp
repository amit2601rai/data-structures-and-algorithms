#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, a, b, c;
    cin>>n>>a>>b>>c;
    vector<int> dp(n+1,0);
    for(int i = 1; i <=n; i++) {
        if (i - a >= 0) dp[i] = max(dp[i], (dp[i - a] != 0 || i == a) ? dp[i - a] + 1 : 0);
        if(i - b >= 0) dp[i] = max(dp[i], (dp[i - b] != 0 || i == b) ? dp[i - b] + 1 : 0);
        if(i - c >= 0) dp[i] = max(dp[i], (dp[i - c] != 0 || i == c) ? dp[i - c] + 1 : 0);
    }
    cout<<dp[n]<<endl;
    return 0;
}