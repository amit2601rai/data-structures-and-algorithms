#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int find(int x, vector<int>& par) {
  if (x == par[x]) return x;
  return par[x] = find(par[x], par);
}

bool unionSet(int x, int y, vector<int>& par, vector<int>& rnk) {
  int px = find(x, par);
  int py = find(y, par);

  if (px == py) return false;

  if (rnk[px] > rnk[py]) {
    par[py] = px;
  } else if (rnk[px] == rnk[py]) {
    par[py] = px;
    rnk[px]++;
  } else {
    par[px] = py;
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<tuple<ll, int, int>> edges;
  while (m--) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    edges.push_back({w, u, v});
  }

  vector<int> par(n + 1);
  for (int i = 1; i <= n; ++i) {
    par[i] = i;
  }
  vector<int> rnk(n + 1, 0);

  sort(edges.begin(), edges.end());

  ll ans = 0;
  int tree = 0;
  for (auto [w, u, v] : edges) {
    if (unionSet(u, v, par, rnk)) {
      ans += w;
      tree++;
    }
    if (tree == n - 1) break;
  }

  if (tree == n - 1)
    cout << ans << endl;
  else
    cout << "IMPOSSIBLE" << endl;

  return 0;
}