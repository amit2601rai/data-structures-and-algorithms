#include <bits/stdc++.h>
 
using namespace std;
 
int main() {
    map<string, int> mp;
    mp["A"] = 0;
    mp["AB"] = 1;
    mp["AC"] = 2;
    mp["B"] = 3;
    mp["BC"] = 4;
    mp["C"] = 5;
    mp["ABC"] = 6;

    map<int, string> revmp;
    revmp[0] = "A";
    revmp[1] = "AB";
    revmp[2] = "AC";
    revmp[3] = "B";
    revmp[4] = "BC";
    revmp[5] = "C";
    revmp[6] = "ABC";

    int n;
    cin >> n;
    vector<vector<int> > dp(n, vector<int>(7, INT_MAX));

    int p;
    string s;
    cin >> p >> s;
    sort(s.begin(), s.end());
    for (int j = 0; j < 7; j++) {
        if (s.find(revmp[j]) != std::string::npos) {
            dp[0][j] = p;
        }
    }
    
    for (int i = 1; i < n; i++) {
        cin >> p >> s;
        sort(s.begin(), s.end());
        
        for (int j = 0; j < 7; j++) {
            string st = revmp[j];
            dp[i][j] = dp[i-1][j];
            if (s.find(st) != std::string::npos) {
                dp[i][j] = min(dp[i][j], p);
            }
        }

        for (int j = 0; j < 7; j++) {
            string st = revmp[j];
            string unionst;
            set_union(s.begin(), s.end(), st.begin(), st.end(), back_inserter(unionst));
            sort(unionst.begin(), unionst.end());
            int k = mp[unionst];
            if (dp[i-1][j] != INT_MAX) dp[i][k] = min(dp[i-1][j] + p, dp[i][k]);
        }
    }
    if (dp[n-1][6] == INT_MAX) cout << "-1" << endl;
    else cout << dp[n-1][6] << endl;
    return 0;
}