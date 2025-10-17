#include <bits/stdc++.h>
 
using namespace std;

int solve(vector<int>v, int n, int k) {
    vector<vector<vector<int> > > dp(3, vector<vector<int> >(n+1, vector<int>(k+1, INT_MAX)));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            int incm = (j- v[i] >= 1) ? ((dp[1][i-1][j- v[i]] != INT_MAX) ? dp[1][i-1][j- v[i]] + 1 : INT_MAX) : 1;
            int nincm = dp[1][i-1][j];
            int inct = (j- v[i] >= 1) ? ((dp[2][i-1][j- v[i]] != INT_MAX) ? dp[2][i-1][j- v[i]] + 1 : INT_MAX) : 1;
            int ninct = dp[2][i-1][j];
            dp[1][i][j] = nincm;
            dp[2][i][j] = ninct;
            if (incm != INT_MAX) dp[1][i][j] = min(dp[1][i][j], incm);
            if (inct != INT_MAX) if (inct < dp[2][i][j]) dp[2][i][j] = inct, dp[1][i][j] = nincm;
        }
    }
    if (dp[1][n][k] == INT_MAX || dp[2][n][k] == INT_MAX) return -1;
    return dp[1][n][k] + dp[2][n][k];
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.begin() + n + 1);
        cout << solve(v, n, k) << endl;
    }
    return 0;
}