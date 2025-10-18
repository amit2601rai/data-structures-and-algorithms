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
        int a = 1, b = n-1;
        int lcm = n-1;
        for (int i = 2; i * i <= n; i++) {
            if (n%i == 0) {
                int f = i, s = n/i;
                if (lcm > n-f) {
                    a = f, b = n-f, lcm = n-f;
                }
                if (lcm > n-s) {
                    a = s, b = n-s, lcm = n-s;
                }
            }
            
        }
        cout << a << " " << b << "\n";
    }
    return 0;
}
