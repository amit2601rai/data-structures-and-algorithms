#include <cstdio>
#include <iostream>

using namespace std;

void print(int b[], int low, int high) {
  for (int i = low; i <= high; i++) cout << b[i] << " ";
  cout << endl;
}

void countingsort(int a[], int b[], int k, int n) {
  int c[k + 1];

  for (int i = 0; i <= k; i++) c[i] = 0;
  for (int i = 0; i < n; i++) c[a[i]] = c[a[i]] + 1;
  // now c contain the number of element equal to i
  for (int i = 1; i <= k; i++) c[i] = c[i] + c[i - 1];
  // now c contains the numebr of elements less than or equal to i
  for (int j = n - 1; j >= 0; j--) {
    b[c[a[j]]] = a[j];
    c[a[j]] = c[a[j]] - 1;
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  int a[n + 1];
  int b[n + 1];
  for (int i = 0; i < n; i++) cin >> a[i];
  countingsort(a, b, k, n);
  print(b, 1, n);
  return 0;
}
