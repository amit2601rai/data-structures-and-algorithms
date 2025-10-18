#include <iostream>

using namespace std;

long long mulmod(long long a, long long b, long long c) {
  long long x = 0, y = a % c;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x + y) % c;
    }
    y = (y * 2) % c;
    b /= 2;
  }
  return x % c;
}

int power(long long a, long long b, long long m) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = mulmod(x, y, m);  // x=(x*y)%m
    }
    y = mulmod(y, y, m);  // y=(y*y)%m
    b /= 2;
  }
  return x % m;
}

int main() {
  long long a, b, m;
  cin >> a >> b >> m;
  cout << power(a, b, m) << endl;
}
