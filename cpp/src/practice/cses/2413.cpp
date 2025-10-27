#include <iostream>
#include <vector>

using namespace std;

constexpr int MOD = 1e9 + 7;
using ll = long long;

int main() {
  int t;
  cin >> t;

  const int MAXN = 1e6 + 5;
  vector<vector<ll>> dp(MAXN, vector<ll>(2, 0));

  // DP State Definition:
  // Think of the tower row-by-row. At each row i, we track the "configuration":
  // dp[i][MERGED] = row i has both columns connected (one horizontal block)
  // dp[i][SPLIT] = row i has both columns independent (two separate blocks)
  const int MERGED = 0;
  const int SPLIT = 1;

  // Base case: height 1
  // We can either place a horizontal block OR two separate 1×1 blocks
  dp[1][MERGED] = 1;  // One horizontal block connecting both columns
  dp[1][SPLIT] = 1;   // Two independent 1×1 blocks

  for (int i = 2; i < MAXN; i++) {
    // To get MERGED at row i:
    // 1. Previous was MERGED → place horizontal (1) OR place 2 verticals side-by-side (1)
    // 2. Previous was SPLIT → place horizontal across both (1)
    dp[i][MERGED] = (dp[i - 1][MERGED] * 2 + dp[i - 1][SPLIT]) % MOD;

    // To get SPLIT at row i:
    // 1. Previous was SPLIT → place 2 new 1×1s (1) OR extend left (1) OR extend right (1) OR extend both (1)
    // 2. Previous was MERGED → place 2 new 1×1s (1)
    dp[i][SPLIT] = (dp[i - 1][SPLIT] * 4 + dp[i - 1][MERGED]) % MOD;
  }

  while (t--) {
    int n;
    cin >> n;

    // Total = all configurations at row n (merged + split)
    ll ans = (dp[n][MERGED] + dp[n][SPLIT]) % MOD;
    cout << ans << endl;
  }

  return 0;
}