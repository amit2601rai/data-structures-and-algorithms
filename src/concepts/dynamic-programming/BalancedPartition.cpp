#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

int balancedPartition(int a[], int n, int sum) {
  bool dp[n + 1][sum + 1];
  for (int i = 0; i <= n; i++) dp[i][0] = true;
  for (int i = 1; i <= sum; i++) dp[0][i] = false;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sum; j++) {
      if (j - a[i] >= 0)
        dp[i][j] = dp[i - 1][j] || dp[i - 1][j - a[i]];
      else
        dp[i][j] = dp[i - 1][j];
    }
  }
  for (int j = sum; j >= 0; j--) {
    if (dp[n][j]) return j;
  }
}

int main() {
  int n;
  cin >> n;
  int a[n + 1];
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  int tmp = sum;
  sum /= 2;
  int firstPartSum = balancedPartition(a, n, sum);
  int secondPartSum = abs(tmp - firstPartSum);
  cout << "First Set Sum = " << firstPartSum << endl;
  cout << "Second Set Sum = " << secondPartSum << endl;
  cout << "Difference = " << abs(firstPartSum - secondPartSum) << endl;
  return 0;
}
