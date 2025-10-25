#include <cstdio>
#include <iostream>

#define FOR(i, a, b) for (int i = a; i <= b; i++)
#define p(x) printf("%d\n", x)

using namespace std;

int missingNumber(int a[], int n) {
  int sz = n - 1;
  int xorSum = 0;
  FOR(i, 0, sz - 1) xorSum ^= a[i];
  FOR(i, 1, n) xorSum ^= i;
  return xorSum;
}

int main() {
  int n, sz;
  cin >> n;
  sz = n - 1;
  int a[sz];
  for (int i = 0; i < sz; i++) cin >> a[i];
  p(missingNumber(a, n, sz));
}
