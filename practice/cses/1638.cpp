#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    int n;
    cin >> n;
    int mod = 1e9 + 7;
    vector<vector<int> >dp(n, vector<int>(n,1));

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            if (str[j] == '*') {
                dp[i][j] = 0;
            }
        }
    }
    for (int j = 1; j < n; j++) if (dp[0][j] != 0) dp[0][j] = dp[0][j-1];
    for (int i = 1; i < n; i++) if (dp[i][0] != 0) dp[i][0] = dp[i-1][0];
    


    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (dp[i][j] != 0) {
                dp[i][j] = dp[i][j-1]+dp[i-1][j];
                dp[i][j] %= mod;
            }
        }
    }
    cout << dp[n-1][n-1] << endl;
    return 0;
}