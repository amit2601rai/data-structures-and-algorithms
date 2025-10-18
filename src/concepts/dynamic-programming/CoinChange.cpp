#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>

using namespace std;

int method1() {
  int n, c, temp;
  cin >> n >> c;
  int dp[c + 1];
  for (int i = 0; i <= c; i++) dp[i] = INT_MAX;
  for (int i = 1; i <= n; i++) {
    cin >> temp;
    dp[temp] = 1;
  }
  int low, high;
  for (int i = 2; i <= c; i++) {
    low = 1;
    high = i - 1;
    while (low <= high) {
      dp[i] = min(dp[i], dp[low] + dp[high]);
      low++;
      high--;
    }
  }
  return dp[c];
}

int method2() {
  int n, c;
  cin >> n >> c;
  int coinval[n + 1];
  for (int i = 1; i <= n; i++) cin >> coinval[i];
  int dp[c + 1];
  dp[0] = 0;
  for (int j = 1; j <= c; j++) {
    dp[j] = INT_MAX;
    for (int i = 1; i <= n; i++)
      if (j - coinval[i] >= 0) dp[j] = min(dp[j], dp[j - coinval[i]] + 1);
  }
  return dp[c];
}

int main() {
  cout << method1() << endl;
  cout << method2() << endl;
  return 0;
}
