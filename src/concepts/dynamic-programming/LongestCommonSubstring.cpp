#include <algorithm>
#include <iostream>

using namespace std;

int longestCommonSubstring(string a, string b) {
  int ans = -1;
  int m = a.size();
  int n = b.size();
  int dp[m + 1][n + 1];
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 || j == 0)
        dp[i][j] = 0;
      else if (a[i - 1] == b[j - 1])
        dp[i][j] = dp[i - 1][j - 1] + 1;
      else
        dp[i][j] = 0;
      ans = max(ans, dp[i][j]);
    }
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string a, b;
    cin >> a;
    cin >> b;
    cout << longestCommonSubstring(a, b) << endl;
  }
  return 0;
}
