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


bool solve(string s) {
    int c1, c2;
    c1 = c2 = 0;
    for (int i = 1; i < s.size(); i++) {
        if (s[i-1] == 'a' && s[i] == 'b') c1++;
        if (s[i-1] == 'b' && s[i] == 'a') c2++;
    }
    return (c1 == c2);
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        string p, q;
        p = q = s;
        if (s[0] == 'a') p[0] = 'b';
        else p[0] = 'a';
        if (s[n-1] == 'a') q[n-1] = 'b';
        else q[n-1] = 'a';

        if (solve(s)) cout << s << endl;
        else if (solve(p)) cout << p << endl;
        else cout << q << endl;
    }
    return 0;
}
