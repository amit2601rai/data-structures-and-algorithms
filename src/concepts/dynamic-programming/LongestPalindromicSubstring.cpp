#include <algorithm>
#include <climits>
#include <cstring>
#include <iostream>

using namespace std;

int longestPalindromicSubtstring(char x[]) {
  int n = strlen(x);
  if (n == 0) return 0;
  bool dp[n][n];
  int ans = 1;
  for (int i = 0; i < n; i++) dp[i][i] = true;
  for (int len = 2; len <= n; len++) {
    for (int i = 0; i < n - len + 1; i++) {
      int j = i + len - 1;
      if (j - i == 1)
        dp[i][j] = (x[i] == x[j]);
      else
        dp[i][j] = dp[i + 1][j - 1] && (x[i] == x[j]);
      if (dp[i][j]) ans = max(ans, j - i + 1);
    }
  }
  return ans;
}

int main() {
  char x[100001];
  cin >> x;
  cout << longestPalindromicSubtstring(x) << endl;
  return 0;
}
