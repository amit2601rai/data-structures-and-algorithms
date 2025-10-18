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

int power(int a, int b) {
    ll mul = 1;
    while(b--) {
        mul *= a;
        if (mul >= mod) mul %= mod;
    }
    return mul;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        ll ans = 0;
        for (int i = 0; i < 31; i++) {
            if ((1<<i)&k) {
                ans += power(n, i);
                if (ans >= mod) ans %= mod;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
