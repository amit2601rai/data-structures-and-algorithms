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
        string s;
        cin >> s;
        int n = s.length();
        vi u(n, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] == '+') u[i] += 1;
            else u[i] -= 1;
        }
        int minval = u[0];
        for (int i = 1; i < n; i++) {
            u[i] += u[i-1];
            minval = min(minval, u[i]);
        }
        if (minval >= 0) cout << n << endl;
        else {
            ll ans = 0;
            minval = (-1)*minval;
            int k = 0;
            for (int cur = 0; cur < minval; cur++) {
                while (k < n && u[k] + cur >= 0) {
                    k++;
                }
                ans += (k+1);
            }
            ans += n;
            cout << ans << endl;
        }
    }
    return 0;
}
