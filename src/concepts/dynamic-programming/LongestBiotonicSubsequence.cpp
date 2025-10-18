#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int start[101];
int end[101];

void lis_start(int a[], int n) {
  for (int i = 1; i <= n; i++) start[i] = 1;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (a[j] < a[i]) start[i] = max(start[i], start[j] + 1);
    }
  }
}

void lis_end(int a[], int n) {
  for (int i = 1; i <= n; i++) end[i] = 1;
  for (int i = n - 1; i >= 1; i--) {
    for (int j = n; j > i; j--) {
      if (a[j] < a[i]) end[i] = max(end[i], end[j] + 1);
    }
  }
}

int main() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  lis_start(a, n);
  lis_end(a, n);
  int ans = -1;
  for (int i = 1; i <= n; i++) ans = max(ans, start[i] + end[i] - 1);
  cout << ans << endl;
}
