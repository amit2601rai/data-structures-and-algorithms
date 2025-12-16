#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  struct edge {
    int a;
    int b;
    ll c;
  };
  vector<edge> edges;

  for (int i = 1; i <= m; i++) {
    edge e;
    cin >> e.a >> e.b >> e.c;
    edges.push_back(e);
  }

  for (int i = 1; i <= n; i++) {
    edge e;
    e.a = 0;
    e.b = i;
    e.c = 0;
    edges.push_back(e);
  }

  vector<int> parent(n + 1, 0);
  vector<long long> dist(n + 1, 0);

  int x = -1;
  for (int i = 0; i <= n; i++) {
    x = -1;
    for (const edge& e : edges) {
      if (dist[e.a] + e.c < dist[e.b]) {
        dist[e.b] = dist[e.a] + e.c;
        parent[e.b] = e.a;
        x = e.b;
      }
    }
  }

  if (x == -1) {
    cout << "NO" << endl;
    return 0;
  }

  int cycle_start = x;
  for (int i = 0; i < n; ++i) cycle_start = parent[cycle_start];

  vector<int> ans;
  for (int v = cycle_start;; v = parent[v]) {
    ans.push_back(v);
    if (v == cycle_start && ans.size() > 1) break;
  }
  reverse(ans.begin(), ans.end());
  cout << "YES\n";
  for (int v : ans) cout << v << ' ';
  cout << '\n';

  return 0;
}