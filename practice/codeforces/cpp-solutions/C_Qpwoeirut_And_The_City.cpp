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

ll traverse(int start, vi v, int n) {
    ll b = 0;
    for (int i = start, j = i + 1, k = j + 1; k < n; i += 2, j += 2, k += 2) {
        if (v[j] <= v[i] || v[j] <= v[k]) {
            cout << "v[i] : " << v[i] << " v[j] : " << v[j] << " v[k] : " << v[k] << endl;
            cout << "delta : "<< abs(v[j] - max(v[i], v[k])) << endl;
            b += (1 + abs(v[j] - max(v[i], v[k])));
            cout << b << endl;
        }
    }
    cout << "b = "<< b << endl;
    return b;
}

ll traverse3(vi v, int n) {
    ll b = 0;
    for (int i = 0, j = 1, k = 2; k < n; i += 3, j += 3, k += 3) {
        if (v[j] <= v[i] || v[j] <= v[k]) {
            b += (1 + abs(v[j] - max(v[i], v[k])));
        }
    }
    return b;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vi v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        if (n == 6) cout << min(traverse(0, v, n), min(traverse(1, v, n), traverse3(v, n))) << endl;
        else if (n%2 == 0) cout << min(traverse(0, v, n), traverse(1, v, n)) << endl;
        else cout << traverse(0, v, n) << endl;
    }
    return 0;
}