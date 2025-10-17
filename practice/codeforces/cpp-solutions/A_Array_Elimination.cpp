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
        int n;
        cin >> n;
        vi v(32, 0);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            for (int k = 0; k < 32; k++) {
                if (x&(1<<k)) v[k]++;
            }
        }
        map<int, int> div;
        for (int i = 0; i < 32; i++) {
            int y = v[i];
            if (y == 0) {
                for (int j = 1; j <= n; j++) {
                    div[j]++;
                }
                continue;
            }
            for (int k = 1; k*k <= y; k++) {
                if (y % k == 0) {
                    div[k]++;
                    if (k != y/k) div[y/k]++;
                }
            }
        }
        for (pair<int, int> p : div) {
            if (p.second == 32) cout << p.first << " ";
        }
        cout << endl;
    }
    return 0;
}
