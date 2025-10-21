#include <iostream>
#include <vector>

using namespace std;

using ll = long long;
constexpr ll MOD = 1e9 + 7;


ll solve(ll n) {
  ll sum = (n * (n + 1)) / 2;
  if (sum % 2 != 0) return 0;

  vector<vector<ll>> dp(n, vector<ll>((sum / 2 )+ 1, 0));
  dp[0][1] = 1;
  for (int i = 0; i < n; i++) dp[i][0] = 1;
  for (int i = 1; i < n; i++) {
    for (int j = 1; j <= sum / 2; j++) {
      dp[i][j] = dp[i-1][j] + (( j-i-1 >= 0) ? dp[i-1][j-i-1] : 0);
      if (dp[i][j] >= MOD) dp[i][j] %= MOD;
    }
  }
  ll modInverse = (MOD + 1) / 2;
  return (dp[n-1][sum/2]*modInverse)%MOD;
}

int main() {
  ll n;
  cin >> n;
  cout << solve(n) << endl;
  return 0;
}
