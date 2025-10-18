#include <algorithm>
#include <cstring>
#include <iostream>

#define fill2D(x, v, m, n)    \
  for (int i = 0; i < m; i++) \
    for (int j = 0; j < n; j++) dp[i][j] = v

using namespace std;

int dpSol(char x[]) {
  int len = strlen(x);
  int dp[len][len];
  fill2D(dp, 0, len, len);
  for (int i = 0; i < len; i++) dp[i][i] = 1;
  for (int l = 2; l <= len; l++) {
    for (int i = 0; i <= len - l; i++) {
      int j = i + l - 1;
      if (j == i + 1) {
        if (x[i] == x[j])
          dp[i][j] = 2;
        else
          dp[i][j] = 0;
      } else if (x[i] == x[j])
        dp[i][j] = dp[i + 1][j - 1] + 2;
      else
        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
    }
  }
  return dp[0][len - 1];
}

int main() {
  char x[55];
  cin >> x;
  cout << dpSol(x) << endl;
  return 0;
}
