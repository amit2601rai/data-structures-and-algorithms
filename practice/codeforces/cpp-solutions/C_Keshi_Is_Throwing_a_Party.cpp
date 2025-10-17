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


bool isPossible(vii v, int target) {
    int invited = 0;
    for (ii p : v) {
        if (p.first < invited) continue;
        if (p.second < target - 1) continue;
        invited++;
        target--;
    }
    return target <= 0;
}


int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vii v;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            v.pb(mp(y,x));
        }

        int low = 1, high = n;
        while (high - low > 1) {
            int mid = (low + high)/2;
            if (isPossible(v, mid)) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
        if (isPossible(v, high)) cout << high << endl;
        else cout << low << endl;
    }
    return 0;
}
