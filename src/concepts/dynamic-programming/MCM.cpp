#include <algorithm>
#include <cstring>
#include <iostream>

#define M 1000000
using namespace std;

int dp[1001][1001];

void mcm(int dim[], int n) {
  int j;
  for (int l = 2; l <= n; l++) {
    for (int i = 1; i <= n - l + 1; i++) {
      j = i + l - 1;
      dp[i][j] = M;
      for (int k = i; k <= j - 1; k++) {
        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + dim[i - 1] * dim[k] * dim[j]);
      }
    }
  }
  cout << dp[1][n] << endl;
}

int main() {
  int n;
  cin >> n;
  int dim[n + 1];  // A_i  dim[i-1]*dim[i]
  for (int i = 0; i <= n; i++) cin >> dim[i];
  mcm(dim, n - 1);
  return 0;
}
