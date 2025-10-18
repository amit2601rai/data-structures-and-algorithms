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


int maxcommon(string sn, string sx) {
    int pn = 0, px = 0;
    int c = 0;
    while (pn < sn.length()) {
        if (sn[pn] == sx[px]) {
            c++, px++;
        }
        pn++;
    }
    return c;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string sn = to_string(n);
        int ans = INT_MAX;
        for (int i = 0; i <= 60; i++) {
            ll one = 1;
            ll x = one << i;
            string sx = to_string(x);
            ans = min(ans, (int)sn.length() + (int)sx.length() - 2*maxcommon(sn, sx));
        }
        cout << ans << endl;
    }
    return 0;
}
