#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<long long> v(100001, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin>>x;
        v[x] += x;
    }

    long long ans = LLONG_MIN;
    vector<long long> dp(100001,0);
    dp[1] = v[1];
    dp[2] = max(v[1], v[2]);
    for (int i = 3; i < 100001; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + v[i]);
    }
    cout<<dp[100000]<<endl;
    return 0;
}