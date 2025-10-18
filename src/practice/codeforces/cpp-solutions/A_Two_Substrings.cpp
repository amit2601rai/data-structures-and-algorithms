#include <bits/stdc++.h>

using namespace std;

int longestCommonSubseq(string a, string b) {
    int m = a.size();
    int n = b.size();
 
    vector<vector<int> > dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if(a[i] == b[j]) {
                dp[i][j] = 1 + ((i-1 >= 0 && j-1 >= 0) ? dp[i-1][j-1] : 0);
            } else {
                dp[i][j] = (j-1 >= 0) ? dp[i][j-1] : 0;
                dp[i][j] = (i-1 >= 0) ? max(dp[i][j], dp[i-1][j]) : 0;
            }
        }
    }
    return dp[m-1][n-1];
}


int main() {
    string s;
    cin>>s;
    
    size_t ab = s.find("AB");
    size_t ba = s.find("BA");

    if (ab != -1 && ba != -1) {
        int abba = longestCommonSubseq(s, "ABBA");
        int baab = longestCommonSubseq(s, "BAAB");
        if (abba == 4 || baab == 4) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    } else cout<<"NO"<<endl;
    return 0;
}