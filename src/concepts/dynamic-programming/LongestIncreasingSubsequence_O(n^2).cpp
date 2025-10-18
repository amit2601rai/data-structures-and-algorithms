#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>

using namespace std;

int dp[1001];

void LIS(int a[], int n) {
  int ans = -1;
  for (int i = 1; i <= n; i++) {
    for (int j = i - 1; j >= 1; j--) {
      if (a[j] < a[i]) {
        dp[i] = max(dp[i], dp[j] + 1);
      }
    }
    ans = max(ans, dp[i]);
  }
  cout << ans << endl;
}

int main() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    dp[i] = 1;
  }
  LIS(a, n);
  return 0;
}
