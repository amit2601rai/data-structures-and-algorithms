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
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vi b(m+1), k;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            k.pb(x);
        }
        for (int i = 0; i < m; i++) {
            int x;
            cin >> x;
            b[i+1] = x;
        }
        sort(k.rbegin(), k.rend());
        ll ans = 0;
        int low = 1;
        for (int q:k) {
            if (low <= m && low <= q) ans += b[low++];
            else ans += b[q];
        }
        cout << ans << endl;
    }
    return 0;
}
