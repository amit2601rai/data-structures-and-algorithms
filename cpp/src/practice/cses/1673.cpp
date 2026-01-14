#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  const ll kInf = -1e18;
  const ll inf = 1e18;
  vector<ll> dist(n + 1, kInf);
  vector<tuple<int, int, long long>> edges;  // (u, v, w)
  while (m--) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    edges.push_back({u, v, w});
  }

  dist[1] = 0;
  for (int i = 1; i <= n - 1; ++i) {
    for (auto [u, v, w] : edges) {
      if (dist[u] > kInf && dist[v] < dist[u] + w) {
        dist[v] = dist[u] + w;
      }
    }
  }

  // Run n more iterations to mark nodes affected by positive cycles
  for (int i = 0; i < n; i++) {
    for (auto [u, v, w] : edges) {
      if (dist[u] > kInf) {
        if (dist[v] < dist[u] + w) {
          dist[v] = inf;  // Mark as affected by positive cycle
        }
        if (dist[u] == inf) {
          dist[v] = inf;  // Propagate the marking
        }
      }
    }
  }

  if (dist[n] >= inf)
    cout << "-1" << endl;
  else
    cout << dist[n] << endl;

  return 0;
}
