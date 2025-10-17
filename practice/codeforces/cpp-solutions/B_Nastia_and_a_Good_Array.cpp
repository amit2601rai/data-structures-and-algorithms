#include <bits/stdc++.h>0

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
    int n;
    vi dp(n+1);
    dp[1] = dp[2] = 4;
    for (int i = 3; i <= n; i++) {
        if (i%2) dp[i] = dp[i-1] + 1;
        else dp[i] = 2*dp[i-1] + dp[i-2];
    }
    cout << dp[n] << endl;
    return 0;
}
