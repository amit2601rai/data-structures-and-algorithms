#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ll> vll;
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

ll mindist(vi v, int k) {
    int n = v.size();
    if (n == 0) return 0;
    ll dist = 0;
    if (k > n) dist += v[n%k-1];
    else if(n%k != 0) dist += 2*v[n%k-1];
    for (int i = n%k; i < n; i += k) {
        int j = i+k-1;
        if (j == n-1) dist += v[j];
        else dist += 2*v[j];
    }
    return dist;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vi neg, pos;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int val;
            cin >> val;
            if (val == 0) continue;
            if (val < 0) neg.pb(-1*val);
            else pos.pb(val);
        }
        sort(neg.begin(), neg.end());
        sort(pos.begin(), pos.end());
        ll ans = mindist(neg, k) + mindist(pos, k);
        if (neg.size() > 0 && pos.size() > 0) ans += min(neg[neg.size()-1], pos[pos.size()-1]);
        cout << ans << endl;
    }
    return 0;
}
