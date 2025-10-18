#include <iostream>

using namespace std;

int bSearch(int a[], int n, int key) {
  int low = 0, high = n - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (a[mid] == key) {
      if (mid == 0 || a[mid - 1] == 0)
        return mid;
      else
        high = mid - 1;
    } else if (a[mid] < key)
      low = mid + 1;
    else
      high = mid - 1;
  }
  return -1;
}

int main() {
  int m, n;
  cin >> m >> n;
  int mat[m][n];
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mat[i][j];
    }
  }

  int ans = 0;
  for (int i = 0; i < m; i++) {
    int x = bSearch(mat[i], n, 1);
    if (x != -1) {
      ans = max(ans, n - x);
    }
  }
  cout << ans << endl;
  return 0;
}
