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
struct s {
    int idx;
    int color;
};

bool compidx(s a, s b) {
    if (a.idx < b.idx) return true;
    else return false;
}

int main(){
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<s> v[n+1];
        for (int i = 0; i < n; i++) { 
            int x;
            cin >> x;
            s u;
            u.color = 0, u.idx = i;
            v[x].pb(u);
        }
        vector<s> ans;
        vector<s> lessthank;
        for (int i = 1; i <= n ; i++) {
            if (v[i].size() < k) {
                lessthank.insert(lessthank.end(), v[i].begin(), v[i].end());
            } else {
                for (int j = 0; j < k; j++) {
                    v[i][j].color = j+1;
                }
                ans.insert(ans.end(), v[i].begin(), v[i].end());
            }
        }
        int itr = lessthank.size()/k;
        int j = 0;
        while(itr--) {
            for (int c = 1; c <= k; c++) {
                s u = lessthank[j++];
                u.color = c;
                ans.pb(u);
            }
        }
        itr = lessthank.size()/k;
        for (int l = itr*k; l < lessthank.size(); l++) {
            ans.pb(lessthank[l]);
        }
        sort(ans.begin(), ans.end(), compidx);
        for (int i = 0; i < ans.size(); i++) cout << ans[i].color << " ";
        cout << endl;
    }
    return 0;
}