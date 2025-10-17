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
        int n, a, u, c, v, b;
        cin >> n;
        cin >> a >> u;
        cin >> c >> v;
        cin >> b;

        int novels = v - u - 1;
        if (novels < 0) cout << v << "\n";
        else {
            int days = c - a - 1;
            cout << u + (novels * (b - a))/days << endl;
        }
    }
    return 0;
}
