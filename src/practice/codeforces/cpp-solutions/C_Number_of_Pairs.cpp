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
    while (t--) {
        int n, l, r;
        cin >> n >> l >> r;
        vi v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.begin() + n);
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            vi::iterator low, high;
            high = upper_bound(v.begin()+i+1, v.end(), r-v[i]);
            low = lower_bound(v.begin()+i+1, v.end(), l-v[i]);
            ans += (high - low);
        }
        cout << ans << endl;
    }
    return 0;
}
