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


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vll v;
    ll strength = 0;
    for (int i = 0; i < n; i++) {
        ll x;
        cin >> x;        
        v.pb(x);
        strength += x;

    }
    sort(v.begin(), v.end());

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        ll d, a;
        cin >> d >> a;
        vector<ll>::iterator lower;
        lower = lower_bound(v.begin(), v.end(), d);
        if (lower == v.end()) lower = v.end() - 1;
        int idx = lower - v.begin();
        if (idx == 0) {
            ll x = (v[idx] >= d) ? 0 : (d - v[idx]);
            ll y = (strength - v[idx] >= a) ? 0 : (a - (strength - v[idx]));
            cout << (x+y) << endl;
        } else {
            ll x = (v[idx-1] >= d) ? 0 : (d - v[idx-1]);
            ll y = (strength - v[idx-1] >= a) ? 0 : (a - (strength - v[idx-1]));
            ll p = (v[idx] >= d) ? 0 : (d - v[idx]);
            ll q = (strength - v[idx] >= a) ? 0 : (a - (strength - v[idx]));
            cout << min(p+q, x+y) << endl;
        }
    }
    return 0;
}
