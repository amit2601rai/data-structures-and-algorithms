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
        vi v(n);
        int min_el = INT_MAX;
        for (int i = 0; i < n; i++) {
            cin >> v[i];
            min_el = min(min_el, v[i]);
        }
        vi u;
        for (int i = 0; i < n; i++) {
            if (v[i]%min_el == 0) u.pb(v[i]);
        }
        sort(u.begin(), u.end());
        int k = 0;
        for (int i = 0; i < n; i++) {
            if(v[i]%min_el == 0) v[i] = u[k++];
        }
        bool is_possible = true;
        for (int i = 1; i < n; i++) {
            if (v[i-1] > v[i]) {
                is_possible = false;
                break;
            }
        }
        if (is_possible) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}