#include <bits/stdc++.h>

using namespace std;

int cal(string s, int m, int x, int y) {
    vector<int> dp(m, 0);
    for (int i = 0; i < m; i++) {
        if (s[i] == '.') {            
            if(i - 1 < 0) dp[i] = x;
            else if(i - 2 < 0 && s[i-1] == '.') dp[i] = min(dp[i-1] + x, y);
            else if(i - 2 < 0 && s[i-1] == '*') dp[i] = dp[i-1] + x;
            else if(s[i-1] == '.') dp[i] = min(dp[i-1] + x, dp[i-2]+y); 
            else dp[i] = dp[i-1] + x;
        } else {
            if (i > 0) dp[i] = dp[i-1];
        }
    }
    return dp[m-1];
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n, m, x, y;
        cin>>n>>m>>x>>y;
        int ans = 0;
        while(n--) {
            string s;
            cin>>s;
            ans += cal(s, m, x, y);
        }
        cout<<ans<<endl;
    }
    return 0;
}