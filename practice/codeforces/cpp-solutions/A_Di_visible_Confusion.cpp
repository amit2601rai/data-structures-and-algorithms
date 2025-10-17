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


int main() { 
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        bool ans = true;
        for (int i = 1; i <= n; i++) {
            int y;
            cin >> y;
            bool ok = false;
            for (int j = (i+1); j >= 2; j--) {
                if (y % j) {
                    ok = true;
                    break;
                }
            }

            ans &= ok;
        }
        if (ans) cout << "YES\n";
        else cout << "NO\n"; 
    }
    return 0;
}