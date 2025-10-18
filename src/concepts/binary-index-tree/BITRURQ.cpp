#include <algorithm>
#include <iostream>

#define MAX 100000

using namespace std;

int tree1[MAX + 1];
int tree2[MAX + 1];

int query1(int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += tree1[idx];
    idx -= (idx & -idx);
  }
  return sum;
}

int query2(int idx) {
  int sum = 0;
  while (idx > 0) {
    sum += tree2[idx];
    idx -= (idx & -idx);
  }
  return sum;
}

int query(int b) { return query1(b) * b - query2(b); }

int query(int a, int b) { return query(b) - query(a - 1); }

void update1(int idx, int val, int n) {
  while (idx <= n) {
    tree1[idx] += val;
    idx += (idx & -idx);
  }
}

void update2(int idx, int val, int n) {
  while (idx <= n) {
    tree2[idx] += val;
    idx += (idx & -idx);
  }
}

void update(int y, int z, int v, int n) {
  update1(y, v, n);
  update1(z + 1, -v, n);
  update2(y, v * (y - 1), n);
  update2(z + 1, -v * z, n);
}

void build(int a[], int n) {
  for (int i = 1; i <= n; i++) update(i, i, a[i], n);
}

int main() {
  int n;
  cin >> n;
  int a[n + 1];
  for (int i = 1; i <= n; i++) cin >> a[i];
  build(a, n);
  int q, x, y, z, t;  // update means add z
  cin >> q;
  while (q--) {
    cin >> x >> y >> z;
    if (x == 0) {
      cin >> t;
      update(y, z, t, n);
    } else
      cout << query(y, z) << endl;
  }
  return 0;
}
