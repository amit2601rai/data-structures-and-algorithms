#include <bits/stdc++.h>
 
using namespace std;

vector<int> solve(vector<int>v, int n, int k) {
    vector<vector<int> > dp(n+1, vector<int>(k+1, -1));
    vector<vector<bool> > flag(n+1, vector<bool>(k+1, false));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (i == 1) {
                if (v[i] >= j) dp[i][j] =  1, flag[i][j] = true;
            } else if (j - v[i] >= 1) {
                if (dp[i-1][j - v[i]] == -1) {
                    dp[i][j] = dp[i-1][j];
                } else if (dp[i-1][j] == -1) {
                   dp[i][j] = dp[i-1][j - v[i]] + 1;
                   flag[i][j] = true;
                } else {
                    if (dp[i-1][j] <= dp[i-1][j - v[i]] + 1 ) {
                        dp[i][j] = dp[i-1][j];
                    } else {
                        dp[i][j] = dp[i-1][j - v[i]] + 1;
                        flag[i][j] = true;
                    }
                }
            } else {
                if (dp[i-1][j] != 1) {
                    dp[i][j] = 1;
                    flag[i][j] = true;
                } else {
                    dp[i][j] = 1;
                }
            }
        }
    } 

    vector<int> el;
    int x = n, y = k;
    while(x >= 1) {
        if (flag[x][y] == true) {
            el.push_back(x);
            y -= v[x];
            if (y <= 0) break;
        }
        x--;
    }
    return el;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> v(n+1, -1);
        for (int i = 1; i <= n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.begin() + n + 1);
        vector<int> elm = solve(v, n, k);

        if (elm.size() == 0) {cout << "-1" << endl; return 0;}

        for (int i = 0; i < elm.size(); i++) {
            v[elm[i]] = -1;
        }
        int m = n - elm.size();
        vector<int> u(m+1, -1);
        int j = 1;
        for (int i = 1; i <= n; i++) {
            if (v[i] != -1) u[j] = v[i], j++;
        }
        vector<int> elt = solve(u, m, k);
        sort(u.begin(), u.begin() + m + 1);

        if (elt.size() == 0) cout << "-1" << endl;
        else {
            sort(elm.begin(), elm.end());
            sort(elt.begin(), elt.end());
            int low = 0;
            int high = elt.size() - 1;
            int ans = 0;
            int flag = 0;
            while (flag < 2) {
                if (elm[low] >= k) ans++, flag++, low++;
                else if (elt[high] >= k) ans++, flag++, high--;
                else if (elm[low] + elt[high] < k) ans++, low++;
                else ans++, flag++, high--;
            }



            cout << elm.size() + elt.size() << endl;
        } 
    }

    return 0;
}