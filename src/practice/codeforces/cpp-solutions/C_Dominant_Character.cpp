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


int solve(string p, string t) {
    int ans = INT_MAX;
    do {  
        if (t.find(p) != string::npos) {
            ans = p.size();
            return ans;
        } 
    } while (next_permutation(p.begin(), p.end()));
    return ans;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        int ans = solve("aa", s);
        ans = min(ans, solve("aab", s));
        ans = min(ans, solve("aac", s));
        ans = min(ans, solve("aabc", s));
        ans = min(ans, solve("aaabbcc", s));
        if (ans == INT_MAX) cout << "-1" << endl;
        else cout <<ans << endl;
    }
    return 0;
}
