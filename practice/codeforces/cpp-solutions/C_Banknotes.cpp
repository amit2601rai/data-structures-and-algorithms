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

int power(int x, int y) {
    return (int)(pow(x, y) + 0.5);
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<bool> v(10, false);
        int last = -1;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v[x] = true;
            last = x;
        }
        int c = 0;
        int prev = -1;
        ll ans = 0;
        for (int i = 0; i < last; i++) {
            if (c > k) break;
            if (v[i]) {
                ans += 1LL*(min((k+1-c), 9)*power(10, i));
                c += min((k+1-c), 9);
                prev = i;
            } else if(prev != -1) {
                int maxcnt = 9 * power(10, i-prev);
                ans += 1LL*(min((k+1-c), maxcnt)*power(10, prev));
                c += min((k+1-c), maxcnt);
            }
        }
        if (c <= k) {
            ans += 1LL*(k+1-c)*power(10, last);
        }
        cout << ans << endl;
    }
    return 0;
}
