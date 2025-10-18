#include <iostream>
#include <vector>

using namespace std;

int phi(int n) {
  int result = n;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) result -= result / i;
    while (n % i == 0) n /= i;
  }
  if (n > 1) result -= result / n;
  return result;
}

int power(int a, int b, int m) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b % 2 == 1) {
      x = (x * y) % m;
    }
    y = (y * y) % m;
    b /= 2;
  }
  return x % m;
}
/* a and m should be co-prime*/
int modInverse(int a, int m) { return power(a, phi(m) - 1, m); }

int CRT(vector<int> remainder, vector<int> mod, int product, int n) {
  int M;
  int sum = 0;
  for (int i = 0; i < mod.size(); i++) {
    M = product / mod[i];
    sum += remainder[i] * M * (modInverse(M, mod[i]));
  }
  return sum % product;
}

int main() {
  int n, r, m, product = 1;
  cin >> n;
  vector<int> remainder(n);
  vector<int> mod(n);
  for (int i = 0; i < n; i++) {
    cin >> r >> m;
    remainder[i] = r;
    mod[i] = m;
    product *= m;
  }
  cout << CRT(remainder, mod, product, n);
  return 0;
}
