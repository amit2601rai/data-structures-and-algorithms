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
    int n;
    cin >> n;
    map<int, int> mp;
    while (n--) {
        int x, y;
        cin >> x >> y;
        mp[x]++;
        mp[y]--;
    }
    int prev = 0;
    for (ii q:mp) {
        if (prev != 0) mp[q.first] += mp[prev];
        prev = q.first;
    } 
    int ans = INT_MIN;
    int y = 0;
    for (ii q:mp) {
        if (q.second > ans) ans = q.second, y = q.first;
    }
    cout << y << " " << ans << endl;
    return 0;
}
