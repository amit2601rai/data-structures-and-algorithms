#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

/*
dp[i][j] : Is STR3[0....i+j-1] interleaved string of STR1[0...i-1] And STR2[0...j-1]?
*/
bool isInterleave(string a, string b, string c) {
  int m = a.size();
  int n = b.size();
  int p = c.size();
  if (m + n != p) return false;
  bool dp[m + 1][n + 1];
  memset(dp, false, sizeof(dp));
  for (int i = 0; i <= m; i++) {
    for (int j = 0; j <= n; j++) {
      if (i == 0 && j == 0)
        dp[i][j] = true;
      else if (i == 0 && b[j - 1] == c[j - 1])
        dp[i][j] = dp[i][j - 1];
      else if (j == 0 && a[i - 1] == c[i - 1])
        dp[i][j] = dp[i - 1][j];
      else if (a[i - 1] == c[i + j - 1] && b[j - 1] != c[i + j - 1])
        dp[i][j] = dp[i - 1][j];
      else if (a[i - 1] != c[i + j - 1] && b[j - 1] == c[i + j - 1])
        dp[i][j] = dp[i][j - 1];
      else if (a[i - 1] == c[i + j - 1] && b[j - 1] == c[i + j - 1])
        dp[i][j] = (dp[i][j - 1] || dp[i - 1][j]);
    }
  }
  return dp[m][n];
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    string a, b, c;
    cin >> a;
    cin >> b;
    cin >> c;
    cout << isInterleave(a, b, c) << endl;
  }
  return 0;
}
