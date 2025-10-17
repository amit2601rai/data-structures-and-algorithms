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

vi g(4e5+1);
vector<bool> vis(4e5+1, false); 
vector<vector<int>> v(2, vector<int>(4e5+1));

void cycles(int x) {
    int y = x;
    do {
        vis[y] = true;               
        y = g[y];       
    } while (y != x);
}

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int k = 0; k < 2; k++) {
            for (int i = 1; i <= n; i++) {
                cin >> v[k][i];
            }
        }

        for (int i = 1; i <= n; i++) {
            g[v[0][i]] = v[1][i];
            vis[v[0][i]] = false;
        }
        
        ll ans = 1;
        for (int i = 1; i <= n; i++) {
            if (!vis[v[0][i]]) {
                ans *= 2;
                ans %= mod;
                cycles(v[0][i]);
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
