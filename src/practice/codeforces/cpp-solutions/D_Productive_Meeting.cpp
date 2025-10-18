#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef priority_queue<int, vi, greater<int> > minpq;
typedef priority_queue<int> maxpq;

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
        int n;
        cin >> n;
        priority_queue<ii>  q;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x > 0) q.push(mp(x,i));
        }
        vii ans;
        while (q.size() > 1) {
            ii x = q.top();
            q.pop();
            ii y = q.top();
            q.pop();
            ans.pb(mp(x.second,y.second));
            if (x.first - 1 > 0) q.push(mp(x.first - 1, x.second));
            if (y.first - 1 > 0) q.push(mp(y.first - 1, y.second));
        }
        cout << ans.size() << endl;
        for (ii e:ans) {
            cout << e.first << " " << e.second << endl;
        }
    }
    return 0;
}
