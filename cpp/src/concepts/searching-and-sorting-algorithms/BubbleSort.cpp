/*
 * Bubble Sort :
 * Comparison Based Algorithm
 * Complexity : O(n^2)
 */

#include <iostream>

using namespace std;

void print(int a[], int n) {
  for (int i = 0; i < n; i++) {
    cout << a[i] << " ";
  }
  cout << endl;
}

void bubblesort(int a[], int n) {
  int pass = n - 1;
  while (pass--) {
    bool flag = false;
    for (int i = 0; i <= pass; i++) {
      if (a[i] > a[i + 1]) {
        int temp = a[i];
        a[i] = a[i + 1];
        a[i + 1] = temp;
        flag = true;
      }
    }
    if (!flag) break;
  }
}

int main() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 0; i < n; i++) cin >> a[i];
  bubblesort(a, n);
  print(a, n);
  return 0;
}
