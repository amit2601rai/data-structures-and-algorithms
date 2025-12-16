#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<bool>> flight(n + 1, vector<bool>(n + 1, false));
  vector<vector<int>> pred(n + 1);  // predecessors: u -> v stored at pred[v]

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    flight[x][y] = true;
    pred[y].push_back(x);
  }

  int mask = 1 << n;
  vector<vector<ll>> dp(mask, vector<ll>(n + 1, 0));

  dp[1 << 0][1] = 1;

  for (int i = 0; i < mask; i++) {
    if ((i & 1) == 0) continue;  // must include city 1
    for (int j = 1; j <= n; j++) {
      if (!(i & (1 << (j - 1)))) continue;    // j must be in mask
      if (j == n && i != mask - 1) continue;  // don't reach n early
      int k = i ^ (1 << (j - 1));
      if (k == 0) continue;    // keep base state intact
      for (int l : pred[j]) {  // iterate only real predecessors
        if (k & (1 << (l - 1))) {
          dp[i][j] += dp[k][l];
          if (dp[i][j] >= MOD) dp[i][j] %= MOD;
        }
      }
    }
  }

  cout << dp[mask - 1][n] << endl;

  return 0;
}