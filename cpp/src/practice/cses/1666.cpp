#include <iostream>
#include <vector>

using namespace std;

void dfs(int s, vector<vector<int>>&v, vector<bool> &vis) {
  vis[s] = true;
  for (int i = 0; i < v[s].size(); i++) {
    if (!vis[v[s][i]]) dfs(v[s][i], v, vis);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> v(n + 1);
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }

  vector<bool> vis(n + 1, false);

  vector<int> rep;

  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      dfs(i, v, vis);
      rep.push_back(i);
    }
  }

  cout << rep.size() - 1 << endl;

  for (int i = 1; i < rep.size(); i++) {
    cout << rep[i-1] << " " << rep[i] << endl;
  }

  return 0;
}