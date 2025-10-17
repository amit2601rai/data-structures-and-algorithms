#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin>>v[i];
    }
    vector<vector<int> > dp(3, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        if(v[i] == 1) {
            dp[1][i] = 1;
        } else if(v[i] == 2) {
            dp[2][i] = 1;
        } else if (v[i] == 3) {
            dp[1][i] = dp[2][i] = 1;
        }

        if (i > 0) {
            dp[0][i] += max(dp[0][i-1], max(dp[1][i-1], dp[2][i-1]));
            dp[1][i] += max(dp[0][i-1], dp[2][i-1]);
            dp[2][i] += max(dp[0][i-1], dp[1][i-1]);
        }
    }
    int minRestDays = n - max(dp[0][n-1], max(dp[1][n-1], dp[2][n-1]));
    cout<<minRestDays<<endl;
    return 0;
}