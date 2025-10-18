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


int next(int x) {
    return x + x%10;
}

bool isAllElementsSame(vi v, int n) {
    for (int i = 1; i < n; i++) {
        if (v[i] != v[i-1]) return false;
    }
    return true;
}

bool isAllElementsWithSameRemainder(vi v, int n, int p, int q) {
    for (int i = 0; i < n; i++) {
        if (v[i] % p != q) return false;
    }
    return true;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n;
        cin >> n;
        vi v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        bool f = false;
        for (int i = 0; i < n; i++) {
             v[i] = next(v[i]);
             if (v[i]%10 == 0) {
                f = true;
             } else {
                while (v[i]%10 != 2) {
                    v[i] = next(v[i]);
                }
             }
        }
        if (f && isAllElementsSame(v, n)) {
            cout << "Yes\n";
        } else if (isAllElementsWithSameRemainder(v, n, 20, 2) || isAllElementsWithSameRemainder(v, n, 20, 12)) {
             cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}