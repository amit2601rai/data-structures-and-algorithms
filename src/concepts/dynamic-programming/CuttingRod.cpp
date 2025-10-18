#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

int main() {
  int n;
  cin >> n;
  int price[n + 1];
  for (int i = 1; i <= n; i++) cin >> price[i];
  int dp[n + 1];
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i] = INT_MIN;
    for (int j = 1; j <= i; j++) {
      dp[i] = max(dp[i], dp[i - j] + price[j]);
    }
  }
  cout << dp[n] << endl;
}
