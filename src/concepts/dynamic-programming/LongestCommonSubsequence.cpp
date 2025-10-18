#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>

using namespace std;

int dp[1001][1001];

void LCS(char x[], char y[], int n, int m) {
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (x[i] == y[j])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
    }
  }
  cout << dp[n][m] << endl;
}

int main() {
  int n, m;
  cin >> n >> m;
  char x[n + 1];
  char y[m + 1];
  for (int i = 1; i <= n; i++) cin >> x[i];
  for (int j = 1; j <= m; j++) cin >> y[j];
  LCS(x, y, n, m);
  return 0;
}
