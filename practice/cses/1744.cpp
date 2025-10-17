#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int a, b;
    cin >> a >> b;
    vector<vector<int> >dp(a+1, vector<int>(b+1, INT_MAX));
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            if (i == j) dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= a; i++) dp[i][1] = i - 1;
    for (int j = 1; j <= b; j++) dp[1][j] = j - 1;

    for (int i = 2; i <= a; i++) {
        for (int j = 2; j <= b; j++) {
            for (int k = 1; k < i; k++) {
                if (dp[k][j] != INT_MAX && dp[i-k][j] != INT_MAX) {
                    dp[i][j] = min(dp[i][j], 1 + dp[k][j] + dp[i-k][j]);
                }
            }
            for (int l = 1; l < j; l++) {
                if (dp[i][l] != INT_MAX && dp[i][j-l] != INT_MAX) { 
                    dp[i][j] = min(dp[i][j], 1 + dp[i][l] + dp[i][j-l]);
                }
            }
        }
    }
    cout << dp[a][b] << endl;
    return 0;
}