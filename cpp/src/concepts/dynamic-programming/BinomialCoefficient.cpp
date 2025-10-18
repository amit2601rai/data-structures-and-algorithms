/*  C(n, k) = C(n-1, k-1) + C(n-1, k)
    C(n, 0) = C(n, n) = 1
*/

#include <iostream>

using namespace std;

int cal(int n, int k) {
  int C[n + 1][k + 1];
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= min(n, k); j++) {
      if (j == 0 || j == i)
        C[i][j] = 1;
      else
        C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
    }
  return C[n][k];
}

int main() {
  int n, k;
  cin >> n >> k;
  cout << cal(n, k) << endl;
  return 0;
}
