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


pair<ll,ll> getTime(ll k) {
    ll t = 0;
    ll c = 1;
    while (c < k) {
        c = c*2;
        t++;
    }
    return mp(t, c);
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        pair<ll,ll> p = getTime(k);
        ll cnum = p.second;
        ll kt = p.first;
        if (cnum < n) {
            ll diff = n - cnum;
            kt += (n-cnum)/k;
            if (diff % k != 0) kt++;
        }
        cout << kt << endl;
    }
    return 0;
}
