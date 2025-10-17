/*Amit Rai (IIIT Hyderabad)*/
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define pb push_back
#define mp make_pair


int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vi v;
        for (int i = 0; i < n; i++) {
            int x;
            cin>>x;
            v.pb(x);
        }
        sort(v.begin(), v.end());

        int dp[205][405];
        for(int i = 0; i < 205; i++) for(int j = 0; j < 405; j++) dp[i][j] = 1e9;
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for(int j = 0; j < 2*n - 1; j++) {
                if(dp[i][j] < 1e9) {
                    if(i < n) dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]+abs(j-v[i]));
                    dp[i][j+1] = min(dp[i][j+1], dp[i][j]);
                }
            }
        }
        cout<<dp[n][2*n-1]<<endl;
    }
    return 0;
}