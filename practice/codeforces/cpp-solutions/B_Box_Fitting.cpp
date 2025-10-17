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
        int n, w;
        cin >> n >> w;
        vi v(21);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            v[log2(x)]++;
        }
        
        int level = 0;
        while(n > 0) {
            int sum = 0;
            for (int i = 20; i >= 0; i--) {
                while (v[i] > 0 && (sum + (1 << i)) <= w) {
                    sum += (1 << i);
                    n--, v[i]--;
                }
            }
            level++;
        }
        cout << level << endl;
    }
    return 0;
}
