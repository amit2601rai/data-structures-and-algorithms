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

  if (rnk[px] >= rnk[py]) {
    par[py] = px;
    rnk[px] += rnk[py];
  } else {
    par[px] = py;
    rnk[py] += rnk[px];
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> par(n + 1);
  for (int i = 1; i <= n; ++i) {
    par[i] = i;
  }
  vector<int> rnk(n + 1, 1);
  int c = n;
  int largest_rnk = 1;
  while (m--) {
    int u, v;
    cin >> u >> v;
    int pu = find(u, par);
    int pv = find(v, par);

    if (unionSet(u, v, par, rnk)) {
      c--, largest_rnk = max(largest_rnk, max(rnk[pu], rnk[pv]));
    }
    cout << c << " " << largest_rnk << endl;
  }
  return 0;
}