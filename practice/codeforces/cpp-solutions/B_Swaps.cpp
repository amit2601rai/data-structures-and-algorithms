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
        vi posa(2*n+1, -1), posb(2*n+1, -1);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            posa[x] = i;
        }
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            posb[x] = i;
        }
        int k = INT_MAX;
        int ans = INT_MAX;
        for (int j = 2*n; j >= 1; j--) {
            if (j%2 == 0) {
                k = min(k, posb[j]);
            } else {
                ans = min(ans, k+posa[j]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}