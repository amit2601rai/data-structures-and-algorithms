#include <iostream>
#include <unordered_map>


using namespace std;

typedef long long ll;
constexpr ll MOD = 1e9 + 7;


ll solve() {
  unordered_map<int, int> mp;
  int n;
  cin >> n;
  while (n--) {
    int x;
    cin >> x;
    mp[x]++;
  }
  ll ans = 1;
  for (auto it = mp.begin(); it != mp.end(); it++) {
    ans *= (it->second + 1);
    if (ans >= MOD) ans %= MOD;
  }
  return (ans - 1)%MOD;

}

int main() {
  cout << solve() << endl;
  return 0;
}