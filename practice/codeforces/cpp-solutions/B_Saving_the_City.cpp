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
        int a, b;
        string s;
        cin >> a >> b;
        cin >> s;
        int cost = 0;
        int m = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0' && cost == 0) continue;
            else if (s[i] == '0' && cost != 0) m++;
            else if (s[i] == '1' && m > 0) {
                cost -= a;
                cost += min(a + m*b, 2*a);
                m = 0;
            } else if (cost == 0) {
                cost = a;
            } 
        }
        cout << cost << endl;
    }
    return 0;
}
