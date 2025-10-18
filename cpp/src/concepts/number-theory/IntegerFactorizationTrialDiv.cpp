#include <iostream>

using namespace std;

typedef long long ll;

void factorization(ll n) {
  for (ll i = 2; i * i <= n; i++) {
    ll count = 0;
    while (n % i == 0) {
      n /= i;
      count++;
    }
    if (count > 0) cout << i << " ";
    if (n == 1) break;
  }
  if (n > 1) cout << n << endl;  // Check For Last Prime Factor
}

int main() {
  ll n;
  cin >> n;
  factorization(n);
  return 0;
}
