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
        char c;
        string s;
        cin >> n >> c;
        cin >> s;
        vi v;
        vi u(n+1, 0);

        for (int i = 0; i < n; i++) {
            if (s[i] != c) v.pb(i+1);
            else u[i+1] = 1;
        }

        vi p;
        for (int i = n/2+1; i <= n; i++) {
            if (u[i]) p.pb(i);
        }

        if (p.size() == 0) {
            p.push_back(n);
            p.push_back(n-1);
        }

        int counter = 0;
        vi xs;
        for (int i = 0; i < p.size(); i++) {
            bool flag = false;
            for (int j = 0; j < v.size(); j++) {
                if (v[j] != -1 && v[j]%p[i] != 0) {
                    flag = true;
                    counter++;
                    v[j] = -1;
                }
            }
            if (flag) xs.pb(p[i]);
            if (counter >= v.size()) break;
        }
       
        cout << xs.size() << endl;
        for (int i = 0; i < xs.size(); i++) cout << xs[i] << " ";
        cout << endl;
    }
    return 0;
}
