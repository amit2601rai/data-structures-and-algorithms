 #include <bits/stdc++.h>
 
 using namespace std;
 
 typedef long long ll;
 typedef long double ld;
 typedef unsigned long long ull;
 typedef pair<int, int> ii;
 typedef vector<int> vi;
 typedef vector<vi> vvi;
 typedef vector<ii> vii;
 typedef priority_queue<int, vi, greater<int> > minHeap;
 typedef priority_queue<int> maxHeap;
 
 #define mod 1000000007
 #define pb push_back
 #define mp make_pair
 #define tr(c, val) for (const auto &val : c)
 #define ispresent(c, val) if(c.find(val) != c.end())
 #define setp(v,n) cout<<fixed;cout<<setprecision(n)<<v<<endl;
 
 int main(){
     int n, m;
     cin >> n >> m;
     vi v(n+1);
     vvi dp(m+1, vi(n+1, 0));
     for (int i = 1; i <= n; i++) cin >> v[i];
     if (v[1] == 0) {
         for (int i = 1; i <= m; i++) dp[i][1] = 1;
     } else {
         dp[v[1]][1] = 1;
     }
     for (int j = 2; j <= n; j++) {
         if (v[j] != 0) {
            dp[v[j]][j] = dp[v[j]][j-1];
            if (v[j]+1 <= m) dp[v[j]][j] += dp[v[j]+1][j-1];
            if (dp[v[j]][j] >= mod) dp[v[j]][j] %= mod;
            if (v[j]-1 >= 1) dp[v[j]][j] += dp[v[j]-1][j-1];
            if (dp[v[j]][j] >= mod) dp[v[j]][j] %= mod;
         } else {
            for (int i = 1; i <= m; i++) {
                dp[i][j] = dp[i][j-1];
                if (j > 1 && i+1 <= m) dp[i][j] += dp[i+1][j-1];
                if (dp[i][j] >= mod) dp[i][j] %= mod;
                if (j > 1 && i-1 >= 1) dp[i][j] += dp[i-1][j-1];
                if (dp[i][j] >= mod) dp[i][j] %= mod;
            }
        }
     }
     int ans = 0;
     for (int i = 1; i <= m; i++) ans += dp[i][n], ans %= mod;
     cout << ans << endl;
     return 0;
 }
 
