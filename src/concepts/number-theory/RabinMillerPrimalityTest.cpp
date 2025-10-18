#include <cstdlib>
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

int power(long a, long long b, long long m) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = mulmod(x, y, m);
    }
    y = mulmod(y, y, m);
    b /= 2;
  }
  return x % m;
}

bool rabinMillerPrimalityTest(long long p, int iterations) {
  if (p < 2) return false;
  if (p != 2 && p % 2 == 0) return false;
  long long s = p - 1;
  while (s % 2 == 0) s /= 2;
  for (int i = 0; i < iterations; i++) {
    long long a = rand() % (p - 1) + 1, temp = s;
    long long mod = power(a, temp, p);
    while (temp != p - 1 && mod != 1 && mod != p - 1) {
      mod = mulmod(mod, mod, p);
      temp *= 2;
    }
    if (mod != p - 1 && temp % 2 == 0) {
      return false;
    }
  }
  return true;
}

int main() {
  long long n;
  cin >> n;
  if (rabinMillerPrimalityTest(n, 100))
    cout << "Probable Prime" << endl;
  else
    cout << "Composite" << endl;
}
