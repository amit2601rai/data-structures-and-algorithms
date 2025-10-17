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
    while(t--) {
        int n;
        cin >> n;
        int prev, cur, y = 0;
        cin >> prev;
        cout << y << " ";
        for (int i = 2; i <= n; i++) {
            cin >> cur;
            y = 0;
            for (int j = 0; j < 32; j++) {
                int p = prev & (1 << j);
                int q = cur & (1 << j);
                if (p == (1 << j) && q == 0) {
                    y = y | (1 << j);
                }
            }
            cout << y << " ";
            prev = cur^y;
        }
        cout << endl;
    }
    return 0;
}
