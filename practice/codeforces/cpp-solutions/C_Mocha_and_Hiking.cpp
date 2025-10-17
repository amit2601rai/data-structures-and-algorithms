#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef priority_queue<int, vi, greater<int> > minHeap;
typedef priority_queue<int> maxHeap;

#define mod 1000000007
#define pb push_back
#define mp make_pair


void dfs(vi g[], vb &vis, vi &path, int s) {
    for (int i = 0; i < g[s].size(); i++) {
        int el = g[s][i];
        if (!vis[el]) {
            vis[el] = true;
            path.pb(el);
            dfs(g, vis, path, el);
        }
    }
}

void printPath(vi path) {
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int v = n+1;
        vi g[v+1];
        for (int i = 1; i <= n-1; i++) {
            g[i].pb(i+1);
        }

        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x == 0) g[i].pb(v);
            else g[v].pb(i);
        }

        vb visf(v+1, false);
        vi pathf;
        // dfs from 1
        pathf.pb(1);
        visf[1] = true;
        dfs(g, visf, pathf, 1);

        if (pathf.size() == v) {
            printPath(pathf);
            continue;
        } 

        vb viss(v+1, false);
        vi paths;
        // dfs from v
        paths.pb(v);
        viss[v] = true;
        dfs(g, viss, paths, v);
        if (paths.size() == v) {
            printPath(paths);
            continue;
        }

        cout << "-1" << endl;

    }
    return 0;
}