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

vector<vector<int>> graph(1003, vector<int>(1003, 0));
vector<vector<bool>> vis(1003, vector<bool>(1003, false));
int n, m;

void dfs(int x, int y, int &sz) {
    vis[x][y] = true;
    // West
    if (!(graph[x][y] & 1)) {
        if (y-1 >= 0 && !vis[x][y-1]) {
            dfs(x, y-1, ++sz);
        }
    }
    // South
    if (!(graph[x][y] & 2)) {
        if (x+1 < n && !vis[x+1][y]) {
            dfs(x+1, y, ++sz);
        }
    }
    // East
    if (!(graph[x][y] & 4)) {
        if (y+1 < m && !vis[x][y+1]) {
            dfs(x, y+1, ++sz);
        }
    }
    // North
    if (!(graph[x][y] & 8)) {
        if (x-1 >= 0 && !vis[x-1][y]) {
            dfs(x-1, y, ++sz);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) { 
            cin >> graph[i][j];
        }
    }
    vi ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(!vis[i][j]) {
                int sz = 1;
                dfs(i, j, sz);
                ans.pb(sz);
            }
        }
    }
    sort(ans.rbegin(), ans.rend());
    for (int r:ans) cout << r << " ";
    cout << endl;
    return 0;
}
