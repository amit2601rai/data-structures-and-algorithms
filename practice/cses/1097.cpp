#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
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
    int n;
    cin >> n;
    vll v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    vvll dp(n, vll(n, LLONG_MIN));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) dp[i][j] = v[i];
        }
    }
    for (int i = n-1; i >= 0; i--) {
        for (int j = i+1; j < n; j++) {
            dp[i][j] = max(v[i] + min((i+2 <= j ? dp[i+2][j]:0), (i+1 <= j-1 ? dp[i+1][j-1]:0)), 
                           v[j] + min((i <= j-2 ? dp[i][j-2]:0), (i+1 <= j-1 ? dp[i+1][j-1]:0)));
        }
    }
    cout << dp[0][n-1] << endl;
    return 0;
}
