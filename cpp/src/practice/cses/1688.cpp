#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;
const int INF = 1e9;

void preprocess(vector<vector<int>>& graph, vector<int>& depth, vector<vector<int>>& up, int source, vector<int> parent,
                int n, int k) {
  for (int i = 1; i <= n; i++) {
    if (i == 1) {
      up[i][0] = -1;
      continue;
    }
    up[i][0] = parent[i];
  }

  for (int j = 1; j < k; j++) {
    for (int i = 1; i <= n; i++) {
      if (i == 1) {
        up[i][j] = -1;
        continue;
      }
      up[i][j] = (up[i][j - 1] != -1) ? up[up[i][j - 1]][j - 1] : -1;
    }
  }

  queue<int> q;
  q.push(source);
  depth[source] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int v : graph[u]) {
      if (depth[v] == INF) {
        depth[v] = depth[u] + 1;
        q.push(v);
      }
    }
  }
}

int lca(int a, int b, vector<vector<int>>& up, vector<int>& depth) {
  if (depth[a] < depth[b]) swap(a, b);

  // Bring a to same level as b
  int diff = depth[a] - depth[b];
  for (int j = 20; j >= 0; j--) {
    if ((diff >> j) & 1) {
      a = up[a][j];
    }
  }

  if (a == b) return a;

  // Binary search for LCA
  for (int j = 20; j >= 0; j--) {
    if (up[a][j] != up[b][j]) {
      a = up[a][j];
      b = up[b][j];
    }
  }
  return up[a][0];
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<vector<int>> graph(n + 1);
  vector<int> parent(n + 1, -1);
  vector<int> depth(n + 1, INF);
  for (int i = 2; i <= n; i++) {
    int u;
    cin >> u;
    parent[i] = u;
    graph[u].push_back(i);
  }
  vector<vector<int>> up(n + 1, vector<int>(21, 0));
  preprocess(graph, depth, up, 1, parent, n, 21);

  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << lca(a, b, up, depth) << endl;
  }
  return 0;
}