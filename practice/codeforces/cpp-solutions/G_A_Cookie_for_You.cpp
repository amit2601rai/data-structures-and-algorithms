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
        ll a, b, n, m;
        cin >> a >> b >> n >> m;
        if (a+b < n+m) {cout << "No\n";continue;}
        if (min(a,b) >= m) cout << "Yes\n";
        else if (a == 0 && m != 0) cout << "No\n";
        else if (a == b) {
            if (n <= a && m <= b) cout << "Yes\n";
            else cout << "No\n";
        } else if (a > b) {
            if (a-b <= n) {
                a = b;
                n -= b;
                if (n <= a && m <= b) cout << "Yes\n";
                else cout << "No\n";
            } else {
                cout << "No\n";
            }
        } else {
            if (b-a <= n) {
                b = a;
                n -= a;
                if (n <= a && m <= b) cout << "Yes\n";
                else cout << "No\n";
            } else {
                cout << "No\n";
            }
        }
    }
    return 0;
}
