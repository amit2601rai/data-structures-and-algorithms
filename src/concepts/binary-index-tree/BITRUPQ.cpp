#include <algorithm>
#include <iostream>

#define MAX 1000

using namespace std;

int tree[MAX + 1];

int read(int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += tree[idx];
    idx -= (idx & -idx);
  }
  return sum;
}

void update(int idx, int val, int n) {
  while (idx <= n) {
    tree[idx] += val;
    idx += (idx & -idx);
  }
}

void build(int a[], int n) {
  for (int i = 1; i <= n; i++) update(i, a[i], n);
}

int main() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(a, n);
  int q, x, y, z;  // update means add z
  cin >> q;
  while (q--) {
    cin >> x >> y >> z;
    if (x == 0) {
      cin >> t;
      update(y, t, n);
      update(z + 1, -t, n);
    } else
      cout << read(z) - read(y - 1) << endl;
  }
  return 0;
}
