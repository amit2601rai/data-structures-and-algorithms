#include <algorithm>
#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

int palinPartition(char str[], int n) {
  int c[n][n];
  bool p[n][n];
  for (int i = 0; i < n; i++) {
    p[i][i] = true;
    c[i][i] = 0;
  }
  for (int len = 2; len <= n; len++) {
    for (int i = 0; i <= n - len; i++) {
      int j = i + len - 1;
      if (len == 2)
        p[i][j] = (str[i] == str[j]);
      else
        p[i][j] = (str[i] == str[j]) && p[i + 1][j - 1];
      if (p[i][j])
        c[i][j] = 0;
      else {
        c[i][j] = INT_MAX;
        for (int k = i; k <= j - 1; k++) c[i][j] = min(c[i][j], c[i][k] + c[k + 1][j] + 1);
      }
    }
  }
  return c[0][n - 1];
}

int main() {
  char str[2001];
  cin >> str;
  int n = strlen(str);
  cout << palinPartition(str, n) << endl;
  return 0;
}
