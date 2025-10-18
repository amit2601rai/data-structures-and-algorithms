#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

ll solve(int n, vector<ll> &v) {
  if (v[0] != 1) return 1;
  ll high = 1;
  for (int i = 1; i < n; i++) {
    if (v[i] - high < 2) high = high + v[i];
    else break;
  }
  return high + 1;
}

int main() {
  int n;
  cin >> n;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  sort(v.begin(), v.end());

  cout << solve(n, v) << endl;
}