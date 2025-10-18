#include <algorithm>
#include <iostream>

using namespace std;

int longestAM(int a[], int n) {
  int llap = -1;
  int dp[n + 1][n + 1];
  for (int i = n - 1; i >= 1; i--) dp[i][n] = 2;
  for (int j = n - 1; j >= 2; j--) {
    int i = j - 1, k = j + 1;
    while (i >= 1 && k <= n) {
      if (a[i] + a[k] < 2 * a[j]) {
        k++;
      } else if (a[i] + a[k] > 2 * a[j]) {
        dp[i][j] = 2;
        i--;
      } else {
        dp[i][j] = dp[j][k] + 1;
        llap = max(llap, dp[i][j]);
        i--;
        k++;
      }
    }
    while (i >= 1) {
      dp[i][j] = 2;
      i--;
    }
  }
  return llap;
}

int main() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a + 1, a + n + 1);
  cout << longestAM(a, n) << endl;
  return 0;
}
