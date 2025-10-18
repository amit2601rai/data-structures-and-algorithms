#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int dp[101][101];

int numOfWays(int coins[], int n, int sum) {
  int dp[n + 1][sum + 1];
  for (int j = 0; j <= sum; j++) dp[0][j] = 0;
  for (int i = 0; i <= n; i++) dp[i][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      dp[i][j] = (j - coins[i] >= 0) ? dp[i][j - coins[i]] + dp[i - 1][j] : dp[i - 1][j];
    }
  }
  return dp[n][sum];
}

int main() {
  int n, sum;
  cin >> n;
  int coins[n + 1];
  for (int i = 1; i <= n; i++) cin >> coins[i];
  cin >> sum;
  cout << numOfWays(coins, n, sum) << endl;
  return 0;
}
