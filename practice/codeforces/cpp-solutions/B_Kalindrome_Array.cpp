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


bool isPalin(vi u) {
    int low = 0, high = u.size()-1;
    while (low < high) {
        if (u[low] != u[high])  return false;
        low++, high--;
    }
    return true;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        int low = 0, high = n-1;
        bool flag = false;
        while (low < high) {
            if (v[low] != v[high]) {
                flag = true;
                break;
            }
            low++, high--;
        }
        if (!flag) cout << "YES\n";
        else {
            vi x, y;
            for (int i = 0; i < n; i++) {
                if (v[low] != v[i]) x.pb(v[i]);
                if (v[high] != v[i]) y.pb(v[i]);
            }
            if (isPalin(x) || isPalin(y)) cout << "YES\n";
            else cout << "NO\n";
        }

    }
    return 0;
}
