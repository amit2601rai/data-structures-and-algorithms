#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  int n, ans = -1;
  cin >> n;
  int dp[n + 1];
  int input[n + 1];
  for (int i = 1; i <= n; i++) cin >> input[i];
  dp[1] = input[1];
  for (int i = 2; i <= n; i++) {
    dp[i] = max(input[i], input[i] + dp[i - 1]);
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
  return 0;
}
